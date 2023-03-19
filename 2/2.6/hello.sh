#!/bin/sh
if [ 1 -gt "$#"]  #if 1 > number of params
then
	echo "Usage: §0 name [additional names]" #basename of the program
else
	echo "Total number of names is $#"
	echo ""
	echo "Hello $1"
fi