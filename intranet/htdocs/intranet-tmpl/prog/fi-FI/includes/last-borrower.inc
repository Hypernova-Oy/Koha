<script>
   var showLastPatronCount = "[% Koha.Preference('showLastPatronCount') | html %]";
</script>
<div id="lastborrower-window">
 <div class="btn-group">
 <a class="btn btn-link navbar-btn lastborrower" id="lastborrowerlink" href="#" title=""><i class="fa fa-arrow-right"></i> Viimeisin asiakas</a>
 <button type="button" class="btn btn-link navbar-btn dropdown-toggle dropdown-toggle-split" data-bs-toggle="dropdown" aria-expanded="false">
 <span class="visually-hidden">Avattava pudotusvalikko</span>
 </button>
 <ul id="lastBorrowerList" class="dropdown-menu dropdown-menu-end">
 <li><hr class="dropdown-divider"></li>
 <li><a id="lastborrower-remove" class="lastborrower dropdown-item" href="#">Tyhjennä lista</a></li>
 </ul>
 </div>
</div>
