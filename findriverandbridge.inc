dim destin as double
dim bridgetarget as agt
dim bridgetarget1 as agt
dim findriver1 as agtset
dim findriver2 as agtset
dim nob1 as integer
dim nob2 as integer
destin = my.Direction
nob1 = 0
if watchahead(1, 1, universe.triage.river) > 0 then
	turn(180)
	forward(3)
	my.Direction = destin
	if watchahead(1, 3, universe.triage.bridge) > 0 then
		makeoneagtsetaroundown(findriver1, 5, universe.triage.bridge, false)
		nob1 = countagtset(findriver1)
		if nob1 > 0 then
		bridgetarget = getagt(findriver1, int(rnd() * nob1))
		my.Direction = getdirection(my.X, my.Y, bridgetarget.x, bridgetarget.y, universe.triage)
		forward(3)
		end if
	else
		turn(180)
		forward(3)
	end if
else
	if watchahead(1, 1, universe.triage.bridge) > 0 then
		if my.X > 48 then
			my.Direction= 180
			forward(5)
			makeoneagtsetaroundown(findriver2, 5, universe.triage.bridge, false)
			nob2 = countagtset(findriver2)
			if nob1 > 0 then
				bridgetarget1 = getagt(findriver2, int(rnd() * nob1))
				bridgetarget1.people = bridgetarget1.people + 1
				bridgetarget1.strength = bridgetarget1.strength - 1
				//年齢・勤労者かどうかのカウントを行う
				if my.age == 1 then
					if my.labor == true then
						bridgetarget1.younglabor = bridgetarget1.younglabor + 1
						universe.younglabor = universe.younglabor + 1
					elseif my.labor == false then
						bridgetarget1.youngcon = bridgetarget1.youngcon + 1
						universe.youngcon = universe.youngcon + 1
					end if
				elseif my.age == 2 then
					if my.labor == true then
						bridgetarget1.middlelabor = bridgetarget1.middlelabor + 1
						universe.middlelabor = universe.middlelabor + 1
					elseif my.labor == false then
						bridgetarget1.middlecon = bridgetarget1.middlecon + 1
						universe.middlecon = universe.middlecon + 1
					end if
				elseif my.age == 3 then
					if my.labor == true then
						bridgetarget1.oldlabor = bridgetarget1.oldlabor + 1
						universe.oldlabor = universe.oldlabor + 1
					elseif my.labor == false then
						bridgetarget1.oldcon = bridgetarget1.oldcon + 1
						universe.oldcon = universe.oldcon + 1
					end if
				end if
			end if
		elseif my.X < 42 then
			my.Direction = 0
			forward(5)
			makeoneagtsetaroundown(findriver1, 5, universe.triage.bridge, false)
			nob1 = countagtset(findriver1)
			if nob1 > 0 then
				bridgetarget = getagt(findriver1, int(rnd() * nob1))
				bridgetarget.people = bridgetarget.people + 1
				bridgetarget.strength = bridgetarget.strength - 1
				//年齢・勤労者かどうかのカウントを行う
				if my.age == 1 then
					if my.labor == true then
						bridgetarget.younglabor = bridgetarget.younglabor + 1
						universe.younglabor = universe.younglabor + 1
					elseif my.labor == false then
						bridgetarget.youngcon = bridgetarget.youngcon + 1
						universe.youngcon = universe.youngcon + 1
					end if
				elseif my.age == 2 then
					if my.labor == true then
						bridgetarget.middlelabor = bridgetarget.middlelabor + 1
						universe.middlelabor = universe.middlelabor + 1
					elseif my.labor == false then
						bridgetarget.middlecon = bridgetarget.middlecon + 1
						universe.middlecon = universe.middlecon + 1
					end if
				elseif my.age == 3 then
					if my.labor == true then
						bridgetarget.oldlabor = bridgetarget.oldlabor + 1
						universe.oldlabor = universe.oldlabor + 1
					elseif my.labor == false then
						bridgetarget.oldcon = bridgetarget.oldcon + 1
						universe.oldcon = universe.oldcon + 1
					end if
				end if
			end if
		end if
	else
		forward(3)
	end if
end if