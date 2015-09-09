dim alt1 as agtset
dim alt2 as agtset
dim alt3 as agtset
dim alt1num as integer
dim alt2num as integer
dim alt3num as integer
if my.age == 1 then
	makeoneagtsetaroundown(alt1, 100, universe.triage.altyoung, false)
	alt1num = countagtset(alt1)
	my.utilize = my.utilize + universe.youngdist^(1/2)
	my.t_utilize = my.t_utilize + universe.youngdist^(1/2)
elseif my.age == 2 then
	makeoneagtsetaroundown(alt2, 100, universe.triage.altmiddle, false)
	alt2num = countagtset(alt2)
	my.utilize = my.utilize + universe.middledist^(1/2)
	my.t_utilize = my.t_utilize + universe.middledist^(1/2)
elseif my.age == 3 then
	makeoneagtsetaroundown(alt3, 100, universe.triage.altold, false)
	alt3num = countagtset(alt3)
	my.utilize = my.utilize + universe.olddist^(1/2)
	my.t_utilize = my.t_utilize + universe.olddist^(1/2)
end if
	
	