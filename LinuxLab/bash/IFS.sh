#! /bin/bash

OLD_IFS=$IFS
echo "[OLD_IFS = ${OLD_IFS}]"

IFS=", "

param_list="hello,world, hi, liudiwen"

for v in $param_list; do
    echo $v
done

IFS=$OLD_IFS