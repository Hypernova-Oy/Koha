use Modern::Perl;

return {
    bug_number  => "21983",
    description => "Deleted biblio handling on ILL",
    up          => sub {
        my ($args) = @_;
        my ( $dbh, $out ) = @$args{qw(dbh out)};

        unless ( column_exists( 'illrequests', 'deleted_biblio_id' ) ) {
            $dbh->do(
                q{
                ALTER TABLE illrequests
                    ADD COLUMN `deleted_biblio_id` int(11) DEFAULT NULL COMMENT 'Deleted bib linked to request'
                        AFTER `biblio_id`;
            }
            );
            say $out "Added column 'illrequests.deleted_biblio_id'";
        }

        # Move deleted biblio_id to deleted_biblio_id before setting the FK
        $dbh->do(
            q{
            UPDATE    illrequests
            LEFT JOIN biblio
            ON illrequests.biblio_id=biblio.biblionumber
            SET illrequests.biblio_id=NULL,
                illrequests.deleted_biblio_id=illrequests.biblio_id
            WHERE     biblio.biblionumber IS NULL
                  AND illrequests.biblio_id IS NOT NULL
        }
        );

        if ( foreign_key_exists( 'illrequests', 'illrequests_ibfk_1' ) ) {
            $dbh->do(
                q{
                ALTER TABLE illrequests
                DROP FOREIGN KEY illrequests_ibfk_1
            }
            );
        }

        if (   !foreign_key_exists( 'illrequests', 'illrequests_bibfk' )
            || !index_exists( 'illrequests', 'illrequests_bibfk' ) )
        {

            if ( foreign_key_exists( 'illrequests', 'illrequests_bibfk' ) ) {
                $dbh->do(
                    q{
                    ALTER TABLE illrequests
                    DROP FOREIGN KEY illrequests_bibfk
                }
                );
            }
            if ( index_exists( 'illrequests', 'illrequests_bibfk' ) ) {
                $dbh->do(
                    q{
                    ALTER TABLE illrequests
                    DROP INDEX illrequests_bibfk
                }
                );
            }

            $dbh->do(
                q{
                ALTER TABLE illrequests
                    ADD KEY `illrequests_bibfk` (`biblio_id`),
                    ADD CONSTRAINT illrequests_bibfk FOREIGN KEY (`biblio_id`) REFERENCES `biblio` (`biblionumber`) ON DELETE SET NULL ON UPDATE CASCADE;
            }
            );

            say $out "Added foreign key constraint 'illrequests.illrequests_bibfk'";
        }
    },
};
