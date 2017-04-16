# How to write your own extension

It's really simple.

Add your script to **~/bin/include/build.leia/** and name it **extension.inc**.

Within this script, you can write anything you want it to do. Be it to compile Krypton or whatever, really.

What you have to add at the end, always, is

**`rm -f /tmp/.build.leia.pid`**

**`exit`**

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

That's all for now.
