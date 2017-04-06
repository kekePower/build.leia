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
	if [[ ! $( grep REMOVEME ~/bin/etc/build.leia.conf ) ]]; then
		echo "Please review ~/bin/etc/build.leia.conf.new for changes and/or updates"
		cp -f etc/build.leia.conf ~/bin/etc/build.leia.conf.new
	else
		cp -af etc ~/bin/
	fi
	cp -af include ~/bin/
	chmod 750 ~/bin/build.leia
	echo "build.leia is installed."
	echo "Please edit ~/bin/etc/build.leia.conf before running the script."
	echo "Please run \"build.leia --help\" to see your options"
	echo "Good luck!"
else
	echo "I guess this isn't the right time for you."
	echo "I understand."
	echo "Please return if/when you're ready."
fi
