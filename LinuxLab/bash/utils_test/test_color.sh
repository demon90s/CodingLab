#! /bin/bash

. ../utils/colors.sh

test1()
{
    set_black_text_white_bg
	echo -e "Black text, White bg\c"
    set_color_default
    echo

    set_red_text
	echo "Red text"

    set_green_text
	echo "Green text"

    set_yellow_text
	echo "Yellow text"

    set_blue_text
	echo "Blue text"

    set_purple_text
	echo -e "Purple text"

    set_sky_blue_text
	echo "Sky Blue text"

    set_white_text
	echo "White text"

    set_white_text_high_light
	echo "White text High light"

    set_white_text_under_line
	echo "White text Underline"

    set_red_text_blink
	echo "Red text Blink"

    set_color_default
	echo "default text"
}

test1