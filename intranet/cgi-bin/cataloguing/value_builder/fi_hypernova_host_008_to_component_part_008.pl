#!/usr/bin/perl

# Converted to new plugin style (Bug 13437)

# Copyright 2010 BibLibre SARL
# Copyright 2022 Hypernova Oy
#
# This file is part of Koha.
#
# Koha is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Koha is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Koha; if not, see <http://www.gnu.org/licenses>.

use Modern::Perl;
use CGI qw ( -utf8 );

use C4::Auth qw( get_template_and_user );
use C4::Biblio;
use C4::Context;
use C4::Output qw( output_html_with_http_headers );

=head1 DESCRIPTION
Is used for callnumber computation.
=cut

my $builder = sub {
    my ( $params ) = @_;
    my $res="
    <script type='text/javascript'>
        function Focus$params->{id}() {
            return Click$params->{id}();
        }
        function Click$params->{id}() {
                var code = document.getElementById('$params->{id}');
                var url = new URL(window.location);
                var parentbiblionumber = url.searchParams.get('parentbiblionumber');
                var host_cn = \$(\"input[id^='tag_773_subfield_w']\").val();
                var url = '../cataloguing/plugin_launcher.pl?plugin_name=fi_hypernova_host_008_to_component_part_008.pl&code=' + code.value + '&host_cn=' + host_cn + '&parentbiblionumber=' + parentbiblionumber;
                var req = \$.get(url);
                req.done(function(resp){
                    code.value = resp;
                    return 1;
                });
                return 1;
        }
    </script>
    ";
    return $res;
};

my $launcher = sub {
    my ( $params ) = @_;
    my $input = $params->{cgi};
    my $code = $input->param('code');
    my $host_cn = $input->param('host_cn');
    my $parentbiblionumber = $input->param('parentbiblionumber');
    if ( $parentbiblionumber eq 'null' ) {
        $parentbiblionumber = undef;
    }

    my ($template, $loggedinuser, $cookie) = get_template_and_user({
        template_name   => "cataloguing/value_builder/ajax.tt",
        query           => $input,
        type            => "intranet",
        authnotrequired => 0,
        flagsrequired   => {editcatalogue => '*'},
        debug           => 1,
    });

    return if !$host_cn and !$parentbiblionumber;

    my $record;
    if ( $parentbiblionumber ) {
        $record = Koha::Biblios->find($parentbiblionumber);
        $record = $record->metadata->record;
    } else {
        my $searcher = Koha::SearchEngine::Search->new(
            {
                index => $Koha::SearchEngine::BIBLIOS_INDEX
            }
        );
        my ( $error, $results, $hits ) =
            $searcher->simple_search_compat( 'control-number:"'.$host_cn.'"', 0, 1, [ 'biblioserver' ] );
        die $error if $error;

        for my $result_record ( @{$results} ) {
            $record = $result_record;
        }
    }

    return unless $record;

    my $parent_f008 = $record->field('008')->data;

    $template->param(
        tagfield => '008',
        return => $parent_f008
    );
    output_html_with_http_headers $input, $cookie, $template->output;
};

return { builder => $builder, launcher => $launcher };
