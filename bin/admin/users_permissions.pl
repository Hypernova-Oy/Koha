#!/usr/bin/perl

# Copyright (C) 2025 Hypernova Oy
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

=head HN#2364 - Users and permissions management script users_permissions.pl
=tags Critical Infrastructure
=cut

use Modern::Perl;
use utf8;
use strict;
use warnings;
use open qw(:std :encoding(UTF-8));

use Getopt::Long qw(:config no_ignore_case);
use YAML::XS;
use Try::Tiny;

use Koha::Script; # Include this first so the env is set properly
use C4::Context;
use Koha::Logger;
use Koha::Patrons;
use Koha::Patron::Categories;

our $l = Koha::Logger->get();

our $verbose = 0;
our (@create_user, @create_category, @create_library, @delete_user, @list_user_perms, @grant_perms, @revoke_perms);
our ($help, $list_categories, $list_libraries, $list_perms, $test);

GetOptions(
# Actions
  'create-library=s'    => \@create_library,
  'create-user=s'       => \@create_user,
  'create-category=s'   => \@create_category,
  'delete-user=s'       => \@delete_user,
  'list-categories'     => \$list_categories,
  'list-libraries'      => \$list_libraries,
  'list-perms'          => \$list_perms,
  'list-user-perms=s'   => \@list_user_perms,
  'grant-perms=s'       => \@grant_perms,
  'revoke-perms=s'      => \@revoke_perms,
  'test'                => \$test,
# Others
  'v|verbose+'          => \$verbose,
  'h|help'              => \$help,
) or $l->logdie("Error in command line arguments");

sub help {
  print <<HELP;
$0 - Manage Koha permissions for users.
Usage: $0 [actions...] [options...]
Actions:
  --create-category   Creates or updates a borrower category
                      YAML (Repeatable): YAML-string of koha.categories database column names
                      Mandatory: categorycode String: koha.categories.categorycode

  --create-library    Creates or updates an existing library/branch
                      YAML (Repeatable): YAML-string of koha.branches database column names and values used for the creation or update of the library.
                      Mandatory: branchcode String: koha.branches.branchcode

  --create-user       Creates or updates an existing user
                      YAML (Repeatable): YAML-string of koha.borrowers database column names and values used for the creation or update of the borrower.
                      Mandatory:
                            cardnumber String: koha.borrowers.cardnumber
                        or: userid     String: koha.borrowers.userid
                      Special handling:
                        password       String: koha.borrowers.password, value can be hashed or plaintext
                        tfa_secret     String: 26-characters. Two-factor authentication secret.

  --delete-user       Deletes the given user
                      YAML (Repeatable): YAML-string of koha.borrowers database column names and values used for the deletion of the borrower.
                      Mandatory:
                            cardnumber String: koha.borrowers.cardnumber
                        or: userid     String: koha.borrowers.userid

  --list-categories   List all current Koha borrower categories

  --list-libraries    List all libraries/branches

  --list-perms        List all current Koha permission modules and subpermissions

  --list-user-perms   List permissions for a specific user
                      YAML (Repeatable): YAML-string of koha.borrowers database column userid or cardnumber.

  --grant-perms       Grant permissions and subpermissions to a user
                      YAML (Repeatable): YAML-string of koha.borrowers.userid or .cardnumber and koha.permissions* .module and .subpermission

  --revoke-perms      Revoke permissions
                      YAML (Repeatable): YAML-string of koha.borrowers.userid or .cardnumber and koha.permissions* .module and .subpermission

Options:
    -v --verbose        Repeatable: Increase log level for each repetition.
    -h --help           This help

Examples:
  # Create a new user
  $0 --create-user={userid: 'mmeikä', password: 'password123', surname: 'Meikäläinen', firstname: 'Matti', email: 'mattimeikalainen\@example.com', categorycode: 'STAFF', branchcode: CPL'}

  # Grant circulation permissions
  $0 --grant-perms="userid: mmeikä\
  module: circulate\
  subpermission: ALL"

  # Grant specific permission
  $0 --grant-perms={userid: 'mmeikä', module: 'catalogue', subpermission: 'staff_login'}

  # List all permissions
  $0 --list-perms

  # Delete a user
  $0 --delete-user="userid: mmeikä"

  $0 --create-library="{branchname: 'Central Library', branchaddress1: '123 Main St', \
                branchcode 'CPL', branchcity: 'Springfield', branchzip: '12345', \
                branchphone: '555-1234', branchemail: 'library\@example.com'}"

HELP
    exit;
}

if ($help || !(@create_category || @create_library || @create_user || @delete_user|| $list_categories || $list_libraries || $list_perms || @list_user_perms || @grant_perms || @revoke_perms || $test)) {
  help();
}

if ($verbose) {
  unless ($l->{logger}->{appender_names} && ref($l->{logger}->{appender_names}) eq 'ARRAY' && @{$l->{logger}->{appender_names}} > 0) {
    #$l->logdie("No Log::Log4perl appenders defined! Add a 'log4perl.logger.".C4::Context::interface().".".__PACKAGE__."' to log4perl.conf");
  }
  $l->dec_level($verbose);
}

# Main execution
try {
  if ($list_perms) {
    list_permissions();
  }
  if ($list_categories) {
    list_categories();
  }
  if ($list_libraries) {
    list_libraries();
  }
  if (@create_category) {
    create_or_update_category($_) for @create_category;
  }
  if (@create_library) {
    create_or_update_library($_) for @create_library;
  }
  if (@delete_user) {
    delete_user_action($_) for @delete_user;
  }
  if (@create_user) {
    create_or_update_user($_) for @create_user;
  }
  if (@grant_perms) {
    grant_permissions($_) for @grant_perms;
  }
  if (@revoke_perms) {
    revoke_permissions($_) for @revoke_perms;
  }
  if (@list_user_perms) {
    list_user_permissions($_) for @list_user_perms;
  }
  if ($test) {
    run_tests();
  }
} catch {
  $l->logdie("Error: $_");
};

# Subroutines

sub create_or_update_category {
  my ($category_yaml) = @_;
  my $category_data = parse_yaml($category_yaml);
  my $categorycode = $category_data->{categorycode};
  $l->logdie("--categorycode must be specified in the given YAML='$category_yaml'") unless $categorycode;

  my $category = Koha::Patron::Categories->find({ categorycode => $categorycode });
  if ($category) {
    # Update existing category
    $l->info("Updating existing patron category categorycode='$categorycode'");

    $category->set($category_data)->store;

    $l->info("Category updated successfully categorycode='$categorycode'");
  } else {
    # Create new category
    $l->info("Creating a new patron category");

    # Set required defaults if not provided
    $category_data->{description} ||= "$categorycode - Autogenerated by $0";
    $category_data->{category_type} ||= 'A';  # Default to Adult

    $category = Koha::Patron::Category->new($category_data)->store;

    $l->info("Category created successfully categorycode='$categorycode'");
  }
}

sub create_or_update_library {
  my ($library_yaml) = @_;
  my $library_data = parse_yaml($library_yaml);
  my $branchcode = $library_data->{branchcode};
  $l->logdie("--branchcode must be specified in the given YAML='$library_yaml'") unless $branchcode;

  my $library = Koha::Libraries->find({ branchcode => $branchcode });

  if ($library) {
    # Update existing library
    $l->info("Updating existing library branchcode='$branchcode'");

    $library->set($library_data)->store;

    $l->info("Library updated successfully branchcode='$branchcode'");
  } else {
    # Create new library
    $l->info("Creating new library");

    # Set required defaults if not provided
    $library_data->{branchname} ||= "$branchcode - Autogenerated by $0";

    $library = Koha::Library->new($library_data)->store;

    $l->info("Library created successfully branchcode='$branchcode'");
  }
}

sub create_or_update_user {
  my ($borrower_yaml) = @_;
  my $patron_data = parse_yaml($borrower_yaml);
  my $cardnumber = $patron_data->{cardnumber};
  my $userid = $patron_data->{userid};
  my $password = $patron_data->{password};
  delete $patron_data->{password};
  my $tfa_secret = $patron_data->{tfa_secret};
  delete $patron_data->{tfa_secret};

  $l->logdie("Either --cardnumber or --userid must be specified in the given YAML='$borrower_yaml'")
    unless $cardnumber || $userid;

  my $patron = find_patron($cardnumber, $userid);

  if ($patron) {
    # Update existing patron
    $l->info("Updating existing patron borrowernumber='".$patron->borrowernumber."'");

    for my $attribute (sort keys %$patron_data) {
      if (defined($patron->$attribute()) && $patron->$attribute() ne $patron_data->{$attribute}) {
        $l->info("[CHANGE] User '$attribute'='".$patron->$attribute()."'=>'".$patron_data->{$attribute}."'");
        $patron->$attribute($patron_data->{$attribute});
      }
    }
    $patron->store() if $patron->is_changed();

    handle_passwords($password, $tfa_secret, $patron_data, $patron);

    my $patron_modification_action_logs = Koha::ActionLogs->search({ user => $patron->borrowernumber, object => $patron->borrowernumber, timestamp => { '>' => \'NOW() - INTERVAL 10 SECOND' } });
    if ($patron_modification_action_logs->count()) {
      $l->debug("Deleting '".$patron_modification_action_logs->count()."' Patron modification action_log entries");
      $patron_modification_action_logs->delete;
    }

    $l->info("User updated successfully borrowernumber='".$patron->borrowernumber."'");
  } else {
    # Create new patron
    $l->info("Creating new patron");

    # Set required defaults if not provided
    $patron_data->{categorycode} ||= get_default_category();
    $patron_data->{branchcode} ||= get_default_branch();
    $patron_data->{surname} ||= 'Autocreated by users_permissions.pl';

    $patron = Koha::Patron->new($patron_data)->store;

    handle_passwords($password, $tfa_secret, $patron_data, $patron);

    $l->info("[CHANGE] User created successfully borrowernumber='".$patron->borrowernumber."'");
  }
}

sub delete_user_action {
  my ($borrower_yaml) = @_;
  my $patron_data = parse_yaml($borrower_yaml);
  my $cardnumber = $patron_data->{cardnumber};
  my $userid = $patron_data->{userid};

  $l->logdie("Either --cardnumber or --userid must be specified in the given YAML='$borrower_yaml'")
    unless $cardnumber || $userid;

  my $patron;
  if ($cardnumber) {
    $patron = Koha::Patrons->find({ cardnumber => $cardnumber });
  }
  if (!$patron && $userid) {
    $patron = Koha::Patrons->find({ userid => $userid });
  }

  $l->logdie("User ".($userid ? "userid='".$userid."'" : "cardnumber='".$cardnumber)."' not found.") unless $patron;

  $patron->delete;

  $l->info("User borrowernumber='".$patron->borrowernumber."' deleted successfully.");
}

sub list_categories {
  $l->info("Listing all patron categories");
  print YAML::XS::Dump(_list_categories());
}

sub _list_categories {
  my @categories = Koha::Patron::Categories->search(
    {},
    { order_by => 'categorycode' }
  )->as_list;

  @categories = map { $_->unblessed } @categories;
  return \@categories;
}

sub list_libraries {
  $l->info("Listing all libraries");
  print YAML::XS::Dump(_list_libraries());
}

sub _list_libraries {
  my @libraries = Koha::Libraries->search(
    {}, 
    { order_by => 'branchcode' }
  )->as_list;

  @libraries = map { $_->unblessed } @libraries;
  return \@libraries;
}

sub list_permissions {
  $l->info("Listing all permissions");

  my ($userflags, $perms) = _list_permissions();

  my %modules;
  for my $row (@$userflags) {
    $modules{$row->{bit}} = {
      flag => $row->{flag},
      desc => $row->{flagdesc}
    };
  }

  print "\nKoha Permission Modules and Subpermissions:\n";
  print "=" x 80 . "\n\n";

  my $current_module = '';
  for my $row (@$perms) {
    my $module_bit = $row->{module_bit};

    if ($current_module ne $module_bit) {
      $current_module = $module_bit;
      my $mod_info = $modules{$module_bit};
      if ($mod_info) {
        print "\nModule: $mod_info->{flag} (bit $module_bit)\n";
        print "Description: ".($mod_info->{flagdesc} || '')."\n";
        print "-" x 80 . "\n";
      }
    }

    print "  - $row->{code}: $row->{description}\n";
  }

  print "\n";
}

sub _list_permissions {
  my $dbh = C4::Context->dbh;
  my $sth_permissions = $dbh->prepare("SELECT module_bit, code, description FROM permissions ORDER BY module_bit, code");
  $sth_permissions->execute();
  my $permissions = $sth_permissions->fetchall_arrayref({});

  # Get module names
  my $sth_userflags = $dbh->prepare("SELECT bit, flag, flagdesc FROM userflags ORDER BY bit");
  $sth_userflags->execute();
  my $userflags = $sth_userflags->fetchall_arrayref({});

  return ($userflags, $permissions);
}

sub list_user_permissions {
  my ($borrower_yaml) = @_;
  my $patron_data = parse_yaml($borrower_yaml);
  my $cardnumber = $patron_data->{cardnumber};
  my $userid = $patron_data->{userid};

  $l->logdie("Either --cardnumber or --userid must be specified in the given YAML='$borrower_yaml'") 
    unless $cardnumber || $userid;

  my $patron = find_patron($cardnumber, $userid);
  $l->logdie("User not found") unless $patron;

  my $perms = _list_user_permissions($patron);
  $perms->{borrowernumber} = $patron->borrowernumber;

  print YAML::XS::Dump($perms);
}

sub _list_user_permissions {
  my ($patron) = @_;
  my $flags = $patron->flags;

  my $dbh = C4::Context->dbh;
  my $sth = $dbh->prepare(
    "SELECT up.module_bit, up.code, p.description, uf.flag, uf.flagdesc
      FROM user_permissions up
      LEFT JOIN permissions p ON up.module_bit = p.module_bit AND up.code = p.code
      LEFT JOIN userflags uf ON up.module_bit = uf.bit
      WHERE up.borrowernumber = ?
      ORDER BY up.module_bit, up.code"
  );
  $sth->execute($patron->borrowernumber);
  my $p = $sth->fetchall_arrayref({});
  my $sth_userflags = $dbh->prepare("SELECT bit, flag, flagdesc FROM userflags ORDER BY bit");
  $sth_userflags->execute();
  my $userflags = $sth_userflags->fetchall_arrayref({});

  my %p;
  no strict; no warnings;
  for my $p (@$p) {
    $p{$p->{flag}}->{bit} = $p->{module_bit};
    $p{$p->{flag}}->{flagdesc} = $p->{flagdesc};
    $p{$p->{flag}}->{permissions}->{$p->{code}} = $p->{description};
  }
  for my $f (@$userflags) {
    $p{$f->{flag}}->{permissions}->{ALL} = 1 if ($flags & (1 << $f->{bit}));
  }
  return \%p;
}

sub grant_permissions {
  my ($permission_yaml) = @_;
  my $permission_data = parse_yaml($permission_yaml);
  my $cardnumber = $permission_data->{cardnumber};
  my $userid = $permission_data->{userid};
  my $module = $permission_data->{module};
  my $subperm = $permission_data->{subpermission};
  $l->logdie("Either --cardnumber or --userid must be specified in the given YAML='$permission_yaml'") unless ($cardnumber || $userid);
  $l->logdie("A --module and a --subpermission must be specified in the given YAML='$permission_yaml'") unless ($module && $subperm);

  my $patron = find_patron($cardnumber, $userid);
  $l->logdie("User not found") unless $patron;

  $l->info("Granting permissions to: " . $patron->userid);

  my $dbh = C4::Context->dbh;

  # Get module_bit for the module
  my $module_bit = get_module_bit($module);
  $l->logdie("Unknown permission module: $module") unless(defined($module_bit));

  if ($subperm =~ /^(?:1|ALL)$/i) {
    $l->debug("Granting module superuser: $module");
    my $flags = ($patron->flags || 0) | (1 << $module_bit);
    $patron->flags($flags)->store();
  } else {
    $l->debug("Granting permission: $module -> $subperm");

    my $perm_exists = $dbh->selectrow_array(
      "SELECT 1 FROM permissions WHERE module_bit = ? AND code = ?",
      undef, $module_bit, $subperm
    );
    $l->logdie("Unknown subpermission: $subperm in module $module") unless $perm_exists;

    $dbh->do(
      "INSERT INTO user_permissions (borrowernumber, module_bit, code) 
        VALUES (?, ?, ?)
        ON DUPLICATE KEY UPDATE borrowernumber=borrowernumber",
      undef, $patron->borrowernumber, $module_bit, $subperm
    );
  }

  $l->info("Granted: $module".($subperm ne '1' ? " -> $subperm" : " (all)"));
}

sub revoke_permissions {
  my ($permission_yaml) = @_;
  my $permission_data = parse_yaml($permission_yaml);
  my $cardnumber = $permission_data->{cardnumber};
  my $userid = $permission_data->{userid};
  my $module = $permission_data->{module};
  my $subperm = $permission_data->{subpermission};
  $l->logdie("Either --cardnumber or --userid must be specified in the given YAML='$permission_yaml'") unless ($cardnumber || $userid);
  $l->logdie("A --module and a --subpermission must be specified in the given YAML='$permission_yaml'") unless ($module && $subperm);

  my $patron = find_patron($cardnumber, $userid);
  $l->logdie("User not found") unless $patron;

  $l->info("Revoking permissions from: " . $patron->userid);

  my $dbh = C4::Context->dbh;

  my $module_bit = get_module_bit($module);
  $l->logdie("Unknown permission module: $module\n") unless(defined($module_bit));

  if ($subperm eq '1') {
    # Revoke all permissions in module
    $l->debug("Revoking all permissions in module: $module");
    $dbh->do(
      "DELETE FROM user_permissions WHERE borrowernumber = ? AND module_bit = ?",
      undef, $patron->borrowernumber, $module_bit
    );
    print "Revoked: $module (all)\n";
  } else {
    # Revoke specific subpermission
    $l->debug("Revoking permission: $module -> $subperm");
    $dbh->do(
      "DELETE FROM user_permissions WHERE borrowernumber = ? AND module_bit = ? AND code = ?",
      undef, $patron->borrowernumber, $module_bit, $subperm
    );
    print "Revoked: $module -> $subperm\n";
  }
}

###              ###
# Helper functions #
###              ###

sub find_patron {
  my ($cardnumber, $userid) = @_;
  my $patron;
  if ($cardnumber) {
    $patron = Koha::Patrons->find({cardnumber => $cardnumber});
    $l->debug("Found patron by cardnumber: $cardnumber") if $patron;
  }
  if (!$patron && $userid) {
    $patron = Koha::Patrons->find({userid => $userid});
    $l->debug("Found patron by userid: $userid") if $patron;
  }

  return $patron;
}

sub get_module_bit {
  my ($module) = @_;

  my $dbh = C4::Context->dbh;
  my $bit = $dbh->selectrow_array(
    "SELECT bit FROM userflags WHERE flag = ?",
    undef, $module
  );

  return $bit;
}

sub get_default_category {
  return $create_category[0]->{categorycode} if @create_category;
  my $category = Koha::Patron::Categories->search({ category_type => 'S' })->next;
  $category = $category ? $category->categorycode : $l->logdie("Unable to get the default category!");
  $l->debug("Default category '$category'");
  return $category;
}

sub get_default_branch {
  return $create_library[0]->{branchcode} if @create_library;
  my $dbh = C4::Context->dbh;
  my $branch = $dbh->selectrow_array("SELECT branchcode FROM branches LIMIT 1");
  $l->logdie("Unable to get the default branch!") unless $branch;
  $l->debug("Default branch '$branch'");
  return $branch;
}

sub handle_passwords {
  my ($password, $tfa_secret, $patron_data, $patron) = @_;
  my $password_hash;

  if ($password) {
    if ($patron->login_attempts) {
      $l->debug("Login attempts '".$patron->login_attempts."' reset");
      $patron->login_attempts(0);
    }

    # Check if password is already hashed (bcrypt starts with $2)
    if ($password =~ /^\$2[aby]\$/) {
      $l->debug("Password appears to be pre-hashed");
      $password_hash = $password;
    } else {
      $l->debug("Hashing plaintext password");
      $password_hash = Koha::AuthUtils::hash_password($password);
    }

    my $existing_password = $patron->password();
    if ($existing_password && $existing_password eq $password_hash) {
      $l->debug("Password not changed");
    }
    else {
      $patron->password($password_hash);
      Koha::Object::store($patron);
      $l->info("[CHANGE] Password");
    }
  }
  else {
    $l->debug("No password given");
  }

  if ($tfa_secret) {
    my $decoded_secret = $patron->decoded_secret();
    if ($decoded_secret && $decoded_secret eq $tfa_secret) {
      $l->debug("TFA Secret not changed");
    }
    else {
      $patron->encode_secret($tfa_secret);
      $patron->auth_method('two-factor') if $patron->auth_method ne 'two-factor';
      Koha::Object::store($patron);
      $l->info("[CHANGE] TFA Secret");
    }
  }
}

sub parse_yaml {
  my ($yaml_string) = @_;
  my $object;

  if ($yaml_string) {
    try {
      $object = YAML::XS::Load($yaml_string);
      $l->debug("Parsed YAML parameters");
    } catch {
      $l->logdie("Failed to parse YAML parameters: $yaml_string\n$_");
    };
  }
  return $object;
}

# Even with use utf8, we need to encode the new ARGV to prevent encoding problems when re-executing the script.
sub encode_ARGV {
  for (my $i=0 ; $i<@ARGV ; $i++) {
    $ARGV[$i] = Encode::encode_utf8($ARGV[$i]);
  }
}

#############
# Run tests #
#############
sub run_tests {
  require Test::More;
  Test::More->import();
  my $schema = Koha::Database->schema;
  $schema->storage->txn_begin;

  eval {
    Test::More::plan(tests => 9);
    my ($cardnumber, $userid, $password, $tfa_secret, $categorycode, $branchcode) = ('12345678','87654321ÄÖ','salakamalaÄÖ','TFASECRET_TFASECRET_TFASEC','SIP2','SIPLIB');

    subtest("--list-perms" => sub {
      Test::More::plan(tests => 4);
      @ARGV=('--list-perms','-v','-v'); encode_ARGV();
      package main::ListPerms { do $0; }

      my ($userflags, $permissions) = _list_permissions();
      ok($userflags, 'userflags');
      cmp_ok(scalar(@$userflags), '>', 8, 'userflags found');
      ok($permissions, 'permissions');
      cmp_ok(scalar(@$permissions), '>', 20, 'permissions found');
    });
    subtest("--list-categories" => sub {
      Test::More::plan(tests => 3);
      @ARGV=('--list-categories','-v','-v'); encode_ARGV();
      package main::ListCategories { do $0; }

      my ($cats) = _list_categories();
      ok($cats, 'categories');
      cmp_ok(scalar(@$cats), '>', 8, 'categories found');
      ok($cats->[0]->{categorycode}, 'category 0 looks like a category');
    });
    subtest("--create-category" => sub {
      Test::More::plan(tests => 4);
      @ARGV=("--create-category={categorycode: $categorycode, description: Ö SIP2 Laite, enrolmentperiod: 60}",'-v','-v'); encode_ARGV();
      package main::CreateCategory { do $0; }

      my $c = (grep {$_->{categorycode} eq $categorycode} @{_list_categories()})[0];
      ok($c, "find category $categorycode");
      is($c->{description}, "Ö SIP2 Laite", 'description');
      is($c->{category_type}, 'A', 'category_type');
      is($c->{enrolmentperiod}, 60, 'enrolmentperiod');
    });
    subtest("--list-libraries" => sub {
      Test::More::plan(tests => 3);
      @ARGV=('--list-libraries','-v','-v'); encode_ARGV();
      package main::ListLibraries { do $0; }

      my ($libs) = _list_libraries();
      ok($libs, 'libraries');
      cmp_ok(scalar(@$libs), '>', 4, 'libraries found');
      ok($libs->[0]->{branchcode}, 'library 0 looks like a library');
    });
    subtest("--create-library" => sub {
      Test::More::plan(tests => 4);
      @ARGV=("--create-library=branchcode: $branchcode\nbranchemail: test\@example.com\nbranchcity: Öllölä",'-v','-v'); encode_ARGV();
      package main::CreateLibrary { do $0; }

      my $c = (grep {$_->{branchcode} eq $branchcode} @{_list_libraries()})[0];
      ok($c, "find library $branchcode");
      is($c->{branchname}, "$branchcode - Autogenerated by $0", 'description autogenerated');
      is($c->{branchemail}, 'test@example.com', 'branchemail');
      is($c->{branchcity}, 'Öllölä', 'branchcity');
    });
    subtest("--create-user" => sub {
      Test::More::plan(tests => 9);
      @ARGV=("--create-user=userid: $userid\ncardnumber: $cardnumber\ntfa_secret: $tfa_secret\nsurname: SukuniminenÄÖ",'-v','-v'); encode_ARGV();
      package main::CreateUser { do $0; }

      ok(get_default_category(), 'get_default_category');
      ok(get_default_branch(), 'get_default_branch');

      ok(my $p = find_patron($cardnumber, $userid), 'find_patron');
      is($p->surname, "SukuniminenÄÖ", 'surname');
      is($p->cardnumber, $cardnumber, 'cardnumber');
      is($p->userid, $userid, 'userid');
      is($p->branchcode, get_default_branch(), 'branchcode');
      is($p->categorycode, get_default_category(), 'categorycode');
      is($p->decoded_secret(), $tfa_secret, 'tfa_secret');
    });
    subtest("--create-user updates with password hash" => sub {
      Test::More::plan(tests => 8);
      my $password_hash = Koha::AuthUtils::hash_password($password);
      @ARGV=("--create-user=userid: $userid\ntfa_secret: $tfa_secret\ncardnumber: $cardnumber\nsurname: Sikanen\npassword: $password_hash\nlogin_attempts: 9",'-v','-v'); encode_ARGV();
      package main::CreateUserUpdate { do $0; }

      ok(my $p = find_patron($cardnumber, $userid), 'find_patron');
      is($p->surname, "Sikanen", 'surname');
      is($p->cardnumber, $cardnumber, 'cardnumber');
      is($p->userid, $userid, 'userid');
      is($p->password, $password_hash, 'password hash');
      is($p->branchcode, get_default_branch(), 'branchcode');
      is($p->categorycode, get_default_category(), 'categorycode');
      is($p->login_attempts, 0, 'login_attempts');
    });
    subtest("--delete-user", => sub {
      Test::More::plan(tests => 1);
      @ARGV=("--delete-user={userid: $userid}"); encode_ARGV();
      package main::DeleteUser { do $0; }

      ok(! find_patron($cardnumber, $userid), 'not find_patron');
    });
    subtest("--create-user with permissions and password" => sub {
      Test::More::plan(tests => 13);
      @ARGV=("--create-user={userid: '$userid', password: '$password', cardnumber: '$cardnumber', surname: 'Sukuniminen'}",
             "--grant-perms={userid: '$userid', module: 'circulate', subpermission: '1'}",
             "--grant-perms=userid: $userid\nmodule: serials\nsubpermission: claim_serials",
             "--list-user-perms={userid: '$userid'}",
             '-v','-v'); encode_ARGV();
      package main::CreateUserWithPermissionAndPassword { do $0; }

      ok(my $p = find_patron($cardnumber, $userid), 'find_patron');
      is($p->surname, "Sukuniminen", 'surname');
      is($p->cardnumber, $cardnumber, 'cardnumber');
      is($p->userid, $userid, 'userid');
      is($p->password, Koha::AuthUtils::hash_password($password, $p->password), 'password hash');
      is($p->branchcode, get_default_branch(), 'branchcode');
      is($p->categorycode, get_default_category(), 'categorycode');

      ok(my $pe = _list_user_permissions($p), 'permissions');
      is($pe->{circulate}->{permissions}->{ALL}, 1, 'circulate all permissions');
      ok($p->has_permission({circulate => 1}), 'has circulate all permissions');
      is($pe->{serials}->{permissions}->{claim_serials}, 'Claim missing serials', 'serials => claim_serials');
      ok($p->has_permission({serials => 'claim_serials'}), 'has serials => claim_serials');
      ok(! $p->has_permission({updatecharges => 'discount'}), 'no unset permission');
    });
  };
  if ($@) {
    BAIL_OUT($@);
  }
  $schema->storage->txn_rollback;
}