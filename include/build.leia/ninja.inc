if [[ $(which ninja) ]]; then
	WITH_BUILD="-GNinja"
	WITH_BUILD_CMD=$(which ninja)
	SHOW_CMD="ninja"
else
	WITH_BUILD_CMD=$( which cmake )
	WITH_EXTRA=" --build . -- VERBOSE=0 -s -j${NUMCPU}"
	SHOW_CMD="cmake"
fi
