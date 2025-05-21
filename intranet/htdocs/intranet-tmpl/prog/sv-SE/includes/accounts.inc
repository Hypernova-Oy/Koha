[%- BLOCK account_type_description -%]
 [%- IF account.credit_type_code -%]
 [%- PROCESS credit_type_description credit_type = account.credit_type -%]
 [%- ELSIF account.debit_type_code -%]
 [%- PROCESS debit_type_description debit_type = account.debit_type -%]
 [%- END -%]
 [%- PROCESS account_status_description account=account -%]
[%- END -%]

[%- BLOCK debit_type_description -%]
 [%- SWITCH debit_type.code -%]
 [%- CASE 'ACCOUNT'          -%]<span>Avgift för att skapa konto</span>
 [%- CASE 'ACCOUNT_RENEW'    -%]<span>Avgift för att förnya konto</span>
 [%- CASE 'ARTICLE_REQUEST'  -%]<span>Avgift för artikelbeställning</span>
 [%- CASE 'LOST'             -%]<span>Förlorat exemplar</span>
 [%- CASE 'MANUAL'           -%]<span>Manuell avgift</span>
 [%- CASE 'NEW_CARD'         -%]<span>Nytt kort</span>
 [%- CASE 'OVERDUE'          -%]<span>Avgift</span>
 [%- CASE 'PROCESSING'       -%]<span>Hanteringsavgift för förlorat exemplar</span>
 [%- CASE 'RENT'             -%]<span>Hyresavgift</span>
 [%- CASE 'RENT_DAILY'       -%]<span>Daglig hyresavgift</span>
 [%- CASE 'RENT_RENEW'       -%]<span>Omlån av exemplar med hyresavgift</span>
 [%- CASE 'RENT_DAILY_RENEW' -%]<span>Omlån av exemplar med daglig hyresavgift</span>
 [%- CASE 'RESERVE'          -%]<span>Reservationsavgift</span>
 [%- CASE 'RESERVE_EXPIRED'  -%]<span>Reservation har väntat för länge</span>
 [%- CASE 'PAYOUT'           -%]<span>Betalning från bibliotek till låntagare</span>
 [%- CASE 'VOID'             -%]<span>Krediten har makulerats</span>
 [%- CASE                    -%]<span>[% debit_type.description | html %]</span>
 [%- END -%]
[%- END -%]

[%- BLOCK credit_type_description -%]
 [%- SWITCH credit_type.code -%]
 [%- CASE 'CANCELLATION' -%]<span>Avgift borttagen</span>
 [%- CASE 'CREDIT'       -%]<span>Kredit</span>
 [%- CASE 'DISCOUNT'     -%]<span>Rabatt</span>
 [%- CASE 'FORGIVEN'     -%]<span>Efterskänkt</span>
 [%- CASE 'LOST_FOUND'   -%]<span>Återbetalning för förlorat exemplar</span>
 [%- CASE 'OVERPAYMENT'  -%]<span>Återbetalning av överbetalning</span>
 [%- CASE 'PAYMENT'      -%]<span>Betalning</span>
 [%- CASE 'PROCESSING_FOUND' -%]<span>Återbetalning av hanteringsavgift för förlorat exemplar</span>
 [%- CASE 'PURCHASE'     -%]<span>Inköp</span>
 [%- CASE 'REFUND'       -%]<span>Återbetalning</span>
 [%- CASE 'WRITEOFF'     -%]<span>Avskrivning</span>
 [%- CASE                -%]<span>[% credit_type.description | html %]</span>
 [%- END -%]
[%- END -%]

[%- BLOCK account_status_description -%]
 [%- SWITCH account.status -%]
 [%- CASE 'UNRETURNED' -%]<span> (Pågående avgift)</span>
 [%- CASE 'RETURNED'   -%]<span> (Returnerad)</span>
 [%- CASE 'REPLACED'   -%]<span> (Ersatt)</span>
 [%- CASE 'REFUNDED'   -%]<span> (Återbetald)</span>
 [%- CASE 'FORGIVEN'   -%]<span> (Efterskänkt)</span>
 [%- CASE 'VOID'       -%]<span> (Annullerad)</span>
 [%- CASE 'LOST'       -%]<span> (Förkommen)</span>
 [%- CASE 'CANCELLED'  -%]<span> (Annullerad)</span>
 [%- CASE              -%]
 [%- END -%]
[%- END -%]
