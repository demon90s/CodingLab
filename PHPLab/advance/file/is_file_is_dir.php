<?php
// is_file 判断entry是否是一个文件
// is_die 判断entry是否是一个目录

$item_list = scandir(".");

echo "item list:\n<br/>";
echo "<ul>\n";
foreach ($item_list as $item)
{
    $item_type = "unknown";
    if (is_dir($item))
    {
        $item_type = "dir";
    }
    else if (is_file($item))
    {
        $item_type = "file";
    }

    echo "<li>$item ($item_type)</li>\n";
}
echo "</ul>\n";

?>