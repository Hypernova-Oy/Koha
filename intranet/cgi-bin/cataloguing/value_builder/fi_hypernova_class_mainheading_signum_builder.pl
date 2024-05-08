#!/usr/bin/perl

# Converted to new plugin style (Bug 13437)

# Copyright 2010 BibLibre SARL
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
        function Blur$params->{id}() {
                var code = document.getElementById('$params->{id}');

                //Prevent overwriting manual changes
                if (code && code.value !== \"\") {
                    return 1;
                }

                var biblionumber = \$('form#f > input[name=biblionumber]').val();
                var url = '../cataloguing/plugin_launcher.pl?plugin_name=fi_hypernova_class_mainheading_signum_builder.pl&code=' + code.value + '&biblionumber=' + biblionumber;
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

# One can run CLI tests against this value_builder using this entrypoint.
sub builder {
    my ($code, $biblionumber) = @_;
    my $biblio = Koha::Biblios->find($biblionumber);
    my $record = $biblio->metadata->record;

    return class($record) . " " . public_signum($record);
}

#Copypaste from
# Koha/Plugin/Fi/KohaSuomi/LabelPrinter/DataSource.pm
#This should be a part of the core MARC::Biblio functionality, so we wouldn't have to copypaste the same code all over Koha.
sub public_signum {
    my $record = shift;

    #Get the proper SIGNUM (important) Use one of the Main Entries or the Title Statement
    my $leader = $record->leader(); #If this is a video, we calculate the signum differently, 06 = 'g'
    my $signumSource; #One of fields 100, 110, 111, 130, or 245 if 1XX is missing
    my $nonFillingCharacters = 0;

    if ($signumSource = $record->subfield('100', 'a')) {

    }
    elsif ($signumSource = $record->subfield('110', 'a')) {

    }
    elsif ($signumSource = $record->subfield('111', 'a')) {

    }
    elsif (substr($leader,6,1) eq 'g' && ($signumSource = $record->subfield('245', 'a'))) {
        $nonFillingCharacters = $record->field('245')->indicator(2);
    }
    elsif ($signumSource = $record->subfield('130', 'a')) {
        $nonFillingCharacters = $record->field('130')->indicator(1);
        $nonFillingCharacters = 0 if (not(defined($nonFillingCharacters)) || $nonFillingCharacters eq ' ');
    }
    elsif ($signumSource = $record->subfield('245', 'a')) {
        $nonFillingCharacters = $record->field('245')->indicator(2);
    }
    if ($signumSource) {
        return uc(substr($signumSource, $nonFillingCharacters, 3));
    }

    return undef;
}

sub class {
    my $record = shift;

    # We want to gather all classification numbers, but 080$x is a special butterfly, having extras for $a.
    # Since no other classification number fields have subfield $x, we can make "assumptions".
    no warnings 'uninitialized';
    my @classes = map {
        $_->subfield('a').$_->subfield('x');
    } ($record->field('08.', '09.'));
    return join(':', @classes);
}

my $launcher = sub {
    my ( $params ) = @_;
    my $input = $params->{cgi};
    my $code = $input->param('code');
    my $biblionumber = $input->param('biblionumber');

    my ($template, $loggedinuser, $cookie) = get_template_and_user({
        template_name   => "cataloguing/value_builder/ajax.tt",
        query           => $input,
        type            => "intranet",
        authnotrequired => 0,
        flagsrequired   => {editcatalogue => '*'},
        debug           => 1,
    });

    $template->param( return => builder($input->param('code'), $input->param('biblionumber')) );

    return output_html_with_http_headers $input, $cookie, $template->output;
};

unless (caller()) {
    print   builder('', $_)  ."\n" for @ARGV;
    exit;
}

return { builder => $builder, launcher => $launcher };
