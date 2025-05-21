[% USE Koha %]
[% USE raw %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="alert alert-info">
 [% IF job.status == 'finished' %]
 <table id="finishedtable">
 <tr>
 <td>Hallinnoi tunnistustietojen tarjoajia</td>
 <td><a href="/cgi-bin/koha/erm/eusage/usage_data_providers/[% report.ud_provider_id | uri %]" title="Käyttäjätietojen palveluntarjoaja">[% report.ud_provider_name | html %]</a></td>
 </tr>
 <tr>
 <td>Raporttityyppi</td>
 <td>[% report.report_type | html %]</td>
 </tr>
 <tr>
 <td>Raportin rivit käsitelty</td>
 <td>[% job.progress | html %]</td>
 </tr>
 <tr>
 [% IF report.report_type.match( '^PR' ) %]
 <td>Alustat lisätty</td>
 [% ELSIF report.report_type.match( '^DR' ) %]
 <td>Tietokannat lisätty</td>
 [% ELSIF report.report_type.match( '^IR' ) %]
 <td>Niteitä lisätty</td>
 [% ELSIF report.report_type.match( '^TR' ) %]
 <td>Nimekkeet lisätty</td>
 [% END %]
 <td>[% report.us_report_info.added_usage_objects | html %]</td>
 </tr>
 <tr>
 <td>Kuukausittainen käyttö ohitettu</td>
 <td>[% report.us_report_info.skipped_mus | html %]</td>
 </tr>
 <tr>
 <td>Kuukausittainen käyttömäärä lisätty</td>
 <td>[% report.us_report_info.added_mus | html %]</td>
 </tr>
 <tr>
 <td>Vuosittainen käyttö ohitettu</td>
 <td>[% report.us_report_info.skipped_yus | html %]</td>
 </tr>
 <tr>
 <td>Vuosittainen käyttö lisätty</td>
 <td>[% report.us_report_info.added_yus | html %]</td>
 </tr>
 </table>
 [% ELSIF job.status == 'started' %]
 <p id="jobactionlabel"></p>
 [% ELSIF job.status == 'failed' %]
 <table id="finishedtable">
 <tr>
 <td>Hallinnoi tunnistustietojen tarjoajia</td>
 <td><a href="/cgi-bin/koha/erm/eusage/usage_data_providers/[% report.ud_provider_id | uri %]" id="failed_provider_name" title="Käyttäjätietojen palveluntarjoaja"></a></td>
 </tr>
 <tr>
 <td>Raporttityyppi</td>
 <td id="failed_report_type"></td>
 </tr>
 </table>
 [% END %]
 [% IF job.status != 'finished' %]
 [% INCLUDE "job_progress.inc" job_id=job.id %]
 [% END %]
 [% IF job.status == 'cancelled' %]
 <p>Ajo keskeytettiin ennen kuin se valmistui.</p>
 [% END %]
 </div>
 [% END %]
[% END %]

[% Asset.js("js/job_progress.js") | $raw %]

[% BLOCK detail %]
 [% FOR m IN job.messages %]
 <div class="alert alert-info">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa fa-warning warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% SWITCH m.code %]
 [% CASE 'object_already_exists' %]
 <span><strong>[% m.title | html %]</strong> Ei luotu, koska oli jo määritelty tälle tiedontarjoajalle. Uusi käyttötilasto on kuitenkin varmennettu</span>
 [% CASE 'object_added' %]
 <span><strong>[% m.title | html %]</strong> lisättiin onnistuneesti</span>
 [% CASE 'object_could_not_be_added' %]
 <span><strong>[% m.title | html %]</strong> ei voitu käsitellä, ole hyvä ja tarkista lokitiedot</span>
 [% CASE 'payload_too_large' %]
 <span>COUNTER-raportin koko ylittää tietokannassa asetetun rajan. Raja on [% m.message | html %] Mt.</span><br>
 <span>Korota rajaa tai valitse lyhyempi aikaväli.</span>
 [% CASE 'no_items' %]
 <span>SUSHI-raportti on tyhjä.</span><br>
 <span>Yritä uudelleen erilaisella aikavälillä.</span>
 [% CASE %]
 <span>SUSHI palautti: [% m.message | html %] [% m.code | html %]</span>
 [% END %]
 </div>
 [% END %]
[% END %]
 [% Asset.js("js/job_progress.js") | $raw %]

[% BLOCK js %]
 [% INCLUDE 'str/job_progress.inc' job_id=job.id %]
 [% INCLUDE 'str/erm_sushi_harvester.inc' %]
<script>
        $(document).ready(function(){
            let job_id = [% job.id | $raw %];
            updateProgress(job_id, {
                progress_callback : function(){
                    $.getJSON('/api/v1/jobs/'+job_id, function(job){
                        if(job.progress == 0){
                            $('#jobactionlabel').text(REQUESTING_SUSHI);
                        }else if(job.progress >= 1){
                            $('#jobactionlabel').text(CREATING_COUNTER);
                        }
                    });
                },
                finish_callback : function(){
                    $.getJSON('/api/v1/jobs/'+job_id, function(job){
                        if(!$('#finishedtable').length){
                            window.location.reload();
                        }
                    });
                }
            });

            let job_data = [% job.data | $raw %];
            let report_type = job_data.report_type;
            let ud_provider_name = job_data.ud_provider_name;
            $('#failed_report_type').text(report_type);
            $('#failed_provider_name').text(ud_provider_name);
        });

</script>
[% END %]
