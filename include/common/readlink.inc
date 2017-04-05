# If a file or directory is a link or not, find the source
# Variables for this function are
# - Input file or directory
# - zname or fzname

function include () {
	source ~/bin/include/${@}.inc
}

include common/colors

function zreadlink () {

if [[ ! ${2} ]]; then
	echo "${WHITE}* readlink error:${END} ${RED}Please add zname or fzname as the second argument in your script.${END}"
else

	if [[ -L ${1} ]]; then

		if [[ ${2} ]] && [[ ${2} == "zname" ]]; then
			readlink "${1}"
		elif [[ ${2} ]] && [[ ${2} == "fzname" ]]; then
			readlink -f "${1}"
		fi

	else

		echo "${LIGHTGREEN}File is not a symlink.${END}"

	fi

fi

}
