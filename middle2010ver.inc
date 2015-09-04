dim neighbor as agtset //一時変数の設定
dim neighbor1 as agtset
dim neighbor2 as agtset
dim neighbor3 as agtset
dim target as agt
dim target1 as agt
dim num as integer
dim one as agt
dim tempinv as integer
forward(3)
if forward(3) <> -1 then
     turn(180)
end if
if my.happy == 1 or my.happy == 2 then //家に帰る
     turn(rnd()* 20 - 10)
     makeallagtsetaroundown(neighbor, 3, false)
     num = countagtset(neighbor)
     if num >= 1 then
          target = getagt(neighbor, int(rnd() * num))
               if target.ID == my.ID and target.home == 2 then
                         my.happy = 0
               else
                    makeoneagtsetaroundown(neighbor1, 100, universe.triage.homem, false)
                    for each one in neighbor1
                         if one.ID == my.ID then
                              my.Direction = getdirection(my.X, my.Y, one.x, one.y, universe.triage)
                              forward(3)
                              if measuredistance(my.X, my.Y, one.x, one.y, universe.triage) <=  3 then
                                   my.happy = 0
                                   my.Direction = 180
                              end if
                         end if
                    next one
               end if
     end if
elseif my.happy == 0 then //家から出てくる時
	if my.labor == true then //勤労者エージェントだった場合
 		if rnd() < 0.29 then//消費地に行く
			forward(3)
			turn(rnd()* 20 - 10)
    			makeoneagtsetaroundown(neighbor2, 1, universe.triage.consumption,  false)
     			num = countagtset(neighbor2)
     			if num >= 1 then
          			target = getagt(neighbor2, int(rnd() * num))
          			my.happy = my.happy + 1
				my.money = my.money - 20578
				tempinv = norminv(rnd(), 20578, 500)
				my.consumption = my.consumption + tempinv
				my.t_consumption = my.t_consumption + tempinv
       				universe.hapsum = universe.hapsum + my.happy
     			end if
  		elseif rnd() > 0.29 or my.money <= 45000 then //オフィスに働きに行く
			forward(3)
			turn(rnd()* 20 - 10)
     			makeoneagtsetaroundown(neighbor3, 1, universe.triage.office,  false)
     			num = countagtset(neighbor3)
     			if num >= 1 then
          			target = getagt(neighbor3, int(rnd() * num))
         			my.happy = my.happy + 2
				my.money = my.money + 35711
				tempinv = norminv(rnd(), 35711, 500)
				my.salary = my.salary + tempinv
				my.free = my.free + (13 - target.laborhour1) * 2572
				my.t_free = my.t_free + (13 - target.laborhour1) * 2572
          			universe.hapsum = universe.hapsum + my.happy
			end if
     		end if
	else //勤労者エージェントでない場合
		if rnd() < 0.58 then//消費地に行く
			forward(3)
			turn(rnd()* 20 - 10)
    			makeoneagtsetaroundown(neighbor2, 1, universe.triage.consumption,  false)
     			num = countagtset(neighbor2)
     			if num >= 1 then
          			target = getagt(neighbor2, int(rnd() * num))
          			my.happy = my.happy + 1
				my.money = my.money - 7338
				tempinv = norminv(rnd(), 7338, 500)
				my.consumption = my.consumption + tempinv
				my.t_consumption = my.t_consumption + tempinv
       				universe.hapsum = universe.hapsum + my.happy
     			end if
  		elseif rnd() > 0.58 or my.money <= 15000 then //オフィスに働きに行く
			forward(3)
			turn(rnd()* 20 - 10)
     			makeoneagtsetaroundown(neighbor3, 1, universe.triage.office,  false)
     			num = countagtset(neighbor3)
     			if num >= 1 then
          			target = getagt(neighbor3, int(rnd() * num))
         			my.happy = my.happy + 2
				my.money = my.money + 10000
				tempinv = norminv(rnd(), 10000, 500)
				my.salary = my.salary + tempinv
				my.free = my.free + (9 - target.laborhour2) * 917
				my.t_free = my.t_free + (9 - target.laborhour2) * 917
          			universe.hapsum = universe.hapsum + my.happy
			end if
     		end if
	end if
end if
my.utilize = my.consumption^(1/2) * my.free^(1/2)
my.t_utilize = my.t_consumption^(1/2) * my.t_free^(1/2)
universe.utilize = universe.utilize + my.utilize
universe.middleutilize = universe.middleutilize + my.t_utilize / 123
universe.t_utilize= universe.t_utilize + my.t_utilize
if getcountstep() Mod 250 == 2 then
	my.t_consumption = 0
	my.t_free = 0
end if