//1step���̔�J�x�����p�ɔ��f������
if my.utilize > 0 then
	my.utilize = my.utilize - 1
end if
if my.t_utilize > 0 then
	my.t_utilize = my.t_utilize - 1
end if
//�߂��ɕʂ̐l�X�G�[�W�F���g������ꍇ�A���p�͌�������
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