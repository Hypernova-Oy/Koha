<div class="modal" id="chartModal" tabindex="-1" role="dialog" aria-labelledby="chartModalLabel">
 <div class="modal-dialog modal-xl">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="chartModalLabel">Inställningar för diagram</h1>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body" id="makechart">
 [% supposed_x = header_row.shift.cell %]
 <fieldset class="rows">
 <ol>
 <li>
 <label for="chart-type">Diagramtyp: </label>
 <select name="chart-type" id="chart-type">
 <option value="pie">Tårtdiagram</option>
 <option value="bar">Stapeldiagram</option>
 <option value="line">Rad</option>
 </select>
 </li>

 <li id="chart-column-horizontal">
 <label for="horizontal">Horisontell stapel:</label>
 <input id="horizontal" name="column-horizontal" type="checkbox" />
 </li>

 <li>
 <label for="x_element">kolumn x:</label>
 <select id="x_element" name="x">
 <option value="[% supposed_x | html %]" selected>[% supposed_x | html %]</option>
 [% FOREACH header IN header_row %]
 <option value="[% header.cell | html %]">[% header.cell | html %]</option>
 [% END %]
 </select>
 </li>

 [% IF allresults.size %]
 <li>
 <label for="include-all">Inkludera alla rader (ignorera sidnumrering):</label>
 <input id="include-all" name="chart-include-all" type="checkbox" checked="checked"/>
 </li>
 [% ELSE %]
 <li>
 <p>Diagrammet utgår bara från synliga rader. Klicka på 'Hämta all data' om du vill att hela rapporten ska användas</p>
 </li>
 [% END %]

 <li>
 <label for="exclude-last">Uteslut sista raden (Uppdatering): </label>
 <input id="exclude-last" name="chart-exclude-last" type="checkbox" />
 </li>
 [% column = 1 %]
 <li class="column_config_row">
 [% FOREACH header IN header_row %]
 <fieldset class="chart-column-conf" id="column_[% column | html %]">
 <legend>
 Kolumn [% column | html %] <a class="chart-column-delete" href="#" data-column="[% column | html %]">
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
 <label for="group_[% column | html %]">Grupp:</label>
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
 <label for="line_[% column | html %]">Rad:</label>
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
 <button id="draw-chart" class="btn btn-default">Rita</button>
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Stäng</button>
 </div>
 </div>
 </div>
</div>
