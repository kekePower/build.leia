# Converts a --with=option,option2 into an array
# Usage: InputToArray <input-string>
# Returns: $InputArray

function InputToArray () {

	if [[ ${@} =~ "--with" ]]; then
	        InputArray=( $( echo ${@} | cut -d= -f2 | sed 's/\,/\ /g' ) )
	fi

}
