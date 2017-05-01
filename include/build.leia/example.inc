# Example script extension

# Set this variable to true
# It makes sure that the rest of the script is not executed.
STANDALONE=true

MSG="This is an example message."
echo "${TIME}[$(date +%T)]${END} ${INFO}${MSG} (INFO)${END}"
echo "${TIME}[$(date +%T)]${END} ${WARNING}${MSG} (WARNING)${END}"
echo "${TIME}[$(date +%T)]${END} ${W}${MSG} (W)${END}"
echo "${TIME}[$(date +%T)]${END} ${OTHER}${MSG} (OTHER)${END}"
echo "${TIME}[$(date +%T)]${END} ${TIME}${MSG} (TIME)${END}"
echo "${TIME}[$(date +%T)]${END} ${ARROW} ${INFO}${MSG} (ARROW,INFO)${END}"

# You can use the loggy function to add info to the log file
loggy ${MSG}

clean_exit ${1}
