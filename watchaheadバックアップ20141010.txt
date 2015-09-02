function watchahead(dist as double, range as double, type as agttype) as integer {
dim findriver as agtset
dim nob as integer
forward(dist)
makeoneagtsetaroundown(findriver, range, type, false)
nob = countagtset(findriver)
forward(-dist)
return(nob)