<?php

// htmlentities 将html标签改掉，改成输出的文本而不被解析，
// 主要用于用户的输入（避免用户输入html代码）

$html_content = "<h1>This is a html content</h1><p>but can not be parse</p>";

//print "$html_content";
$html_content = htmlentities($html_content);
print "$html_content";

?>