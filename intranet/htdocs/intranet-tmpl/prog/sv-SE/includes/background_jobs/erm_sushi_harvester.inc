[% USE Koha %]
[% USE raw %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="alert alert-info">
 [% IF job.status == 'finished' %]
 <table id="finishedtable">
 <tr>
 <td>Hantera identitetsleverantörer</td>
 <td><a href="/cgi-bin/koha/erm/eusage/usage_data_providers/[% report.ud_provider_id | uri %]" title="Besök hanterare av användardata">[% report.ud_provider_name | html %]</a></td>
 </tr>
 <tr>
 <td>Rapporttyp</td>
 <td>[% report.report_type | html %]</td>
 </tr>
 <tr>
 <td>Rader i rapporten bearbetade</td>
 <td>[% job.progress | html %]</td>
 </tr>
 <tr>
 [% IF report.report_type.match( '^PR' ) %]
 <td>Plattformar har lagts till</td>
 [% ELSIF report.report_type.match( '^DR' ) %]
 <td>Databaser tillagda</td>
 [% ELSIF report.report_type.match( '^IR' ) %]
 <td>Tillagda exemplar</td>
 [% ELSIF report.report_type.match( '^TR' ) %]
 <td>Titlar tillagda</td>
 [% END %]
 <td>[% report.us_report_info.added_usage_objects | html %]</td>
 </tr>
 <tr>
 <td>Månadsstatistik ignoreras</td>
 <td>[% report.us_report_info.skipped_mus | html %]</td>
 </tr>
 <tr>
 <td>Månadsstatistik har lagts till</td>
 <td>[% report.us_report_info.added_mus | html %]</td>
 </tr>
 <tr>
 <td>Årsstatistik ignoreras</td>
 <td>[% report.us_report_info.skipped_yus | html %]</td>
 </tr>
 <tr>
 <td>Årsstatistik tillagd</td>
 <td>[% report.us_report_info.added_yus | html %]</td>
 </tr>
 </table>
 [% ELSIF job.status == 'started' %]
 <p id="jobactionlabel"></p>
 [% ELSIF job.status == 'failed' %]
 <table id="finishedtable">
 <tr>
 <td>Hantera identitetsleverantörer</td>
 <td><a href="/cgi-bin/koha/erm/eusage/usage_data_providers/[% report.ud_provider_id | uri %]" id="failed_provider_name" title="Besök hanterare av användardata"></a></td>
 </tr>
 <tr>
 <td>Rapporttyp</td>
 <td id="failed_report_type"></td>
 </tr>
 </table>
 [% END %]
 [% IF job.status != 'finished' %]
 [% INCLUDE "job_progress.inc" job_id=job.id %]
 [% END %]
 [% IF job.status == 'cancelled' %]
 <p>Jobbet har avbrutits innan det var klart.</p>
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
 <span><strong>[% m.title | html %]</strong> finns redan i denna dataleverantör och skapades inte. Ny användningsstatistik verifierades ändå</span>
 [% CASE 'object_added' %]
 <span><strong>[% m.title | html %]</strong> Fält har lagts till</span>
 [% CASE 'object_could_not_be_added' %]
 <span><strong>[% m.title | html %]</strong> kunde inte köras - kontrollera loggarna</span>
 [% CASE 'payload_too_large' %]
 <span>storleken på COUNTER-rapporten överskrider gränsen som definierats av databasen. Gränsen är [% m.message | html %] MB.</span><br>
 <span>Utöka begränsningen eller skörda en annan period.</span>
 [% CASE 'no_items' %]
 <span>SUSHI-svar returnerade inga exemplar.</span><br>
 <span>Vänligen försök på nytt senare.</span>
 [% CASE %]
 <span>SUSHI returnerade: [% m.message | html %] [% m.code | html %]</span>
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
