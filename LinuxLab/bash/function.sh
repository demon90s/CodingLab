#! /bin/bash

add()
{
    res=0
    for v in $@; do
        let res+=$v
    done

    echo $res
}

add 3 4
add 1 2 3 4 5

name=liudiwen
test_local()
{
    local name="miemie"
    echo $name
}
test_local # miemie
echo $name # liudiwen