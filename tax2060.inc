
//徴税シークエンス
makeoneagtsetaroundown(y, 100,  universe.triage.young, false)
makeoneagtsetaroundown(m, 100, universe.triage.middle, false)
makeoneagtsetaroundown(o, 100, universe.triage.old, false)
mergeagtset(human,y)
mergeagtset(human,m)
mergeagtset(human,o)
if getcountstep() Mod 250 == 0 then
	for each one in human
		if one.salary < 22282 then
			one.consumption = one.consumption - 5 * ( one.salary*0.05 )^0.88
			my.budget = my.budget + one.salary*0.05
			one.salary = 0
		elseif one.salary < 37709 then
			one.consumption = one.consumption - 5 * ( one.salary*0.1 - 1114 )^0.88
			my.budget = my.budget + one.salary*0.1
			one.salary = 0
		elseif one.salary < 79418 then
			one.consumption = one.consumption - 5 * ( one.salary*0.2 - 4885 )^0.88
			my.budget = my.budget + one.salary*0.2
			one.salary = 0
		elseif one.salary < 102843 then
			one.consumption = one.consumption - 5 * ( one.salary*0.23 - 7267 )^0.88
			my.budget = my.budget + one.salary*0.23
			one.salary = 0
		elseif one.salary < 205686 then
			one.consumption = one.consumption - 5 * ( one.salary*0.33 - 17551 )^0.88
			my.budget = my.budget + one.salary*0.33
			one.salary = 0
		else
			one.consumption = one.consumption - 5 * ( one.salary*0.4 - 31949 )^0.88
			my.budget = my.budget + one.salary*0.4
			one.salary = 0
		end if
	next one
end if