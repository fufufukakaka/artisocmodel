
//徴税シークエンス
makeoneagtsetaroundown(y, 100,  universe.triage.young, false)
makeoneagtsetaroundown(m, 100, universe.triage.middle, false)
makeoneagtsetaroundown(o, 100, universe.triage.old, false)
mergeagtset(human,y)
mergeagtset(human,m)
mergeagtset(human,o)
if getcountstep() Mod 250 == 0 then
	for each one in human
		if one.salary < 24551 then
			one.consumption = one.consumption - 5 * ( one.salary*0.05 )^0.88
			my.budget = my.budget + one.salary*0.05
			one.salary = 0
		elseif one.salary < 41548 then
			one.consumption = one.consumption - 5 * ( one.salary*0.1 - 1227 )^0.88
			my.budget = my.budget + one.salary*0.1
			one.salary = 0
		elseif one.salary < 87504 then
			one.consumption = one.consumption - 5 * ( one.salary*0.2 - 5382 )^0.88
			my.budget = my.budget + one.salary*0.2
			one.salary = 0
		elseif one.salary < 113314 then
			one.consumption = one.consumption - 5 * ( one.salary*0.23 - 8007 )^0.88
			my.budget = my.budget + one.salary*0.23
			one.salary = 0
		elseif one.salary < 226629 then
			one.consumption = one.consumption - 5 * ( one.salary*0.33 - 19339 )^0.88
			my.budget = my.budget + one.salary*0.33
			one.salary = 0
		else
			one.consumption = one.consumption - 5 * ( one.salary*0.4 - 35202 )^0.88
			my.budget = my.budget + one.salary*0.4
			one.salary = 0
		end if
	next one
end if