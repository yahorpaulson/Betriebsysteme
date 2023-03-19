#!/bin/sh
if [ 1 -gt "$#" ]  #if 1 < number of params
then
	echo "Usage: $0 name [additional names]" #basename of the program
	rm hello.txt
	
else
	echo "Total number of names is $#"
	echo ""
	echo > hello.txt
	while [ 1 -le $# ] #less or equal
		do
			echo "Hello $1" >> hello.txt
			shift
	done
fi

cat hello.txt