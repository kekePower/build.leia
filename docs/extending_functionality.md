# How to write your own extension

It's really simple.

Add your script to **~/bin/include/build.leia/** and name it **extension.inc** or whatever you want to call your creation.

Within this script, you can write anything you want it to do. Be it to compile Krypton or whatever, really.

You can, and should, add a small description at the top.

**`# This extension will make coffee`**

The second line should be

**`STANDALONE=true`**

This makes sure that build.leia doesn't continue when your script has done its magic.

What you have to add at the end, always, is

**`module_exit ${1}`**

You can use **module_exit ${1}** every time you want to exit for any reason and at any time.

The first line deletes the pid file created at the beginning of the script and this has to be done before exiting.

The second line exits the script before it can run anything else. This is important since the script contains a lot of functons and it will run if not stopped and will produce unexpected results.

## You've written your extension, now what?

Easy. Just run **build.leia --with=extension**

## See example

You can view the **example.inc** file for a simple example. All it does is echo an example line.

But it also contains the two lines mentioned above.

## Formatting of the messages

This script includes the use of colors for messages and it also include themes.

For example `${TIME}[$(date +%T)]${END} ${INFO}${MSG}${END}` picks up the color for TIME for the timestamp. INFO is the color for the message. END is used to stop the use of the color and has to be set before you can use any other color in the same message.

Colors defined are
* INFO
* WARNING
* W
* OTHER
* Y
* TIME
* ARROW

## Logging

I've written a simple logger function called **loggy**. All it does is echo the text to the pre-defined log.

The format is:

`loggy ${MSG}`

In the main script, I also log the output of almost every command.

`make -s -j${NUMCPU} >> ${LOGGYLOGFILE} 2>&1`

Doing this enables me to check the log file if something happens and I can then correct the error and try again.

`${NUMCPU}` checks the system for the number of cores and/or threads available and uses that number to compile. Use it to speed up compilation.

## Putting it all together

This is the example extension I've made that showcases some of the functionality of **build.leia**.

```# Example script extension
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

module_exit ${1}```

That's all for now.
