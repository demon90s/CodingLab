#! /bin/bash

# case 支持 pattern

echo "Is it morning? Please enter yes or no"
read timeofday

case "$timeofday" in
    yes | y | YES | Yes) 
        echo "Good morning"
        echo "Up bright and early this morning"
        ;;
    [nN]*)
        echo "Good afternoon"
        ;;
    *)
        echo "Sorry, answer not recognized"
        echo "Please answer yes or no"
        ;;
esac

exit 0

