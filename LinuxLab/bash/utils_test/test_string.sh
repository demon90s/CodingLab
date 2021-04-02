#! /bin/bash

. ../utils/string.sh

if string_equal A B ; then
    echo "EQUAL"
fi

if string_equal AB AB ; then
    echo "AB EQUAL"
fi

if $(string_not_equal A B) ; then
    echo "A B NOT EQUAL"
fi

if $(string_not_equal AB AB) ; then
    echo "AB EQUAL"
fi

str="liudiwen"
if $(string_empty $str) ; then
    echo "string is empty"
fi

if $(string_not_empty $str) ; then
    echo "string is not empty"
fi

if ! $(string_empty $str) ; then
    echo "string is not empty"
fi

str="hello world   yeyeye   wow"
str=$(string_erase_blanks "$str")
echo $str

str="1200|1300|2500|600"
string_slice $str "|"