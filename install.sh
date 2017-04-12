#!/bin/zsh

echo "Do you want to install build.leia to ~/bin/? (Y/n) \c"
read answer

if [[ ${answer} == "" || ${answer} == "Y" || ${answer} == "y" ]]; then
	
	if [[ ! -d ${HOME}/bin ]]; then
		echo "~/bin doesn't exist. Creating it now."
		mkdir ~/bin
	fi

	echo "Copying files to ~/bin/"
	cp -f build.leia ~/bin/
	if [[ $( cat ~/bin/etc/build.leia.conf | head -1 ) != $( cat etc/build.leia.conf.sample | head -1 ) ]]; then
		echo "Please review ~/bin/etc/build.leia.conf.sample for changes and/or updates"
		cp -f etc/build.leia.conf.sample ~/bin/etc/build.leia.conf.sample
	else
		cp -af etc ~/bin/
	fi
	cp -af include ~/bin/
	chmod 750 ~/bin/build.leia
	echo "build.leia is installed."
	echo "Please edit ~/bin/etc/build.leia.conf.sample before running the script."
	echo "Please run \"build.leia --help\" to see your options"
	echo "Good luck!"
else
	echo "I guess this isn't the right time for you."
	echo "I understand."
	echo "Please return if/when you're ready."
fi
