<?php
 // scandir 找到目录中的所有项目（名字字符串），把它存入一个数组返回

$item_list = scandir(".");

echo "item list:\n<br/>";
echo "<ul>\n";
foreach ($item_list as $item)
{
    echo "<li>$item</li>\n";
}
echo "</ul>\n";

?>