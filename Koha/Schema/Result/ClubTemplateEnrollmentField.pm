use utf8;
package Koha::Schema::Result::ClubTemplateEnrollmentField;

# Created by DBIx::Class::Schema::Loader
# DO NOT MODIFY THE FIRST PART OF THIS FILE

=head1 NAME

Koha::Schema::Result::ClubTemplateEnrollmentField

=cut

use strict;
use warnings;

use base 'DBIx::Class::Core';

=head1 TABLE: C<club_template_enrollment_fields>

=cut

__PACKAGE__->table("club_template_enrollment_fields");

=head1 ACCESSORS

=head2 id

  data_type: 'integer'
  is_auto_increment: 1
  is_nullable: 0

=head2 club_template_id

  data_type: 'integer'
  is_foreign_key: 1
  is_nullable: 0

=head2 name

  data_type: 'text'
  is_nullable: 0

=head2 description

  data_type: 'mediumtext'
  is_nullable: 1

=head2 authorised_value_category

  data_type: 'varchar'
  is_nullable: 1
  size: 32

=cut

__PACKAGE__->add_columns(
  "id",
  { data_type => "integer", is_auto_increment => 1, is_nullable => 0 },
  "club_template_id",
  { data_type => "integer", is_foreign_key => 1, is_nullable => 0 },
  "name",
  { data_type => "text", is_nullable => 0 },
  "description",
  { data_type => "mediumtext", is_nullable => 1 },
  "authorised_value_category",
  { data_type => "varchar", is_nullable => 1, size => 32 },
);

=head1 PRIMARY KEY

=over 4

=item * L</id>

=back

=cut

__PACKAGE__->set_primary_key("id");

=head1 RELATIONS

=head2 club_enrollment_fields

Type: has_many

Related object: L<Koha::Schema::Result::ClubEnrollmentField>

=cut

__PACKAGE__->has_many(
  "club_enrollment_fields",
  "Koha::Schema::Result::ClubEnrollmentField",
  { "foreign.club_template_enrollment_field_id" => "self.id" },
  { cascade_copy => 0, cascade_delete => 0 },
);

=head2 club_template

Type: belongs_to

Related object: L<Koha::Schema::Result::ClubTemplate>

=cut

__PACKAGE__->belongs_to(
  "club_template",
  "Koha::Schema::Result::ClubTemplate",
  { id => "club_template_id" },
  { is_deferrable => 1, on_delete => "CASCADE", on_update => "CASCADE" },
);


# Created by DBIx::Class::Schema::Loader v0.07049 @ 2022-01-19 06:49:06
# DO NOT MODIFY THIS OR ANYTHING ABOVE! md5sum:qFRwC+QtitmYq2n2TdXOxw

=head2 koha_object_class

Missing POD for koha_object_class.

=cut

sub koha_object_class {
    'Koha::Club::Template::EnrollmentField';
}

=head2 koha_objects_class

Missing POD for koha_objects_class.

=cut

sub koha_objects_class {
    'Koha::Club::Template::EnrollmentFields';
}

1;
