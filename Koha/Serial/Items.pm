package Koha::Serial::Items;

# Copyright ByWater Solutions 2016
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

use Koha::Database;

use Koha::Serial::Item;

use base qw(Koha::Objects);

=head1 NAME

Koha::Serial::Items - Koha Serial Items Object class

=head1 API

=head2 Class Methods

=cut

=head3 type

=cut

sub _type {
    return 'Serialitem';
}

=head2 object_class

Missing POD for object_class.

=cut

sub object_class {
    return 'Koha::Serial::Item';
}

=head1 AUTHOR

Kyle M Hall <kyle@bywatersolutions.com>

=cut

1;
