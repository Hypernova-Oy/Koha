package Koha::AuthorisedValueCategories;

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

use Koha::Database;
use Koha::Exceptions;

use Koha::AuthorisedValueCategory;

use base qw(Koha::Objects);

=head1 NAME

Koha::AuthorisedValueCategories - Koha AuthorisedValueCategory Object set class

=head1 API

=head2 Class Methods

=cut

=head3 delete

Overridden delete method to prevent system default deletions

=cut

sub delete {
    my ($self) = @_;

    my @set = $self->as_list;
    for my $type (@set) {
        if ( $type->is_system ) {
            Koha::Exceptions::CannotDeleteDefault->throw;
        }
    }

    return $self->SUPER::delete;
}

=head3 type

=cut

sub _type {
    return 'AuthorisedValueCategory';
}

=head2 object_class

Missing POD for object_class.

=cut

sub object_class {
    return 'Koha::AuthorisedValueCategory';
}

1;
