package Koha::Plugin::2_CalcFineNotEmpty;

use Modern::Perl;

use base qw(Koha::Plugins::Base);

our $VERSION  = "0.0.1";
our $metadata = {
    name            => 'Calc Fine Not Empty Plugin',
    author          => 'Kyle M Hall',
    description     => 'Test plugin',
    date_authored   => '2013-01-14',
    date_updated    => '2013-01-14',
    minimum_version => '3.11',
    maximum_version => undef,
    version         => $VERSION,
    namespace       => 'calc_fine_not_empty',
};

=head1 Methods

=head2 new

=cut

sub new {
    my ( $class, $args ) = @_;
    $args->{'metadata'} = $metadata;
    my $self = $class->SUPER::new($args);
    return $self;
}

=head2 overwrite_calc_fine

=cut

sub overwrite_calc_fine {
    my ( $self, $params ) = @_;

    return [ 1, 2, 3 ];
}

1;
