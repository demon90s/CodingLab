<?php

// strip_tags 用于将html的标签直接删掉。
// 主要用于避免用户输入html代码

$html_content = "<h1>This is a html content</h1><p>but tags have been deleted</p>";

//print "$html_content";
$html_content = strip_tags($html_content);
print "$html_content";

?>