# Example script extension

MSG="This is an example message."
echo "${TIME}[$(date +%T)]${END} ${INFO}${MSG}${END}"

# You can use the loggy function to add info to the log file
loggy ${MSG}

# Now remove the pid file
rm -f /tmp/.build.leia.pid > /dev/null 2>&1

# and exit
exit
