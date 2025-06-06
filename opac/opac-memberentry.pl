#!/usr/bin/perl

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

use CGI             qw ( -utf8 );
use Digest::MD5     qw( md5_base64 md5_hex );
use JSON            qw( to_json );
use List::MoreUtils qw( any each_array uniq );
use String::Random  qw( random_string );
use Try::Tiny;

use C4::Auth   qw( get_template_and_user );
use C4::Output qw( output_html_with_http_headers );
use C4::Context;
use C4::Letters qw( GetPreparedLetter EnqueueLetter SendQueuedMessages );
use C4::Form::MessagingPreferences;
use C4::Members::Messaging qw( SetMessagingPreferencesFromDefaults );
use Koha::AuthUtils;
use Koha::Patrons;
use Koha::Patron::Consent;
use Koha::Patron::Modification;
use Koha::Patron::Modifications;
use C4::Scrubber;
use Koha::DateUtils qw( dt_from_string );
use Koha::Email;
use Koha::Libraries;
use Koha::Patron::Attribute::Types;
use Koha::Patron::Attributes;
use Koha::Patron::Images;
use Koha::Patron::Categories;
use Koha::Policy::Patrons::Cardnumber;
use Koha::AuthorisedValues;
my $cgi = CGI->new;
my $dbh = C4::Context->dbh;

my ( $template, $borrowernumber, $cookie ) = get_template_and_user(
    {
        template_name   => "opac-memberentry.tt",
        type            => "opac",
        query           => $cgi,
        authnotrequired => 1,
    }
);

my $op = $cgi->param('op') || q{};
if ( $borrowernumber && ( $op eq 'cud-create' || $op eq 'new' ) ) {
    print $cgi->redirect("/cgi-bin/koha/opac-main.pl");
    exit;
}

if ( $op eq q{} ) {
    if ($borrowernumber) {
        $op = 'edit';
    } else {
        $op = 'new';
    }
}

my $PatronSelfRegistrationDefaultCategory = C4::Context->preference('PatronSelfRegistrationDefaultCategory');
my $defaultCategory                       = Koha::Patron::Categories->find($PatronSelfRegistrationDefaultCategory);

# Having a valid PatronSelfRegistrationDefaultCategory is mandatory
if ( !C4::Context->preference('PatronSelfRegistration') && !$borrowernumber
    || ( ( $op eq 'new' || $op eq 'cud-create' ) && !$defaultCategory ) )
{
    print $cgi->redirect("/cgi-bin/koha/opac-main.pl");
    exit;
}

my $mandatory = GetMandatoryFields($op);

my $params = {};
if ( $op eq 'cud-create' || $op eq 'new' ) {
    my @PatronSelfRegistrationLibraryList = split '\|', C4::Context->preference('PatronSelfRegistrationLibraryList');
    $params = { branchcode => { -in => \@PatronSelfRegistrationLibraryList } }
        if @PatronSelfRegistrationLibraryList;
}
my $libraries = Koha::Libraries->search( $params, { order_by => ['branchname'] } );

my ( $min, $max ) = Koha::Policy::Patrons::Cardnumber->get_valid_length();
if ( defined $min ) {
    $template->param(
        minlength_cardnumber => $min,
        maxlength_cardnumber => $max
    );
}

my $translated_languages = C4::Languages::getTranslatedLanguages( 'opac', C4::Context->preference('opacthemes') );

$template->param(
    op                => $op,
    hidden            => GetHiddenFields( $mandatory, $op ),
    mandatory         => $mandatory,
    libraries         => $libraries,
    OPACPatronDetails => C4::Context->preference('OPACPatronDetails'),
    defaultCategory   => $defaultCategory,
    languages         => $translated_languages,
);

my $attributes            = ParsePatronAttributes( $borrowernumber, $cgi );
my $conflicting_attribute = 0;

foreach my $attr (@$attributes) {
    my $attribute = Koha::Patron::Attribute->new($attr);
    if ( !$attribute->unique_ok ) {
        my $attr_type = Koha::Patron::Attribute::Types->find( $attr->{code} );
        $template->param(
            extended_unique_id_failed_code        => $attr->{code},
            extended_unique_id_failed_value       => $attr->{attribute},
            extended_unique_id_failed_description => $attr_type->description,
        );
        $conflicting_attribute = 1;
    }
}

if ( $op eq 'cud-create' ) {

    my %borrower = ParseCgiForBorrower($cgi);

    %borrower = DelEmptyFields(%borrower);
    $borrower{categorycode} ||= $PatronSelfRegistrationDefaultCategory;

    my @empty_mandatory_fields =
        ( CheckMandatoryFields( \%borrower, $op ), CheckMandatoryAttributes( \%borrower, $attributes ) );
    my $invalidformfields = CheckForInvalidFields( { borrower => \%borrower, context => 'create' } );
    delete $borrower{'password2'};
    my $is_cardnumber_valid;
    if ( !grep { $_ eq 'cardnumber' } @empty_mandatory_fields ) {

        # No point in checking the cardnumber if it's missing and mandatory, it'll just generate a
        # spurious length warning.
        my $patron = Koha::Patrons->find( $borrower{borrowernumber} );
        $is_cardnumber_valid = Koha::Policy::Patrons::Cardnumber->is_valid( $borrower{cardnumber}, $patron );
        unless ($is_cardnumber_valid) {
            for my $m ( @{ $is_cardnumber_valid->messages } ) {
                my $message = $m->message;
                if ( $message eq 'already_exists' ) {
                    $template->param( cardnumber_already_exists => 1 );
                } elsif ( $message eq 'invalid_length' ) {
                    $template->param( cardnumber_wrong_length => 1 );
                }
            }
        }
    }

    if ( @empty_mandatory_fields || @$invalidformfields || !$is_cardnumber_valid || $conflicting_attribute ) {

        $template->param(
            empty_mandatory_fields => \@empty_mandatory_fields,
            invalid_form_fields    => $invalidformfields,
            borrower               => \%borrower
        );
        $template->param( patron_attribute_classes => GeneratePatronAttributesForm( undef, $attributes ) );
    } elsif ( md5_base64( uc( $cgi->param('captcha') ) ) ne $cgi->param('captcha_digest') ) {
        $template->param(
            failed_captcha => 1,
            borrower       => \%borrower
        );
        $template->param( patron_attribute_classes => GeneratePatronAttributesForm( undef, $attributes ) );
    } elsif ( !$libraries->find( $borrower{branchcode} ) ) {
        die "Branchcode not allowed";    # They hack the form
    } else {
        if ( C4::Context->preference('PatronSelfRegistrationVerifyByEmail') ) {
            ( $template, $borrowernumber, $cookie ) = get_template_and_user(
                {
                    template_name   => "opac-registration-email-sent.tt",
                    type            => "opac",
                    query           => $cgi,
                    authnotrequired => 1,
                }
            );
            $template->param( 'email' => $borrower{'email'} );

            my $verification_token = md5_hex( time() . {} . rand() . {} . $$ );
            while ( Koha::Patron::Modifications->search( { verification_token => $verification_token } )->count() ) {
                $verification_token = md5_hex( time() . {} . rand() . {} . $$ );
            }

            $borrower{password} =
                Koha::AuthUtils::generate_password( Koha::Patron::Categories->find( $borrower{categorycode} ) )
                unless $borrower{password};
            $borrower{verification_token} = $verification_token;

            $borrower{extended_attributes} = to_json($attributes);
            $borrower{borrowernumber}      = 0;                      # prevent warn Missing value for PK column
            Koha::Patron::Modification->new( \%borrower )->store();

            #Send verification email
            my $letter = C4::Letters::GetPreparedLetter(
                module      => 'members',
                letter_code => 'OPAC_REG_VERIFY',
                lang        => 'default',           # Patron does not have a preferred language defined yet
                tables      => {
                    borrower_modifications => $verification_token,
                },
            );

            my $message_id = C4::Letters::EnqueueLetter(
                {
                    letter                 => $letter,
                    message_transport_type => 'email',
                    to_address             => $borrower{'email'},
                    from_address           => C4::Context->preference('KohaAdminEmailAddress'),
                }
            );
            C4::Letters::SendQueuedMessages( { message_id => $message_id } ) if $message_id;
        } else {
            $borrower{password} ||=
                Koha::AuthUtils::generate_password( Koha::Patron::Categories->find( $borrower{categorycode} ) );
            my $consent_dt = delete $borrower{gdpr_proc_consent};
            my $patron;
            try {
                $patron = Koha::Patron->new( \%borrower )->store;
                Koha::Patron::Consent->new(
                    { borrowernumber => $patron->borrowernumber, type => 'GDPR_PROCESSING', given_on => $consent_dt } )
                    ->store
                    if $patron && $consent_dt;
                C4::Members::Messaging::SetMessagingPreferencesFromDefaults(
                    { borrowernumber => $patron->borrowernumber, categorycode => $patron->categorycode } );
            } catch {
                my $type = ref($_);
                my $info = "$_";
                $template->param( error_type => $type, error_info => $info );
                $template->param( borrower   => \%borrower );
            };

            ( $template, $borrowernumber, $cookie ) = get_template_and_user(
                {
                    template_name   => "opac-registration-confirmation.tt",
                    type            => "opac",
                    query           => $cgi,
                    authnotrequired => 1,
                }
            ) if $patron;

            if ($patron) {
                $patron->extended_attributes->filter_by_branch_limitations->delete;
                $patron->extended_attributes($attributes);

                $template->param( password_cleartext => $patron->plain_text_password );
                $template->param( borrower           => $patron->unblessed );

                $template->param( confirmed => 1 );

                # If 'AutoEmailNewUser' syspref is on, email user their account details from the 'notice' that matches the user's branchcode.
                if ( C4::Context->preference("AutoEmailNewUser") ) {

                    #look for defined primary email address, if blank - attempt to use borr.email and borr.emailpro instead
                    my $emailaddr = $patron->notice_email_address;

                    # if we manage to find a valid email address, send notice
                    if ($emailaddr) {
                        eval {
                            my $letter = GetPreparedLetter(
                                module      => 'members',
                                letter_code => 'WELCOME',
                                branchcode  => $patron->branchcode,,
                                lang        => $patron->lang || 'default',
                                tables      => {
                                    'branches'  => $patron->branchcode,
                                    'borrowers' => $patron->borrowernumber,
                                },
                                want_librarian => 1,
                            ) or return;

                            my $message_id = EnqueueLetter(
                                {
                                    letter                 => $letter,
                                    borrowernumber         => $patron->id,
                                    to_address             => $emailaddr,
                                    message_transport_type => 'email'
                                }
                            );
                            SendQueuedMessages( { message_id => $message_id } ) if $message_id;
                        };
                    }
                }

                # Notify library of new patron registration
                my $notify_library = C4::Context->preference('EmailPatronRegistrations');
                if ($notify_library) {
                    $patron->notify_library_of_registration($notify_library);
                }

            }
        }
    }
} elsif ( $op eq 'cud-update' ) {

    my $borrower = Koha::Patrons->find($borrowernumber)->unblessed;

    my %borrower = ParseCgiForBorrower($cgi);
    $borrower{borrowernumber} = $borrowernumber;
    $borrower{categorycode}   = $borrower->{categorycode};

    my @empty_mandatory_fields = grep { $_ ne 'password' }    # password is not required when editing personal details
        ( CheckMandatoryFields( \%borrower, $op ), CheckMandatoryAttributes( \%borrower, $attributes ) );
    my $invalidformfields = CheckForInvalidFields( { borrower => \%borrower, context => 'update' } );

    # Send back the data to the template
    %borrower = ( %$borrower, %borrower );

    if ( @empty_mandatory_fields || @$invalidformfields ) {
        $template->param(
            empty_mandatory_fields => \@empty_mandatory_fields,
            invalid_form_fields    => $invalidformfields,
            borrower               => \%borrower,
        );
        $template->param( patron_attribute_classes => GeneratePatronAttributesForm( $borrowernumber, $attributes ) );

        $template->param( op => 'edit' );
    } else {

        # If preferred name is not included but firstname is then set preferred_name to firstname
        $borrower{preferred_name} = $borrower{firstname}
            if defined $borrower{firstname} && !defined $borrower{preferred_name};
        my %borrower_changes = DelUnchangedFields( $borrowernumber, %borrower );
        $borrower_changes{'changed_fields'} = join ',', keys %borrower_changes;
        my $extended_attributes_changes = FilterUnchangedAttributes( $borrowernumber, $attributes );

        if ( $borrower_changes{'changed_fields'} || scalar @{$extended_attributes_changes} > 0 ) {
            ( $template, $borrowernumber, $cookie ) = get_template_and_user(
                {
                    template_name   => "opac-memberentry-update-submitted.tt",
                    type            => "opac",
                    query           => $cgi,
                    authnotrequired => 1,
                }
            );

            $borrower_changes{borrowernumber}      = $borrowernumber;
            $borrower_changes{extended_attributes} = to_json($extended_attributes_changes);

            Koha::Patron::Modifications->search( { borrowernumber => $borrowernumber } )->delete;

            $borrower_changes{verification_token} = q{};    # prevent warn Missing value for PK column
            my $m = Koha::Patron::Modification->new( \%borrower_changes )->store();

            #Automatically approve patron profile changes if set in syspref

            if ( C4::Context->preference('AutoApprovePatronProfileSettings') ) {

                # Need to get the object from database, otherwise it is not complete enough to allow deletion
                # when approval has been performed.
                my $tmp_m = Koha::Patron::Modifications->find( { borrowernumber => $borrowernumber } );
                $tmp_m->approve() if $tmp_m;
            }

            my $patron = Koha::Patrons->find($borrowernumber);
            $template->param( borrower => $patron->unblessed );
        } else {
            my $patron = Koha::Patrons->find($borrowernumber);
            $template->param(
                op                       => 'edit',
                nochanges                => 1,
                borrower                 => $patron->unblessed,
                patron_attribute_classes => GeneratePatronAttributesForm( $borrowernumber, $attributes ),
            );
        }
    }
} elsif ( $op eq 'edit' ) {    #Display logged in borrower's data
    my $patron   = Koha::Patrons->find($borrowernumber);
    my $borrower = $patron->unblessed;

    $template->param(
        borrower => $borrower,
        hidden   => GetHiddenFields( $mandatory, 'edit' ),
    );

    if ( C4::Context->preference('OPACpatronimages') ) {
        $template->param( display_patron_image => 1 ) if $patron->image;
    }

    $template->param( patron_attribute_classes => GeneratePatronAttributesForm($borrowernumber) );
} else {

    # Render self-registration page
    $template->param( patron_attribute_classes => GeneratePatronAttributesForm() );
}

my $captcha      = random_string("CCCCC");
my $patron_param = Koha::Patrons->find($borrowernumber);
$template->param( has_guarantor_flag => $patron_param->guarantor_relationships->guarantors->_resultset->count )
    if $patron_param;

$template->param(
    captcha        => $captcha,
    captcha_digest => md5_base64($captcha),
    patron         => $patron_param
);

output_html_with_http_headers $cgi, $cookie, $template->output, undef, { force_no_caching => 1 };

sub GetHiddenFields {
    my ( $mandatory, $op ) = @_;
    my %hidden_fields;

    my $BorrowerUnwantedField =
        $op eq 'edit' || $op eq 'cud-update'
        ? C4::Context->preference("PatronSelfModificationBorrowerUnwantedField")
        : C4::Context->preference("PatronSelfRegistrationBorrowerUnwantedField");

    my @fields = split( /\|/, $BorrowerUnwantedField || q|| );
    foreach (@fields) {
        next unless m/\w/o;

        #Don't hide mandatory fields
        next if $mandatory->{$_};
        $hidden_fields{$_} = 1;
    }

    return \%hidden_fields;
}

sub GetMandatoryFields {
    my ($op) = @_;

    my %mandatory_fields;

    my $BorrowerMandatoryField =
        $op eq 'edit' || $op eq 'cud-update'
        ? C4::Context->preference("PatronSelfModificationMandatoryField")
        : C4::Context->preference("PatronSelfRegistrationBorrowerMandatoryField");

    my @fields = split( /\|/, $BorrowerMandatoryField );
    push @fields, 'gdpr_proc_consent' if C4::Context->preference('PrivacyPolicyConsent') && $op eq 'cud-create';

    foreach (@fields) {
        $mandatory_fields{$_} = 1;
    }

    if ( $op eq 'cud-create' || $op eq 'new' ) {
        $mandatory_fields{'email'} = 1
            if C4::Context->preference('PatronSelfRegistrationVerifyByEmail');
    }

    return \%mandatory_fields;
}

sub CheckMandatoryFields {
    my ( $borrower, $op ) = @_;

    my @empty_mandatory_fields;

    my $mandatory_fields = GetMandatoryFields($op);
    delete $mandatory_fields->{'cardnumber'};

    foreach my $key ( keys %$mandatory_fields ) {
        push( @empty_mandatory_fields, $key )
            unless ( defined( $borrower->{$key} ) && $borrower->{$key} );
    }

    return @empty_mandatory_fields;
}

sub CheckMandatoryAttributes {
    my ( $borrower, $attributes ) = @_;

    my @empty_mandatory_fields;

    for my $attribute (@$attributes) {
        my $attr = Koha::Patron::Attribute::Types->find( $attribute->{code} );
        push @empty_mandatory_fields, $attribute->{code}
            if $attr && $attr->opac_mandatory && $attribute->{attribute} =~ m|^\s*$|;
    }

    return @empty_mandatory_fields;
}

sub CheckForInvalidFields {
    my $params   = shift;
    my $borrower = $params->{borrower};
    my $context  = $params->{context};
    my @invalidFields;
    if ( $borrower->{'email'} ) {
        unless ( Koha::Email->is_valid( $borrower->{email} ) ) {
            push( @invalidFields, "email" );
        } elsif ( C4::Context->preference("PatronSelfRegistrationEmailMustBeUnique") && $context eq 'create' ) {
            my $patrons_with_same_email = Koha::Patrons->search(    # FIXME Should be search_limited?
                {
                    email => $borrower->{email},
                    (
                        exists $borrower->{borrowernumber}
                        ? ( borrowernumber => { '!=' => $borrower->{borrowernumber} } )
                        : ()
                    )
                }
            )->count;
            if ($patrons_with_same_email) {
                push @invalidFields, "duplicate_email";
            }
        } elsif ( C4::Context->preference("PatronSelfRegistrationConfirmEmail")
            && $borrower->{'email'} ne $borrower->{'repeat_email'}
            && !defined $borrower->{borrowernumber} )
        {
            push @invalidFields, "email_match";
        }

        # email passed all tests, so prevent attempting to store repeat_email
        delete $borrower->{'repeat_email'};
    }
    if ( $borrower->{'emailpro'} ) {
        push( @invalidFields, "emailpro" ) unless Koha::Email->is_valid( $borrower->{'emailpro'} );
    }
    if ( $borrower->{'B_email'} ) {
        push( @invalidFields, "B_email" ) unless Koha::Email->is_valid( $borrower->{'B_email'} );
    }
    if ( defined $borrower->{'password'}
        and $borrower->{'password'} ne $borrower->{'password2'} )
    {
        push( @invalidFields, "password_match" );
    }
    if ( $borrower->{'password'} ) {
        my ( $is_valid, $error ) = Koha::AuthUtils::is_password_valid(
            $borrower->{password},
            Koha::Patron::Categories->find(
                $borrower->{categorycode} || C4::Context->preference('PatronSelfRegistrationDefaultCategory')
            )
        );
        unless ($is_valid) {
            push @invalidFields, 'password_too_short'       if $error eq 'too_short';
            push @invalidFields, 'password_too_weak'        if $error eq 'too_weak';
            push @invalidFields, 'password_has_whitespaces' if $error eq 'has_whitespaces';
        }
    }

    if ( $borrower->{'dateofbirth'} ) {
        my $patron           = Koha::Patron->new( { dateofbirth => $borrower->{'dateofbirth'} } );
        my $age              = $patron->get_age;
        my $borrowercategory = Koha::Patron::Categories->find( $borrower->{'categorycode'} );
        my ( $low, $high ) = ( $borrowercategory->dateofbirthrequired, $borrowercategory->upperagelimit );
        my $upper_registration_age_restriction = C4::Context->preference("PatronSelfRegistrationAgeRestriction");
        if ( ( $high && ( $age > $high ) ) or ( $age < $low ) ) {
            push @invalidFields, 'ERROR_age_limitations';
        }
        if ( $upper_registration_age_restriction && $age > $upper_registration_age_restriction ) {
            push @invalidFields, 'ERROR_age_limitations_self_registration';
        }
    }

    return \@invalidFields;
}

sub ParseCgiForBorrower {
    my ($cgi) = @_;

    my $scrubber = C4::Scrubber->new();
    my %borrower;

    foreach my $field ( $cgi->param ) {
        if ( $field =~ '^borrower_' ) {
            my ($key) = substr( $field, 9 );
            if ( $field !~ '^borrower_password' ) {
                $borrower{$key} = $scrubber->scrub( scalar $cgi->param($field) );
            } else {

                # Allow html characters for passwords
                $borrower{$key} = $cgi->param($field);
            }
        }
    }

    # Replace checkbox 'agreed' by datetime in gdpr_proc_consent
    $borrower{gdpr_proc_consent} = dt_from_string
        if $borrower{gdpr_proc_consent} && $borrower{gdpr_proc_consent} eq 'agreed';

    delete $borrower{$_}
        for
        qw/borrowernumber date_renewed debarred debarredcomment flags privacy privacy_guarantor_fines privacy_guarantor_checkouts checkprevcheckout updated_on lastseen login_attempts overdrive_auth_token anonymized/
        ;    # See also members/memberentry.pl
    delete $borrower{$_}
        for
        qw/dateenrolled dateexpiry borrowernotes opacnote sort1 sort2 sms_provider_id autorenew_checkouts gonenoaddress lost relationship/
        ;    # On OPAC only
    delete $borrower{$_}
        for split( /\s*\|\s*/, C4::Context->preference('PatronSelfRegistrationBorrowerUnwantedField') || q{} );

    return %borrower;
}

sub DelUnchangedFields {
    my ( $borrowernumber, %new_data ) = @_;

    # get the mandatory fields so we can get the hidden fields
    my $mandatory    = GetMandatoryFields('edit');
    my $patron       = Koha::Patrons->find($borrowernumber);
    my $current_data = $patron->unblessed;

    # get the hidden fields so we don't obliterate them should they have data patrons aren't allowed to modify
    my $hidden_fields = GetHiddenFields( $mandatory, 'edit' );

    foreach my $key ( keys %new_data ) {
        next
            if ( $new_data{$key} || $current_data->{$key} )
            && $new_data{$key} ne $current_data->{$key}
            && !$hidden_fields->{$key};
        delete $new_data{$key};
    }

    return %new_data;
}

sub DelEmptyFields {
    my (%borrower) = @_;

    foreach my $key ( keys %borrower ) {
        delete $borrower{$key} unless $borrower{$key};
    }

    return %borrower;
}

sub FilterUnchangedAttributes {
    my ( $borrowernumber, $entered_attributes ) = @_;

    my @patron_attributes = grep { $_->type->opac_editable ? $_ : () }
        Koha::Patron::Attributes->search( { borrowernumber => $borrowernumber } )->as_list;

    my $patron_attribute_types;
    foreach my $attr (@patron_attributes) {
        $patron_attribute_types->{ $attr->code } += 1;
    }

    my $passed_attribute_types;
    foreach my $attr ( @{$entered_attributes} ) {
        $passed_attribute_types->{ $attr->{code} } += 1;
    }

    my @changed_attributes;

    # Loop through the current patron attributes
    foreach my $attribute_type ( keys %{$patron_attribute_types} ) {
        if ( ( $patron_attribute_types->{$attribute_type} // q{} ) ne
            ( $passed_attribute_types->{$attribute_type} // q{} ) )
        {
            # count differs, overwrite all attributes for given type
            foreach my $attr ( @{$entered_attributes} ) {
                push @changed_attributes, $attr
                    if $attr->{code} eq $attribute_type;
            }
        } else {

            # count matches, check values
            my $changes = 0;
            foreach my $attr ( grep { $_->code eq $attribute_type } @patron_attributes ) {
                $changes = 1
                    unless any { $_->{value} eq $attr->attribute } @{$entered_attributes};
                last if $changes;
            }

            if ($changes) {
                foreach my $attr ( @{$entered_attributes} ) {
                    push @changed_attributes, $attr
                        if $attr->{code} eq $attribute_type;
                }
            }
        }
    }

    # Loop through passed attributes, looking for new ones
    foreach my $attribute_type ( keys %{$passed_attribute_types} ) {
        if ( !defined $patron_attribute_types->{$attribute_type} ) {

            # YAY, new stuff
            foreach my $attr ( grep { $_->{code} eq $attribute_type } @{$entered_attributes} ) {
                push @changed_attributes, $attr;
            }
        }
    }

    return \@changed_attributes;
}

sub GeneratePatronAttributesForm {
    my ( $borrowernumber, $entered_attributes ) = @_;

    # Get all attribute types and the values for this patron (if applicable)
    my @types = grep { $_->opac_editable() or $_->opac_display }    # FIXME filter using DBIC
        Koha::Patron::Attribute::Types->search()->as_list();
    if ( scalar(@types) == 0 ) {
        return [];
    }

    my @displayable_attributes = grep { $_->type->opac_display ? $_ : () }
        Koha::Patron::Attributes->search( { borrowernumber => $borrowernumber } )->as_list;

    my %attr_values = ();

    # Build the attribute values list either from the passed values
    # or taken from the patron itself
    if ( defined $entered_attributes ) {
        foreach my $attr (@$entered_attributes) {
            push @{ $attr_values{ $attr->{code} } }, $attr->{attribute};
        }
    } elsif ( defined $borrowernumber ) {
        my @editable_attributes = grep { $_->type->opac_editable ? $_ : () } @displayable_attributes;
        foreach my $attr (@editable_attributes) {
            push @{ $attr_values{ $attr->code } }, $attr->attribute;
        }
    }

    # Add the non-editable attributes (that don't come from the form)
    foreach my $attr ( grep { !$_->type->opac_editable } @displayable_attributes ) {
        push @{ $attr_values{ $attr->code } }, $attr->attribute;
    }

    # Find all existing classes
    my @classes = sort( uniq( map { $_->class } @types ) );
    my %items_by_class;

    foreach my $attr_type (@types) {
        push @{ $items_by_class{ $attr_type->class() } }, {
            type => $attr_type,

            # If editable, make sure there's at least one empty entry,
            # to make the template's job easier
            values => $attr_values{ $attr_type->code() } || ['']
            }
            unless !defined $attr_values{ $attr_type->code() }
            and !$attr_type->opac_editable;
    }

    # Finally, build a list of containing classes
    my @class_loop;
    foreach my $class (@classes) {
        next unless ( $items_by_class{$class} );

        my $av = Koha::AuthorisedValues->search( { category => 'PA_CLASS', authorised_value => $class } );

        my $lib = $av->count ? $av->next->opac_description : $class;

        push @class_loop,
            {
            class => $class,
            items => $items_by_class{$class},
            lib   => $lib,
            };
    }

    return \@class_loop;
}

sub ParsePatronAttributes {
    my ( $borrowernumber, $cgi ) = @_;

    my @codes  = $cgi->multi_param('patron_attribute_code');
    my @values = $cgi->multi_param('patron_attribute_value');

    my @editable_attribute_types =
        map { $_->code } Koha::Patron::Attribute::Types->search( { opac_editable => 1 } )->as_list;

    my $ea = each_array( @codes, @values );
    my @attributes;

    my $delete_candidates = {};

    my $scrubber = C4::Scrubber->new();
    while ( my ( $code, $value ) = $ea->() ) {
        if ( any { $_ eq $code } @editable_attribute_types ) {

            # It is an editable attribute
            if ( !defined($value) or $value eq '' ) {
                $delete_candidates->{$code} = 1
                    unless $delete_candidates->{$code};
            } else {

                # we've got a value
                push @attributes, { code => $code, attribute => $scrubber->scrub($value) };

                # 'code' is no longer a delete candidate
                delete $delete_candidates->{$code}
                    if defined $delete_candidates->{$code};
            }
        }
    }

    foreach my $code ( keys %{$delete_candidates} ) {
        if (
            !$borrowernumber    # self-registration
            || Koha::Patron::Attributes->search( { borrowernumber => $borrowernumber, code => $code } )->count > 0
            )
        {
            push @attributes, { code => $code, attribute => '' }
                unless any { $_->{code} eq $code } @attributes;
        }
    }

    return \@attributes;
}

1;
