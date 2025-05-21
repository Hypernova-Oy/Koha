<div class="modal" id="chartModal" tabindex="-1" role="dialog" aria-labelledby="chartModalLabel">
 <div class="modal-dialog modal-xl">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="chartModalLabel">Kaavion asetukset</h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body" id="makechart">
 [% supposed_x = header_row.shift.cell %]
 <fieldset class="rows">
 <ol>
 <li>
 <label for="chart-type">Kaavion tyyppi: </label>
 <select name="chart-type" id="chart-type">
 <option value="pie">Ympyräkaavio</option>
 <option value="bar">Palkki</option>
 <option value="line">Rivi</option>
 </select>
 </li>

 <li id="chart-column-horizontal">
 <label for="horizontal">Vaakapalkki:</label>
 <input id="horizontal" name="column-horizontal" type="checkbox" />
 </li>

 <li>
 <label for="x_element">x-sarake:</label>
 <select id="x_element" name="x">
 <option value="[% supposed_x | html %]" selected>[% supposed_x | html %]</option>
 [% FOREACH header IN header_row %]
 <option value="[% header.cell | html %]">[% header.cell | html %]</option>
 [% END %]
 </select>
 </li>

 [% IF allresults.size %]
 <li>
 <label for="include-all">Sisällytä kaikki rivit (älä huomioi sivutusta):</label>
 <input id="include-all" name="chart-include-all" type="checkbox" checked="checked"/>
 </li>
 [% ELSE %]
 <li>
 <p>Tämä kaavio käyttää vain näkyviä rivejä. Hae kaikki tiedot kaavioon valitsemalla 'Nouda kaikki tiedot'</p>
 </li>
 [% END %]

 <li>
 <label for="exclude-last">Jätä pois viimeinen rivi (yhteenveto): </label>
 <input id="exclude-last" name="chart-exclude-last" type="checkbox" />
 </li>
 [% column = 1 %]
 <li class="column_config_row">
 [% FOREACH header IN header_row %]
 <fieldset class="chart-column-conf" id="column_[% column | html %]">
 <legend>
 Sarake [% column | html %] <a class="chart-column-delete" href="#" data-column="[% column | html %]">
 <i class="fa fa-times error"></i>
 </a>
 </legend>
 <div>
 <label for="y_[% column | html %]" >y:</label>
 <select id="y_[% column | html %]" name="y">
 <option value="[% supposed_x | html %]" selected>[% supposed_x | html %]</option>
 [% FOREACH h IN header_row %]
 [% IF header.cell == h.cell %]
 <option value="[% h.cell | html %]" selected>[% h.cell | html %]</option>
 [% ELSE %]
 <option value="[% h.cell | html %]">[% h.cell | html %]</option>
 [% END %]
 [% END %]
 </select>
 </div>

 <div class="chart-column-group">
 [% i = 1 %]
 <label for="group_[% column | html %]">Ryhmä:</label>
 <select id="group_[% column | html %]" name="group">
 [% FOREACH h IN header_row %]
 [% IF i == column %]
 <option value="[% i | html %]" selected>[% i | html %]</option>
 [% ELSE %]
 <option value="[% i | html %]">[% i | html %]</option>
 [% END %]
 [% i = i + 1 %]
 [% END %]
 </select>
 </div>

 <div class="chart-column-line">
 <label for="line_[% column | html %]">Rivi:</label>
 <input class="column-line" id="line_[% column | html %]" name="[% header.cell | html %]" type="checkbox" />
 </div>
 </fieldset>
 [% column = column + 1 %]
 [% END %]
 </li>
 </ol>
 </fieldset>

 [% item = { cell = supposed_x } %]
 [% header_row.unshift(item) | html %]
 </div>
 <div class="modal-footer">
 <button id="draw-chart" class="btn btn-default">Piirrä</button>
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Sulje</button>
 </div>
 </div>
 </div>
</div>
