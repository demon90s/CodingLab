<?php

$host = "localhost:3306";
$username = "root";
$password = "123456";

$link = @mysqli_connect($host, $username, $password);   // @ 表示发生错误不提示
if (!$link)
{
    echo '<p style="color: red;">mysql connect failed:' . mysqli_connect_error() . '</p>';
    // 这里用不了 mysqli_error ... 因为要传入一个参数，这里没有
}
else
{
    echo "mysql connect succ\n";
}

if (!@mysqli_query($link, "just a bad syntax"))
{
    echo '<p style="color: red;">mysql connect failed:' . mysqli_error($link) . '</p>';
}


?>