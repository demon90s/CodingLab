<?php

$xmldoc = new DOMDocument();

$xmldoc->load("test.xml") or die("load xml failed");

$x = $xmldoc->documentElement;
foreach ($x->childNodes as $item)
{
    echo $item->nodeName . " = " . $item->nodeValue . "<br>";
}

$xmldoc->saveXML();

?>