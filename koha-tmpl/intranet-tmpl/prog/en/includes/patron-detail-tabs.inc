<!-- patron-detail-tabs.inc -->
[% USE raw %]
[% PROCESS 'html_helpers.inc' %]
[% WRAPPER tabs id= "finesholdsissues" %]
    [% WRAPPER tabs_nav %]
        [% WRAPPER tab_item tabname= "checkouts" bt_active= 1 %]
            <span>Checkouts</span> (<span class="checkout_count">[% issuecount || 0 | html %]</span>)
        [% END %]

        [% IF relatives_issues_count %]
            [% WRAPPER tab_item tabname= "relatives-issues" %]
                <span>Relatives' checkouts</span> ([% relatives_issues_count | html %])
            [% END %]
        [% END %]

        [% IF ( guarantees_fines ) %]
            [% WRAPPER tab_item tabname= "guarantees_finesandcharges" %]
                <span>Guarantees' charges</span> ([% guarantees_fines | $Price %])
            [% END %]
        [% END %]

        [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
            [% WRAPPER tab_item tabname= "holds" %]
                <span>Holds</span> ([% holds_count || 0 | html %])
            [% END %]
            [% WRAPPER tab_item tabname="bookings" %]
                [% SET bookings_count = patron.bookings.filter_by_active.count %]
                [% SET expired_bookings_count = patron.bookings.count - bookings_count %]
                <span class="bookings_count">Bookings ([% bookings_count || 0 | html %])</span>
            [% END %]
        [% END %]

        [% IF Koha.Preference('UseRecalls') %]
            [% WRAPPER tab_item tabname= "recalls" %]
                <span>Recalls</span> ([% recalls.count || 0 | html %])
            [% END %]
        [% END %]

        [% IF Koha.Preference('ArticleRequests') %]
            [% SET article_requests = Context.Scalar( Context.Scalar( patron, 'article_requests' ), 'filter_by_current') %]
            [% WRAPPER tab_item tabname= "article-requests" %]
                <span>Article requests</span> ([% article_requests.count || 0 | html %])
            [% END %]
        [% END %]

        [% IF Koha.Preference('ClaimReturnedLostValue') || Koha.Preference('BundleLostValue') %]
            [% WRAPPER tab_item tabname= "return-claims" %]
                <span>Claims</span>
                [% IF ( patron.return_claims.count ) %]
                    ([% IF patron.return_claims.resolved.count == 0 %]
                        <span title="Resolved claims" class="badge text-bg-info" id="return-claims-count-resolved">[% patron.return_claims.resolved.count | html %]</span>
                    [% ELSE %]
                        <span title="Resolved claims" class="badge text-bg-info" id="return-claims-count-resolved">[% patron.return_claims.resolved.count | html %]</span>
                    [% END %]
                    [% IF patron.return_claims.unresolved.count == 0 %]
                        <span title="Unresolved claims" class="badge text-bg-info" id="return-claims-count-unresolved">[% patron.return_claims.unresolved.count | html %]</span>
                    [% ELSE %]
                        <span title="Unresolved claims" class="badge text-bg-warning" id="return-claims-count-unresolved">[% patron.return_claims.unresolved.count | html %]</span>
                    [% END %])
                [% ELSE %]
                    [% no_claims = 0 %]
                    (<span title="Resolved claims" class="badge text-bg-info" id="return-claims-count-resolved">[% no_claims | html %]</span>
                    <span title="Unresolved claims" class="badge text-bg-info" id="return-claims-count-unresolved">[% no_claims | html %]</span>)
                [% END # /IF patron.return_claims.count %]
            [% END # /WRAPPER tab_item return-claims %]
        [% END %]

        [% WRAPPER tab_item tabname= "reldebarments" %]
            <span>Restrictions ([% patron.restrictions.count || 0 | html %])</span>
        [% END %]

        [% SET enrollments = patron.get_club_enrollments %]
        [% SET enrollable  = patron.get_enrollable_clubs(0) %]
        <!-- 0 => not OPAC -->
        [% IF CAN_user_clubs && ( enrollable.count || enrollments.count ) %]
            [% WRAPPER tab_item tabname= "clubs" %]
                <span>Clubs ([% enrollments.count | html %]/[% enrollable.count | html %])</span>
            [% END %]
        [% END %]

        [% IF CAN_user_tools_manage_patron_lists || patron_lists_count %]
            [% WRAPPER tab_item tabname="pat_lists" %]
                <span>Patron lists ([% patron_lists_count | html %])</span>
            [% END %]
        [% END %]
    [% END # /WRAPPER tabs_nav %]

    [% WRAPPER tab_panels %]
        [% WRAPPER tab_panel tabname="checkouts" bt_active= 1 %]
            [% INCLUDE "checkouts-table.inc" %]
        [% END # /tab_panel# %]

        [% IF relatives_issues_count %]
            [% WRAPPER tab_panel tabname="relatives-issues" %]
                [% INCLUDE "relatives-issues-table.inc" %]
            [% END # /tab_panel# %]
        [% END %]

        [% IF ( guarantees_fines ) %]
            [% WRAPPER tab_panel tabname="guarantees_finesandcharges" %]
                <table id="tguaranteesfines">
                    <thead>
                        <tr>
                            <th>Guarantee</th>
                            <th>Amount outstanding</th>
                        </tr>
                    </thead>
                    [% FOREACH guarantee IN guarantees %]
                        <tr>
                            <td>[% INCLUDE 'patron-title.inc' patron=guarantee hide_patron_infos_if_needed=1 %]</td>
                            [% IF logged_in_user.can_see_patron_infos( guarantee ) %]
                                <td>[% guarantee.account.balance | $Price %]</td>
                            [% ELSE %]
                                <td>-</td>
                            [% END %]
                        </tr>
                    [% END %]
                    <tfoot>
                        <td>Total due</td>
                        <td>[% guarantees_fines | $Price %]</td>
                    </tfoot>
                </table>
            [% END # /tab_panel# %]
        [% END # /tab_panel# %]

        [% IF CAN_user_clubs && ( enrollments.count || enrollable.count ) %]
            [% WRAPPER tab_panel tabname="clubs" %]
                Loading...
            [% END # /tab_panel# %]
        [% END %]

        [% IF CAN_user_tools_manage_patron_lists || patron_lists_count %]
            [% WRAPPER tab_panel tabname="pat_lists" %]
                Loading...
            [% END # /tab_panel# %]
        [% END %]

        [% WRAPPER tab_panel tabname="reldebarments" %]
            [% INCLUDE 'patron-restrictions-tab.inc' %]
        [% END # /tab_panel# %]

        [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
            [% WRAPPER tab_panel tabname="holds" %]
                [% IF ( holds_count ) %]
                    <form action="/cgi-bin/koha/reserve/modrequest.pl" method="post">
                        [% INCLUDE 'csrf-token.inc' %]
                        <input type="hidden" name="from" value="circ" />
                        <table id="holds-table" style="width: 100% !Important;">
                            <thead>
                                <tr>
                                    <th>Hold date</th>
                                    <th class="anti-the">Title</th>
                                    <th>Call number</th>
                                    <th>Item type</th>
                                    <th>Barcode</th>
                                    <th>Pickup at</th>
                                    <th>Expiration</th>
                                    <th>Priority</th>
                                    <th>Notes</th>
                                    <th>Delete?</th>
                                    <th>Suspend?</th>
                                    <th>Status</th>
                                </tr>
                            </thead>
                        </table>

                        <fieldset class="action">
                            <input type="submit" class="btn btn-primary cancel" name="submit" value="Cancel marked holds" />

                            [% SET hold_cancellation = AuthorisedValues.GetAuthValueDropbox('HOLD_CANCELLATION') %]
                            [% IF hold_cancellation.count %]
                                <label for="cancellation-reason">Cancellation reason:</label>
                                <input type="hidden" name="op" value="cud-cancelall" />
                                <select name="cancellation-reason" id="cancellation-reason">
                                    <option value="">No reason given</option>
                                    [% FOREACH reason IN hold_cancellation %]
                                        <option value="[% reason.authorised_value | html %]">[% reason.lib | html %]</option>
                                    [% END %]
                                </select>
                            [% END %]
                        </fieldset>
                    </form>

                    [% IF Koha.Preference('SuspendHoldsIntranet') %]
                        <form action="/cgi-bin/koha/reserve/modrequest_suspendall.pl" method="post">
                            [% INCLUDE 'csrf-token.inc' %]
                            <fieldset class="action">
                                <input type="hidden" name="op" value="cud-suspendall" />
                                <input type="hidden" name="from" value="[% patronpage | html %]" />
                                <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
                                <input type="submit" class="btn btn-primary" value="Suspend all holds" />

                                [% IF Koha.Preference('AutoResumeSuspendedHolds') %]
                                    <label for="suspend_until">until</label>
                                    <input type="text" size="10" id="suspend_until" name="suspend_until" class="flatpickr" data-flatpickr-futuredate="true" />
                                    <span class="hint">Specify date on which to resume [% INCLUDE 'date-format.inc' %]: </span>
                                [% END %]
                            </fieldset>
                        </form>

                        <form action="/cgi-bin/koha/reserve/modrequest_suspendall.pl" method="post">
                            [% INCLUDE 'csrf-token.inc' %]
                            <fieldset class="action">
                                <input type="hidden" name="op" value="cud-unsuspendall" />
                                <input type="hidden" name="from" value="borrower" />
                                <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
                                <input type="hidden" name="suspend" value="0" />
                                <input type="submit" class="btn btn-primary" value="Resume all suspended holds" />
                            </fieldset>
                        </form>
                    [% END # IF SuspendHoldsIntranet %]
                [% ELSE %]
                    <p>Patron has nothing on hold.</p>
                [% END %]
            [% END # /tab_panel#holds %]

            [% WRAPPER tab_panel tabname="bookings" %]
                [% IF ( bookings_count ) %]
                    <fieldset class="action filters" style="cursor:pointer;">
                        <a id="expired_filter" class="filtered"><i class="fa fa-bars"></i> Show expired</a>
                    </fieldset>
                    <table id="bookings_table" style="width: 100% !Important;"></table>
                [% ELSIF ( expired_bookings_count ) %]
                    <fieldset class="action filters" style="cursor:pointer;">
                        <a id="expired_filter"><i class="fa fa-filter"></i> Hide expired</a>
                    </fieldset>
                    <table id="bookings_table" style="width: 100% !Important;"></table>
                [% ELSE %]
                    <p>Patron has nothing booked.</p>
                [% END %]
            [% END %]
        [% END %]

        [% IF Koha.Preference('UseRecalls') %]
            [% WRAPPER tab_panel tabname="recalls" %]
                [% INCLUDE 'recalls.inc' %]
            [% END # /tab_panel# %]
        [% END %]

        [% IF Koha.Preference('ClaimReturnedLostValue') || Koha.Preference('BundleLostValue') %]
            [% WRAPPER tab_panel tabname="return-claims" %]
                [% INCLUDE 'patron-return-claims.inc' %]
            [% END # /tab_panel# %]
        [% END %]

        [% IF Koha.Preference('ArticleRequests') %]
            [% WRAPPER tab_panel tabname="article-requests" %]
                [% INCLUDE 'patron-article-requests.inc' %]
            [% END %]
        [% END # /tab_panel# %]
    [% END # /WRAPPER tab_panels %]
[% END # /WRAPPER tabs %]
<!-- /patron-detail-tabs.inc -->
