[% USE Koha %]
[% USE raw %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="alert alert-info">
 [% IF job.status == 'finished' %]
 <table id="finishedtable">
 <tr>
 <td>Tiedoston nimi</td>
 <td>[% report.file_name | html %]</td>
 </tr>
 <tr>
 <td>Yhteensä rivejä käsitelty</td>
 <td>[% report.total_rows | html %]</td>
 </tr>
 <tr>
 <td>Nimekkeet tuotu</td>
 <td>[% report.titles_imported | html %]</td>
 </tr>
 <tr>
 <td>Löytyi tuplia</td>
 <td>[% report.duplicates_found | html %]</td>
 </tr>
 <tr>
 <td>Epäonnistuneet tuonnit</td>
 <td>[% report.failed_imports | html %]</td>
 </tr>
 </table>
 <a href="/cgi-bin/koha/erm/eholdings/local/packages/[% report.package_id | $raw %]">Paketti</a>
 [% ELSIF job.status == 'started' %]
 <p id="jobactionlabel"></p>
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
 [% CASE 'title_already_exists' %]
 <span><strong>[% m.title | html %]</strong> on jo olemassa eikä sitä luotu.</span>
 [% CASE 'no_title_found' %]
 <span><strong>Nimeke [% m.title_id | html %]</strong> julkaisun nimekettä ei ollut, eikä sitä tuotu.</span>
 [% CASE 'title_failed' %]
 <span><strong>Nimeke [% m.title_id | html %]</strong> tuonti epäonnistui virheellä: [% m.error_message | html %]</span>
 [% CASE 'no_rows' %]
 <span>Tässä tiedostossa ei löytynyt kelvollisia rivejä. Tarkista tiedoston muotoilu.</span>
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
