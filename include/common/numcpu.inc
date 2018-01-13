# Find the number of available cores and return variable NUMCPU
# You can use this i.e. to "make -j${NUMCPU}"

NUMCPU=$(getconf _NPROCESSORS_ONLN)
