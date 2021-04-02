#! /bin/bash

string_equal()
{
    local lhs="$1"
    local rhs="$2"
    if [ "$lhs" = "$rhs" ]; then
        return 0
    else
        return 1
    fi
}

string_not_equal()
{
    local lhs="$1"
    local rhs="$2"
    if [ "$lhs" != "$rhs" ]; then
        echo true
    else
        echo false
    fi
}

string_empty()
{
    local str="$1"
    if [ -z "$str" ]; then
        echo true
    else
        echo false
    fi
}

string_not_empty()
{
    local str="$1"
    if [ -n "$str" ]; then
        echo true
    else
        echo false
    fi
}

string_erase_blanks()
{
    local str="$1"
    str=${str//[[:blank:]]/}
    echo $str
}

string_slice()
{
    local str="$1"
    local ifs="$2"

    local old_ifs=$IFS
    IFS="$ifs"
    for v in "$str"; do
        echo $v
    done

    IFS=$old_ifs
}