#!/bin/bash

# This script renames all files of a given type to a different filetype
#
#
# TODO: 
#		takes two options as arguments. The first argument is the filetype you want to change.
#		The second argument is the filetype you want to change files into.
#
#		check that the two arguments are actually given. 
#		If not, the script is supposed to return a error message and terminate
#
#		In the next step the script needs to find the corresponding filenames.
#		Each file that is considered needs to be checked if it is a file and 
#		has read and write permissions.
#
#		Once files are found their file extensions need to change: 
#		For example, file.txt needs to change to file.text. HINT: use sed
#
#		Finally, the script needs to output something to the effect of notifying 
#		the user that file.txt has been changed to file.text.
#---------------------------------------------------------------------------------------------
	orgExt=$1
	newExt=$2

	if [ $# -lt 2 ]; then
		echo "Error: not enough arguments"
	else
		  shift
		  shift

		for file in $@; do
			  if [ ! -f "$file" ]; then

				echo "Error: $file not found"

			elif [ -r "$file" ] && [ -x "$file" ]; then

				mv "$file" "`echo $file | sed "s/$orgExt/$newExt/"`"

			else

				echo "Error: Check read write permissions for $file"

			 fi
		done
	fi
ls
