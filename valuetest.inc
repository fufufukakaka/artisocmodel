//bridge‚ª©•ª‚Ì‚Á‚Ä‚¢‚éŒoÏ‰¿’l‚ğ”»’f‚·‚é‚½‚ß‚ÌŒvZ®
my.value = my.value
		+ my.younglabor *  (14070 * 0.29 + 25667 * 0.71)
		+ my.youngcon * (7338 * 0.58 + 6000 * 0.42) 
		+ my.middlelabor * (20578 * 0.29 + 35711 * 0.71)
		+ my.middlecon * (7338 * 0.58 + 6000 * 0.42)
		+ my.oldlabor * (17459 * 0.29 + 24358 * 0.71)
		+ my.oldcon * (7338 * 0.58 + 6000 * 0.42)
my.t_value = my.t_value
		+ my.t_younglabor *  (14070 * 0.29 + 25667 * 0.71)
		+ my.t_youngcon * (7338 * 0.58 + 6000 * 0.42) 
		+ my.t_middlelabor * (20578 * 0.29 + 35711 * 0.71)
		+ my.t_middlecon * (7338 * 0.58 + 6000 * 0.42)
		+ my.t_oldlabor * (17459 * 0.29 + 24358 * 0.71)
		+ my.t_oldcon * (7338 * 0.58 + 6000 * 0.42)
my.totalvalue = my.totalvalue + my.value
universe.totalvalue = universe.totalvalue + my.value
if getcountstep() Mod 250 == 3 then
	my.t_value = 0
	my.t_younglabor = 0
	my.t_youngcon = 0
	my.t_middlelabor = 0
	my.t_middlecon = 0
	my.t_oldlabor = 0
	my.t_oldcon = 0
end if