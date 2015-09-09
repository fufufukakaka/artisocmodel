makeoneagtsetaroundown(findbridge, 100, universe.triage.bridge, false)

//‹´‚ÌƒRƒA‚ğ”‚¦‚é
for each check in findbridge
		if check.bridgecore == 1 then //‘Ï‹v’l‚ª0‚È‚ç“P‹‚·‚é
			universe.numberbridge = universe.numberofbridge + 1
            AddAgt(My.findcore,check)//ƒRƒA‚ğ”F¯‚·‚é
        end if
next check
//‹´‚ğ“_ŒŸ‚·‚é
if getcountstep() Mod 250 == 0 then
	for each check in My.findcore
		if check.strength == 0 then //‘Ï‹v’l‚ª0‚È‚ç“P‹‚·‚é
			killagt(check)
		else
			if check.strength < 500 then
				//ŒoÏ‰¿’l‚ğ”»’f‚·‚é
				if check.value < universe.averagevalue  then
					killagt(check)
					my.breakbridge = my.breakbridge + 1
				else
					// xŠú‰ñ•œ‚·‚é•âC
					my.cost = (250*20 - check.strength) * 2.12
					my.budget = my.budget - my.cost
					check.strength = 250*20
					my.totalcost = my.totalcost + my.cost
			 	end if 
			end if
		end if
	next check
	if my.breakbridge > gethistory(my.breakbridge, 250) then
		buildnum = my.breakbridge - gethistory(my.breakbridge, 250)
		if universe.youngutilize < universe.middleutilize and universe.youngutilize < universe.oldutilize then
			for iy = 0 to norminv(rnd(), buildnum, 1) - 1
				alten = createagt(universe.triage.altyoung)
				universe.altyoungnum = universe.altyoungnum + 1
				alten.dist = universe.utilize / 300
				my.cost = alten.dist * 2.12
				my.budget = my.budget - my.cost
			next iy
		elseif universe.middleutilize < universe.youngutilize and universe.middleutilize < universe.oldutilize then
			for im = 0 to norminv(rnd(), buildnum, 1) - 1
				alten = createagt(universe.triage.altmiddle)
				universe.altmiddlenum = universe.altmiddlenum + 1
				alten.dist = universe.utilize / 300
				my.cost = alten.dist * 2.12
				my.budget = my.budget - my.cost
			next im
		elseif universe.oldutilize < universe.youngutilize and universe.oldutilize < universe.middleutilize then
			for io = 0 to norminv(rnd(), buildnum, 1) - 1
				alten = createagt(universe.triage.altold)
				universe.altoldnum = universe.altoldnum + 1
				alten.dist = universe.utilize / 300
				my.cost = alten.dist * 2.12
				my.budget = my.budget - my.cost
			next io
		end if
	end if
end if
		