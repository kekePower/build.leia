# Converts a --with=option,option2 into an array
# Usage: WithToArray <input-string>
# Returns: $WithArray

function WithToArray () {

	if [[ ${@} =~ "--with" ]] || [[ ${@} =~ "--install" ]];then
	        WithArray=( $( echo ${@} | cut -d= -f2 | sed 's/\,/\ /g' ) )
	fi

}
