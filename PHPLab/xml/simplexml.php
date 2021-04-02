<?php

$xml = simplexml_load_file("test.xml"); // get root element
if (!$xml)
{
    die("load xml failed");
}

echo $xml->getName() . "<br>"; // root

foreach ($xml->children() as $child)
{
    echo $child->getName() . ": " . $child . "<br>";
}

?>