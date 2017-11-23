# build.leia - A shell script to build Kodi 18 Leia from source

## Description
This is a complete hack to fetch(clone), update(pull), compile and install [Kodi](https://github.com/xbmc/xbmc) from source on Linux.

I wrote this script to automate the compilation of Kodi on my Linux system. It checks if you have the source, if you don't it will ask if you want to download it. Then it asks if you want to compile and install the binary-addons.

Kodi 18 Leia uses cmake and checks for installled libraries automatically without the need to specify them during configuration. Compared to configuring Kodi Krypton v17, it's a lot easier and feels more bullet proof.

Also, the introduction to using ccache speeds up build times after the first compilation. I've introduced an option that will disable ccache if you want to compile Kodi with a sort of clean slate (for a lack of words...).

It uses the Z Shell (ZSH) as I find it more than capable for my needs.

The script also uses **sudo** to install Kodi and the binary-addons. Please make sure you are in the **sudoers** list.

Default installation dir is **/opt/leia**. This can be changed by editing the PREFIX variable in **build.leia**.

See **build.leia --help** for your options.

### Requirements

* Standard requirements for building [Kodi on Linux](https://github.com/xbmc/xbmc/blob/master/docs/README.linux)
* [ZSH](http://www.zsh.org/)
* [git](https://github.com/git/git)
* You must be in the sudoers file
	* Unless you want to install Kodi to your home directory. Then you'll have to edit the PREFIX setting and remove the sudo commands from the script.

## Getting the source

If you want to be on the cutting-edge, you can download the **master** branch. This will have a lot of bugs until the next major version is released.

To get the latest, stable version, please use the **v1.x** branch.

**`git clone -b v1.x https://github.com/kekePower/build.leia`**

## Options

### Fresh start

The script will first check to see if you have the Kodi Leia source in the directory specified in **etc/build.leia.conf**. If it's not there, it will ask you if you want it to clone the source from Github.

It will then ask you if you also want to compile the binary-addons later.

### Major hack is now included

I've created a patch that lets you define your own, personalized string in the System information screen.

The build.leia.conf now includes "MY_GIT_VERSION" that gives you the option to make this screen look like

**Kodi 18.0-ALPHA1 by kekePower**

Or, if you edit build.leia.conf, your own string.

![System Information](https://github.com/kekePower/build.leia/blob/v1.x/docs/system-info.png)

### You can now use Ninja and optimise the build for your CPU

There is a new option to use [Ninja](https://ninja-build.org/) to build Kodi for you. The script will check if you have Ninja installed
and if not, will fall back to using cmake. See [this PR](https://github.com/xbmc/xbmc/pull/12936).

You have to check the differences in your current **build.leia.conf** towards the new one. There is a new entry called
**USE_NINJA=true** or **false**. Set this to your preference.

I've also added the possibility to optimise the build of Kodi for your CPU. See [the table](https://github.com/graysky2/kernel_gcc_patch/blob/master/README.md) on this page
and use **MY_CPU_ARCH=<YourArch>**. The default is **native**, which normally is good enough.

### Command line options

**build.leia** - The default is the same as **build.leia --with=clean,addons**

**build.leia --help** will show you a few examples of use

**build.leia --with=** - This is where the magic happens.

Your options are:

**--with=clean** - This will remove the **build-kodi** directory and recreate it.

**--with=dirty** - This will simply pull the updated source and compile as is.

**--with=addons** - This will clean and compile the binary-addons.

**--with=no-git** - This will skip pulling for updates from Github and just carry on with the compilation. This can be used if one compilation has failed after an update and you want to run it again.

**--with=force** - This will compile Kodi even if there are no new updates from Github.

**--with=no-ccache** - Disable ccache when configuring Kodi

**--with=only-addons** - Will clean and compile and install the binary-addons only

**--with=nn** - Will disable the two questions about clearing ccache and deleting PREFIX. This also defaults to include **--with=clean,addons**.
You can now use the combination **--with=clean,nn** which will skip the previous assumption. It became a neccesity for me and hopefully you'll like it too.

You can use any of these options together, except from **clean** and **dirty**.

**build.leia --with=clean,addons,force** will remove the **kodi-build** directory, recreate it, check to see if there are updates from Github and even if there are no new updates, it will continue with the compilation and lastly it will do a **distclean** for the binary-addons and re-compile them.

## Troubleshooting

Sometimes the configuration or compilation failes. If this happens, you can try the following suggestions.

Please cd into your Leia source code: **cd ${HOME}/kodi/Leia/kodi-build** and run the following command: **cmake ..**

You will see the complete output of the command and possibly find you're missing some libraries and/or tools necessary to compile Kodi. Install the missing libraries and/or tools and try again. Once you've sorted all this out, you're ready to run the script.

If you experience compilation issues, a good idea is to delete the source tree and let the script download a fresh copy.

## Translations

I only know two languages, Norwegian and English, and therefore there are only these two availale.

If you want to help out with translation, please fork the project and copy the language files from **include/build.leia/language/**.

The **en_US.inc** is the most up-to-date file.

## The road ahead

I've a lot of thoughts about how to make this script even more robust. At the moment they're basically just a mess in my head, but I'll try to plot them down in a coherent way.

* I'd like to see a way for the script to check for known dependencies
	* If some are missing, download them (git?), compile and install them
	* The main problem here is that we can't really catch missing dependecies of these unless we go through all of them manually and set up some sort of order
* ~~Make the installer more robust when it comes to updating.~~
	~~* Sometimes there are changes to the config file and I'd like to keep the local changes while updating with the new settings without adding in the REMOVEME string.~~
* ~~Move the hardcoded text from build.leia into the language files~~
* ~~Perhaps make an option (GLOBAL_INSTALL?) that en/disables the use of sudo~~
* More to come...

## Extensions

I've written two extension that are not included in the tar-ball.

You can download them at [my gist page](https://gist.github.com/kekePower)

## Screenshots

![build.leia Help](https://dl.dropboxusercontent.com/u/15356427/build.leia.help.png)
![build.leia Compile with progress](https://dl.dropboxusercontent.com/u/15356427/build.leia-progress.png)
![build.leia Compile Finished](https://dl.dropboxusercontent.com/u/15356427/build.leia.finished.png)
