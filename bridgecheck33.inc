if getcountstep() Mod 250 == 249 then
	if universe.youngutilize < universe.middleutilize then
		if universe.youngutilize < universe.oldutilize then
			my.yy = 0.5
			if universe.middleutilize < universe.oldutilize then
				my.mm = 0.3
				my.oo = 0.2
			else 
				my.mm = 0.2
				my.oo = 0.3
			end if
		else
			my.oo = 0.5
			my.yy = 0.3
			my.mm = 0.2
		end if
	elseif universe.youngutilize > universe.middleutilize then
		if universe.youngutilize > universe.oldutilize then
			my.yy = 0.2
			if universe.middleutilize < universe.oldutilize then
				my.mm = 0.5
				my.oo = 0.3
			else
				my.mm = 0.3
				my.oo = 0.5
			end if
		else
			my.mm = 0.5
			my.yy = 0.3
			my.mm = 0.2
		end if
	end if
end if
makeoneagtsetaroundown(findbridge, 100, universe.triage.bridge, false)
universe.numberofbridge = countagtset(findbridge) 
if getcountstep() Mod 250 == 0 then
	makeoneagtsetaroundown(findbridge, 100, universe.triage.bridge, false)
	for each check in findbridge
		if check.strength == 0 then //‘Ï‹v’l‚ª0‚È‚ç“P‹‚·‚é
			killagt(check)
		else
			if check.strength < 2500 then
				//ŒoÏ‰¿’l‚ğ”»’f‚·0
				if check.value < universe.averagevalue and my.breakbridge < 450 and my.breaknumber < 30 then
					killagt(check)
					my.breakbridge = my.breakbridge + 1
					my.breaknumber = my.breaknumber + 1
				else
					// xŠú‰ñ•œ‚·‚é•âC
					if check.value < universe.averagevalue * my.criteria then
						my.cost = (250*20 - check.strength) * 2.12
						my.budget = my.budget - my.cost
						check.strength = 5000
						my.totalcost = my.totalcost + my.cost
					else
						my.cost = (250*60 - check.strength) * 2.12
						my.budget = my.budget - my.cost
						check.strength = 250*60
						my.totalcost = my.totalcost + my.cost
					end if
			 	end if 
			end if
		end if
	next check
	if my.breakbridge > gethistory(my.breakbridge, 1) then
		for iy = 0 to round(my.breaknumber * my.yy) - 1
			alten = createagt(universe.triage.altyoung)
			universe.altyoungnum = universe.altyoungnum + 1
			alten.dist = universe.utilize / universe.totalpeople
			my.cost = alten.dist * 2.12
			my.budget = my.budget - my.cost
		next iy
		for im = 0 to round(my.breaknumber * my.mm) - 1
			alten = createagt(universe.triage.altmiddle)
			universe.altmiddlenum = universe.altmiddlenum + 1
			alten.dist = universe.utilize / universe.totalpeople
			my.cost = alten.dist * 2.12
			my.budget = my.budget - my.cost
		next im
		for io = 0 to round(my.breaknumber * my.oo) - 1
			alten = createagt(universe.triage.altold)
			universe.altoldnum = universe.altoldnum + 1
			alten.dist = universe.utilize / universe.totalpeople
			my.cost = alten.dist * 2.12
			my.budget = my.budget - my.cost
		next io
	end if
end if	
if getcountstep() Mod 250 == 1 then
	my.breaknumber = 0
end if