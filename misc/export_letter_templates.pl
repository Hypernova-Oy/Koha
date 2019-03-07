#!/usr/bin/perl

# This file is part of Koha.
#
# Copyright 2019 Hypernova Oy
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
binmode(STDOUT, ":utf8");

use Getopt::Long;
use Pod::Usage;

use Koha::LetterTemplates;

my ( $output_format, $letter_lang, $letter_code, $help );
$output_format = 'plain';
$letter_lang   = 'default';
GetOptions(
    'f|format=s'                => \$output_format,
    'l|lang=s'                  => \$letter_lang,
    'c|code=s'                  => \$letter_code,
    'h|help|?'                  => \$help
) || pod2usage(1);

if ($help) {
    pod2usage(1);
}

my $letters;
my $search_params;

$search_params->{'lang'} = $letter_lang;
$search_params->{'code'} = $letter_code if defined $letter_code;

$letters = Koha::LetterTemplates->search( $search_params )->as_list;
if ($output_format eq 'plain') {
    foreach my $letter_template (@$letters) {
        print $letter_template->code .
              ' (' . $letter_template->message_transport_type . "):\n" .
              $letter_template->title . ',' .
              $letter_template->content. "\n" .
              "\n\n";
    }
}
elsif ($output_format eq 'textile') {
    print "{{toc}}\n\n";
    print "h2. Letter Templates\n\n";
    foreach my $letter_template (@$letters) {
        print "h3. " . $letter_template->code .
              ' (' . $letter_template->message_transport_type . ')' ."\n\n";
        print '*' . $letter_template->title . "*\n";
        print "<pre>";
        print $letter_template->content. "\n";
        print "</pre>\n\n";
    }
}

exit;

=head1 NAME

export letter templates - This script exports letter templates (letter database table)

=head1 SYNOPSIS

export_letter_templates.pl [-h|--help] [-f|--format=FORMAT] [-l|--language=LANGUAGE] [-c|--code=CODE] > letter_templates.txt

=head1 OPTIONS

=over

=item B<-h|--help>

Print a brief help message.

=item B<--format>

 --format=FORMAT        FORMAT is 'plain' (default) or 'textile' (e.g. for Redmine).

=item B<--lang>

 --lang=LANGUAGE        LANGUAGE should be language code of the letter. Default
                        value is 'default'. Example: fi-FI

=item B<--code>

 --code=CODE            CODE is letter code, e.g. PREDUEDGST. Leave empty to
                        export all letters.

=back

=head1 AUTHOR

Lari Taskula

=head1 COPYRIGHT

Hypernova Oy

=head1 LICENSE

This file is part of Koha.

Koha is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later version.

You should have received a copy of the GNU General Public License along
with Koha; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

=cut
