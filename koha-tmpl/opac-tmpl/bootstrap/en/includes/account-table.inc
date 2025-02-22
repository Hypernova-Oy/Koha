[% PROCESS 'accounts.inc' %]
<form method="post" action="opac-account-pay.pl" class="form-horizontal">
    [% INCLUDE 'csrf-token.inc' %]
    <input type="hidden" name="op" value="cud-pay" />
    [% IF ( ACCOUNT_LINES ) %]
        <table class="table table-bordered table-striped finestable" id="finestable">
            <caption class="sr-only">Your charges</caption>
            <thead>
                <tr>
                    [% IF ENABLE_OPAC_PAYMENTS %]<th>&nbsp;</th>[% END %]
                    <th>Created</th>
                    <th class="psort">Updated</th>
                    <th class="all">Type</th>
                    <th>Description</th>
                    <th>Amount</th>
                    <th>Amount outstanding</th>
                    <th></th>
                </tr>
            </thead>

            <tbody>
                [% FOREACH ACCOUNT_LINE IN ACCOUNT_LINES %]
                    [% SET tr_class = '' %]
                    [% IF ACCOUNT_LINE.amountoutstanding > 0 || ACCOUNT_LINE.amountoutstanding < 0 %]
                        [% tr_class = "outstanding" %]
                    [% END %]
                    <tr class="[% tr_class | html %]">
                        [% IF ENABLE_OPAC_PAYMENTS %]
                            <td>
                                [% IF ACCOUNT_LINE.amountoutstanding > 0 %]
                                    [% SET DISPLAY_PAYMENT_BLOCK = 1 %]
                                    <input class="checkbox-pay pay-online hidden" name="accountline" type="checkbox" id="checkbox-pay-[% ACCOUNT_LINE.accountlines_id | html %]" value="[% ACCOUNT_LINE.accountlines_id | html %]" />
                                    <input type="hidden" id="amount-[% ACCOUNT_LINE.accountlines_id | html %]" value="[% ACCOUNT_LINE.amountoutstanding | html %]" />
                                [% END %]
                            </td>
                        [% END %]
                        <td data-order="[% ACCOUNT_LINE.date | html %]">[% ACCOUNT_LINE.date | $KohaDates %]</td>
                        <td data-order="[% ACCOUNT_LINE.timestamp | html %]">[% ACCOUNT_LINE.timestamp | $KohaDates with_hours = 1 %]</td>
                        <td> [% PROCESS account_type_description account=ACCOUNT_LINE %] </td>
                        <td>
                            [%- IF ACCOUNT_LINE.payment_type %][% AuthorisedValues.GetByCode('PAYMENT_TYPE', ACCOUNT_LINE.payment_type, 1) | html %][% END %]
                            [%- IF ACCOUNT_LINE.description %][% ACCOUNT_LINE.description | html %][% END %]
                            [% IF ACCOUNT_LINE.itemnumber %]([% ACCOUNT_LINE.item.biblio.title | html %])[% END %]
                        </td>
                        [% SET td_class = ACCOUNT_LINE.is_credit ? 'credit' : 'debit' %]
                        [% IF ( ACCOUNT_LINE.is_credit ) %]
                            <td class="credit">[% ACCOUNT_LINE.amount * -1 | $Price %]</td>
                        [% ELSE %]
                            <td class="debit">[% ACCOUNT_LINE.amount | $Price %]</td>
                        [% END %]
                        [% IF ( ACCOUNT_LINE.is_credit ) %]
                            <td class="credit">[% ACCOUNT_LINE.amountoutstanding * -1 | $Price %]</td>
                        [% ELSE %]
                            <td class="debit">[% ACCOUNT_LINE.amountoutstanding | $Price %]</td>
                        [% END %]
                        <td></td>
                    </tr>
                [% END %]
            </tbody>

            <tfoot>
                <tr>
                    [%- IF ENABLE_OPAC_PAYMENTS -%]
                        [%- SET COLSPAN = 6 -%]
                    [%- ELSE -%]
                        [%- SET COLSPAN = 5 -%]
                    [%- END -%]
                    <th class="sum" colspan="[% COLSPAN | html %]">Total due</th>
                    <td class="sum">[% total | $Price %]</td>
                    <th></th>
                </tr>
                [% IF outstanding_credits.total_outstanding < 0 %]
                    [% FOREACH outstanding_credit IN outstanding_credits %]
                        [% SET tr_class = '' %]
                        [% IF outstanding_credit.amountoutstanding < 0 %]
                            [% tr_class = "outstanding" %]
                        [% END %]
                        <tr class="[% tr_class | html %]">
                            [% IF ENABLE_OPAC_PAYMENTS %]<td></td>[% END %]
                            <td><span title="[% outstanding_credit.date | html %]">[% outstanding_credit.date | $KohaDates %]</span></td>
                            <td><span title="[% outstanding_credit.timestamp | html %]">[% outstanding_credit.date | $KohaDates with_hours = 1 %]</span></td>
                            <td> [% PROCESS account_type_description account=outstanding_credit %] </td>
                            <td>
                                [%- IF outstanding_credit.payment_type %][% AuthorisedValues.GetByCode('PAYMENT_TYPE', outstanding_credit.payment_type, 1) | html %][% END %]
                                [%- IF outstanding_credit.description %][% outstanding_credit.description | html %][% END %]
                                [% IF outstanding_credit.itemnumber %]([% outstanding_credit.item.biblio.title | html %])[% END %]
                            </td>
                            <td class="credit">[% outstanding_credit.amount * -1 | $Price %]</td>
                            <td class="credit">[% outstanding_credit.amountoutstanding * -1 | $Price %]</td>
                            <td></td>
                        </tr>
                    [% END %]
                    <tr>
                        <th class="sum" colspan="[% COLSPAN | html %]">Total due if credit(s) applied:</th>
                        <td class="sum">[% total + outstanding_credits.total_outstanding | $Price %]</td>
                        <td></td>
                    </tr>
                [% END %]
            </tfoot>
        </table>
    [% ELSE %]
        <h3>You have no fines or charges</h3>
    [% END # /IF ( ACCOUNT_LINES ) %]

    [% FOREACH r IN relatives %]
        <h3 id="g[% r.patron.id | html %]">[% r.patron.firstname | html %] [% r.patron.surname | html %]'s fines and charges</h3>

        <table class="table table-bordered table-striped finestable" id="finestable-[% r.patron.id | html %]">
            <thead>
                <tr>
                    <th>Created</th>
                    <th>Updated</th>
                    <th>Description</th>
                    <th>Fine amount</th>
                    <th>Amount outstanding</th>
                    <th></th>
                </tr>
            </thead>

            <tbody>
                [% SET account_sum = 0 %]
                [% FOREACH a IN r.accountlines %]
                    [% SET account_sum = account_sum + a.amountoutstanding %]
                    <tr>
                        <td data-order="[% a.date | html %]">[% a.date | $KohaDates %]</td>
                        <td data-order="[% a.timestamp | html %]">[% a.timestamp | $KohaDates with_hours = 1 %]</td>
                        <td>
                            [% PROCESS account_type_description account=a %]
                            [%- IF a.payment_type %], [% AuthorisedValues.GetByCode('PAYMENT_TYPE', a.payment_type, 1) | html %][% END %]
                            [%- IF a.description %], [% a.description | html %][% END %]
                            [% IF a.itemnumber %]([% a.item.biblio.title | html %])[% END %]
                        </td>
                        <td class="[% a.amount < 0 ? 'credit' : 'credit' | html %]">[% a.amount | $Price %]</td>
                        <td class="[% a.amountoutstanding < 0 ? 'credit' : 'debit' | html %]">[% a.amountoutstanding | $Price %]</td>
                        <td></td>
                    </tr>
                [% END %]
            </tbody>

            <tfoot>
                <tr>
                    <th class="sum" colspan="4">Total due</th>
                    <td class="sum">[% account_sum | $Price %]</td>
                    <th></th>
                </tr>
            </tfoot>
        </table>
    [% END # /FOREACH r %]

    [% IF ENABLE_OPAC_PAYMENTS && DISPLAY_PAYMENT_BLOCK %]
        <fieldset class="pay-online hidden">
            <legend>Pay selected fines and charges</legend>
            <span class="help-block"><h2>Payment method</h2></span>

            [% FOREACH p IN plugins %]
                <div class="control-group">
                    <label class="radio">
                        <input type="radio" data-threshold="[% p.opac_online_payment_threshold | html %]" name="payment_method" id="payment_method-[% p.class | html %]" value="[% p.class | html %]" checked="checked" />
                        [% p.get_metadata.name | html %]
                    </label>
                    <small class="help-block text-muted"></small>
                </div>
            [% END %]

            <div class="control-group">
                <input type="hidden" id="payment-amount" name="payment_amount" value="0" />
                <button id="submit-pay" type="submit" class="btn btn-primary" disabled="disabled">Make payment</button>
                <span id="amount-to-pay-label"> Amount to pay: <span id="amount-to-pay">0.00</span> </span>
            </div>
        </fieldset>
    [% END # /IF ENABLE_OPAC_PAYMENTS && DISPLAY_PAYMENT_BLOCK %]
</form>
