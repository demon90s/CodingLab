<?php

// 按行分割字符串，但不会保存最后的换行符

$fp = fopen("test.csv", "r") or die("open file failed");

while ($field_list = fgetcsv($fp, 1024))
{
    echo "<p>";
    echo "name: $field_list[0], phone: $field_list[1], age: $field_list[2]";
    echo "</p>\n";
}

fclose($fp);

?>