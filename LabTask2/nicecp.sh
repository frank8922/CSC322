#!/bin/csh
#
#
#--------------------Description -------------------------------------
#
# Copys file named as first parameter to the file
# named as the second parameter to the shell script
#
# TODO:
#
#  A) The shell script needs to check if 2 argumnets were given.
#	   It is supposed to exit if there are no 2 arguments
#
#  B) The shell script needs to check if the second file already exists
#	   and ask the users to confirm whether he/she wants the file named
#	   as the second parameter overwritten. If not, the script exits.
#
#  C) Finally, the shell script is supposed to copy the first file to the 
#	   second one.
#
#---------------------Solution ----------------------------------------- 
#
#
	set input = ""
	if ($# < 2) then
		echo "Error: not enough arguments"
		exit
	else
		if ( -f $2 && -e $2 && -r $2) then
		  echo "Are you sure you want to overwrite the existing file $2?"
		  set input = $<
		  echo $input
		  if ( $input == "n" | $input == "N") then
			exit 0
		  else
			cp $1 $2
		  endif
		endif
	endif

