#! /bin/bash

# sleep 挂起程序若干秒，可以用小数来表示更精细的精度

n=0
while [ $n -lt 10 ]; do
    echo $n
    sleep 0.5
    (( n++ ))
done
