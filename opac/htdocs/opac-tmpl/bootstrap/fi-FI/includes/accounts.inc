[%- BLOCK account_type_description -%]
 <span>
 [%- IF account.credit_type_code -%]
 [%- PROCESS credit_type_description credit_type_code = account.credit_type_code -%]
 [%- ELSIF account.debit_type_code -%]
 [%- PROCESS debit_type_description debit_type_code = account.debit_type_code -%]
 [%- END -%]
 [%- PROCESS account_status_description account=account -%]
 </span>
[%- END -%]

[%- BLOCK debit_type_description -%]
 [%- SWITCH debit_type_code -%]
 [%- CASE 'ACCOUNT'          -%]<span>Tilin luomismaksu</span>
 [%- CASE 'ACCOUNT_RENEW'    -%]<span>Tilin uusimismaksu</span>
 [%- CASE 'ARTICLE_REQUEST'  -%]<span>Artikkelipyynnön maksu</span>
 [%- CASE 'LOST'             -%]<span>Kadonnut aineisto</span>
 [%- CASE 'MANUAL'           -%]<span>Käsin lisätty maksu</span>
 [%- CASE 'NEW_CARD'         -%]<span>Uusi kortti</span>
 [%- CASE 'OVERDUE'          -%]<span>Myöhästymismaksu</span>
 [%- CASE 'PROCESSING'       -%]<span>Kadonneen niteen käsittelykulut</span>
 [%- CASE 'RENT'             -%]<span>Lainausmaksu</span>
 [%- CASE 'RENT_DAILY'       -%]<span>Päivävuokra</span>
 [%- CASE 'RENT_RENEW'       -%]<span>Vuokrattavan niteen uusinta</span>
 [%- CASE 'RENT_DAILY_RENEW' -%]<span>Päivävuokrattavan niteen uusinta</span>
 [%- CASE 'RESERVE'          -%]<span>Varausmaksu</span>
 [%- CASE 'RESERVE_EXPIRED'  -%]<span>Noutamaton varaus</span>
 [%- CASE 'PAYOUT'           -%]<span>Maksusuoritus kirjastolta asiakkaalle</span>
 [%- CASE 'VOID'             -%]<span>Hyvitys on mitätöity</span>
 [%- CASE                    -%]<span>[% debit_type.description | html %]</span>
 [%- END -%]
[%- END -%]

[%- BLOCK credit_type_description -%]
 [%- SWITCH credit_type_code -%]
 [%- CASE 'CANCELLATION' -%]<span>Peruutettu veloitus</span>
 [%- CASE 'CREDIT'       -%]<span>Hyvitys</span>
 [%- CASE 'DISCOUNT'     -%]<span>Alennus</span>
 [%- CASE 'FORGIVEN'     -%]<span>Maksun mitätöinti</span>
 [%- CASE 'LOST_FOUND'   -%]<span>Kadonneen niteen korvaushinnan hyvitys</span>
 [%- CASE 'OVERPAYMENT'  -%]<span>Liikamaksun hyvitys</span>
 [%- CASE 'PAYMENT'      -%]<span>Maksu</span>
 [%- CASE 'PROCESSING_FOUND' -%]<span>Kadonneen niteen käsittelykulun hyvitys</span>
 [%- CASE 'PURCHASE'     -%]<span>Osto</span>
 [%- CASE 'REFUND'       -%]<span>Hyvitys</span>
 [%- CASE 'WRITEOFF'     -%]<span>Poista</span>
 [%- CASE                -%]<span>[% credit_type.description | html %]</span>
 [%- END -%]
[%- END -%]

[%- BLOCK account_status_description -%]
 [%- SWITCH account.status -%]
 [%- CASE 'UNRETURNED' -%]<span> (Kertyvä maksu)</span>
 [%- CASE 'RETURNED'   -%]<span> (Palautettu)</span>
 [%- CASE 'REPLACED'   -%]<span> (Korvattu)</span>
 [%- CASE 'REFUNDED'   -%]<span> (Hyvitetty)</span>
 [%- CASE 'FORGIVEN'   -%]<span> (Maksun mitätöinti)</span>
 [%- CASE 'VOID'       -%]<span> (Mitätöity)</span>
 [%- CASE 'LOST'       -%]<span> (Kadonnut)</span>
 [%- CASE 'CANCELLED'  -%]<span> (Peruutettu)</span>
 [%- CASE              -%]
 [%- END -%]
[%- END -%]
