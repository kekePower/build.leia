# Example script extension
# To see it in action, run "build.leia --with=example"

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

# You can also direct output of the commands you run in your extension
# directly to the log-file
echo "This is a command from the example extension" >> ${LOGGYLOGFILE} 2>&1 # I know the variable name sucks...

module_exit ${1}
