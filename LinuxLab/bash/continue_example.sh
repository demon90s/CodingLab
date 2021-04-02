#! /bin/bash

# continue 跳到下一次循环继续执行

rm -fr fred*
echo > fred1
echo > fred2
mkdir fred3
echo > fred4

# 查找第一个名字开头是fred的目录
for file in fred*
do
	if [ -d "$file" ]; then
		echo "skipping directory $file"
		continue
	fi
	echo file is $file
done

rm -fr fred*
