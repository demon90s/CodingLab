<?php

// expat 是基于事件的 xml 解析器，即在读取到节点的时候调用设置好的回调函数

// 读取到一个 element 时调用
function start($parser, $element_name, $element_attrs)
{
    switch ($element_name)
    {
        case "NAME":
            echo "Name: ";
            break;   

        case "AGE":
            echo "Age: ";
            break;
    }
}

// 读取完一个 element 时调用
function stop($parser, $element_name)
{
    echo "<br>";
}

// 读取到一个字符串时调用
function char($parser, $data)
{
    echo $data;
}

$parser = xml_parser_create();

xml_set_element_handler($parser, "start", "stop");

xml_set_character_data_handler($parser, "char");

// open xml file
$fp = fopen("test.xml", "r") or die("open xml file failed");


$content = fread($fp, filesize("test.xml"));

xml_parse($parser, $content) or die(sprintf("XML Error: %s at line %d", 
    xml_error_string(xml_get_error_code($parser)),
    xml_get_current_line_number($parser)));

xml_parser_free($parser);

?>