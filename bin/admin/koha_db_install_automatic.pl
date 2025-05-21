#!/usr/bin/perl

use Modern::Perl;
use Getopt::Long;

use C4::Installer;
use Koha::Caches;
use Koha::SearchEngine::Elasticsearch;

my $help;
my $verbose = 1;
my $marcflavour = 'MARC21';
my $lang = 'en';

GetOptions(
    'h|help'        => \$help,
    'v|verbose'     => \$verbose,
    'marcflavour=s' => \$marcflavour,
    'lang=s'        => \$lang
);

if ( $help ) {
    print <<HELP;
Automatically installs the Koha default database and on subsequent runs, updatedatabase.pl
updatedatabase.pl-runs are logged into the Koha logdir
  -v --verbose  Get update notifications
  --marcflavour MARC21
  --lang en
  -h --help     This nice help
HELP
    exit 0;
}

my $installed = install_default_database($verbose, $marcflavour, $lang);

unless ( $installed ) {
  exit 0;
}

# Flush caches
Koha::Caches->get_instance()->flush_all;
Koha::Caches->get_instance('config')->flush_all;
Koha::Caches->get_instance('sysprefs')->flush_all;

# Initialize ES mappings
Koha::SearchEngine::Elasticsearch->reset_elasticsearch_mappings;

sub install_default_database {
    my ($verbose, $marcflavour, $lang) = @_;
    $marcflavour = 'MARC21' unless $marcflavour;
    my @cc = caller(0);
    require C4::Languages;
    my $installer = C4::Installer->new();

    my ($version, $error);
    eval {
        $version = C4::Context->preference('Version');
    };
    if ($version) {
        print "$cc[3]():> INFO: Koha database exists. Skipping install_default_database()\n" if $verbose;
        return 0;
    }
    $error = $installer->load_db_schema();
    die "$cc[3]():> FATAL: $error" if $error;

    my $all_languages = C4::Languages::getAllLanguages();
    $lang //= 'en';

    my @installList;
    my $frameworkList  = $installer->marc_framework_sql_list($lang, $marcflavour);
    foreach my $list (@$frameworkList) {
        foreach my $fwk (@{$list->{frameworks}}) {
            push(@installList, $fwk->{fwkfile});
        }
    }
    my $sampleDataList = $installer->sample_data_sql_list($lang);
    foreach my $list (@$sampleDataList) {
        foreach my $fwk (@{$list->{frameworks}}) {
            push(@installList, $fwk->{fwkfile});
        }
    }

    #fill $list with list of sql files
    my ($fwk_language, $error_list) = $installer->load_sql_in_order($lang, $all_languages, @installList);
    $installer->set_version_syspref();
    $installer->set_marcflavour_syspref($marcflavour);

   return 1;
}
