#!/bin/env zsh

echo "Do you want to install build.leia to ${HOME}/bin/? (Y/n) \c"
read answer

if [[ ${answer} == "" || ${answer} == "Y" || ${answer} == "y" ]]; then
	
	if [[ ! -d ${HOME}/bin ]]; then
		echo "${HOME}/bin doesn't exist. Creating it now."
		mkdir ${HOME}/bin
	fi

	echo "Copying files to ${HOME}/bin/"
	cp -f build.leia ${HOME}/bin/

	if [[ ! -d ${HOME}/bin/etc ]]; then
		cp -af etc ${HOME}/bin/
	fi

	if [[ $( cat ${HOME}/bin/etc/build.leia.conf | head -1 ) != $( cat etc/build.leia.conf.sample | head -1 ) ]]; then
		echo "Please review ${HOME}/bin/etc/build.leia.conf.sample for changes and/or updates"
		cp -f etc/build.leia.conf.sample ${HOME}/bin/etc/build.leia.conf.sample
	fi

	cp -af include ${HOME}/bin/
	chmod 750 ${HOME}/bin/build.leia

	echo "build.leia is installed."
	echo "Please edit ${HOME}/bin/etc/build.leia.conf.sample before running the script."
	echo "Rename it to build.leia.conf when you're done editing it."
	echo "If ${HOME}/bin is not in your PATH, you will have to add it."
	echo "Please run \"build.leia --help\" to see your options"
	echo "Good luck!"

else

	echo "I guess this isn't the right time for you."
	echo "I understand."
	echo "Please return if/when you're ready."

fi
