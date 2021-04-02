#! /bin/bash

echo "enter age: "
read age

if [ "$age" -lt 0 ] || [ "$age" -gt 150 ]
then
    echo "wrong age"
elif [ "$age" -ge 0 ] && [ "$age" -lt 4 ]
then
    echo "baby"
elif ! [ "$age" -lt 4 ]
then
    echo "age >= 4"
fi
