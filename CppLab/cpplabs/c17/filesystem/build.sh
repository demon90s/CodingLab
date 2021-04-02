#! /bin/bash

if [ "$1" == "clean" ]; then
	for f in *; do
		if file $f | grep -q 'ELF 64-bit LSB executable' ; then
			echo "rm $f"
			rm -f $f
		fi
	done
	exit 0
fi

cpp=$1
if [ "$cpp" == "" ]; then
	echo "usage: $0 <cppfile>"
	exit 1
fi

out=${cpp%.cpp*}

g++ -g -Wall -std=c++17 $cpp -o $out -lstdc++fs
