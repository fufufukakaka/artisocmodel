//1step毎の疲労度を効用に反映させる
if my.utilize > 0 then
	my.utilize = my.utilize - 1
end if
if my.t_utilize > 0 then
	my.t_utilize = my.t_utilize - 1
end if
//近くに別の人々エージェントがいる場合、効用は減少する
dim people as agtset
dim people1 as agtset
if my.utilize > 0 then
	makeagtset(people, universe.triage.young)
	makeagtset(people, universe.triage.middle)
	makeagtset(people, universe.triage.old)
	makeagtsetaroundowncell(people, 3, people1, false)
	if countagtset(people1) > 0 then
		my.utilize = my.utilize - countagtset(people1)
	end if
end if
if my.t_utilize > 0 then
	makeagtset(people, universe.triage.young)
	makeagtset(people, universe.triage.middle)
	makeagtset(people, universe.triage.old)
	makeagtsetaroundowncell(people, 3, people1, false)
	if countagtset(people1) > 0 then
		my.t_utilize = my.t_utilize - countagtset(people1)
	end if
end if