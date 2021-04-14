<?php
    // file 函数返回文件的内容数组，并将每一行存储为一个数组元素
    $data = file("tmp.txt");

    $num = count($data);
    for ($i = 0; $i < $num; ++$i)
    {
        $line = $data[$i];
        echo "$line<br/>";
    }
?>