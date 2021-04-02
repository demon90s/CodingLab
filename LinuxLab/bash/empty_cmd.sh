#! /bin/bash

# : 是一个空命令

rm -f fred
if [ -f fred ]; then
	:
else
	echo file fred did not exist
fi
