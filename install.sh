#!/bin/env zsh

echo "Do you want to install build.leia to ${HOME}/bin/? (Y/n) \c"
read answer

if [[ ${answer} == "" || ${answer} == "Y" || ${answer} == "y" ]]; then

	if [[ ! -d ${HOME}/bin ]]; then
		echo "${HOME}/bin doesn't exist. Creating it now."
		mkdir ${HOME}/bin
	fi

	echo "Copying files to ${HOME}/bin/"
	install -Dm 0750 build.leia ${HOME}/bin/build.leia

	if [[ ! -d ${HOME}/bin/etc ]]; then
		cp -af etc ${HOME}/bin/
	fi

	if [[ $( cat ${HOME}/bin/etc/build.leia.conf | head -1 ) != $( cat etc/build.leia.conf.sample | head -1 ) ]]; then
		echo "Please review ${HOME}/bin/etc/build.leia.conf.sample for changes and/or updates"
		install -Dm 0600 etc/build.leia.conf.sample ${HOME}/bin/etc/build.leia.conf.sample
	fi

	cp -af include ${HOME}/bin/

	echo "build.leia is installed."
	echo "Please edit ${HOME}/bin/etc/build.leia.conf.sample before running the script."
	echo "Rename it to build.leia.conf when you're done editing it."
	echo "You can also edit ${HOME}/bin/include/extra/VERSION unless you want"
	echo "\"Kodi <version> by kekePower\" in the System information screen."
	echo "If ${HOME}/bin is not in your PATH, you will have to add it."
	echo "Please run \"build.leia --help\" to see your options"
	echo "Happy Compiling!"

else

	echo "I guess this isn't the right time for you."
	echo "I understand."
	echo "Please return when you're ready to try build.leia."

fi
