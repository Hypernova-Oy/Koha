[% USE Koha %]
[% USE raw %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="alert alert-info">
 [% IF job.status == 'finished' %]
 <table id="finishedtable">
 <tr>
 <td>Filnamn</td>
 <td>[% report.file_name | html %]</td>
 </tr>
 <tr>
 <td>Antal bearbetade rader</td>
 <td>[% report.total_rows | html %]</td>
 </tr>
 <tr>
 <td>Titlar importerade</td>
 <td>[% report.titles_imported | html %]</td>
 </tr>
 <tr>
 <td>Dubbletter hittades</td>
 <td>[% report.duplicates_found | html %]</td>
 </tr>
 <tr>
 <td>Misslyckade importer</td>
 <td>[% report.failed_imports | html %]</td>
 </tr>
 </table>
 <a href="/cgi-bin/koha/erm/eholdings/local/packages/[% report.package_id | $raw %]">Paket</a>
 [% ELSIF job.status == 'started' %]
 <p id="jobactionlabel"></p>
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
 [% CASE 'title_already_exists' %]
 <span><strong>[% m.title | html %]</strong> finns redan och kunde inte skapas.</span>
 [% CASE 'no_title_found' %]
 <span><strong>Titel [% m.title_id | html %]</strong> hade inte en publikationstitel och importerades inte.</span>
 [% CASE 'title_failed' %]
 <span><strong>Titel [% m.title_id | html %]</strong> misslyckades att importeras på grund av följande fel: [% m.error_message | html %]</span>
 [% CASE 'no_rows' %]
 <span>Inga giltiga rader hittades i filen. Kolla formateringen.</span>
 [% END %]
 </div>
 [% END %]
[% END %]


[% BLOCK js %]
 [% INCLUDE 'str/job_progress.inc' job_id=job.id %]
 [% INCLUDE 'str/import_from_kbart_file.inc' %]
<script>
        $(document).ready(function(){
            let job_id = [% job.id | html %];
            updateProgress(job_id, {
                progress_callback : function(){
                    $.getJSON('/api/v1/jobs/'+job_id, function(job){
                        if(job.progress == 0){
                            $('#jobactionlabel').text(READING_FILE);
                        }else if(job.progress >= 1){
                            $('#jobactionlabel').text(PROCESSING_FILE);
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
        });
</script>
[% END %]
