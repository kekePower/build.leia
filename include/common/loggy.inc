# Function: LOGGER
# Usage: loggy <message>
function loggy () {
  
	echo "$$ - $(date +%T) - ${KODIVERSION} - ${@}" >> ${LOGGYLOGFILE}

}
