<?php
// $_SERVER 保存关于报头、路径和脚本位置信息
// 参考：https://www.w3school.com.cn/php/php_superglobals.asp

echo $_SERVER['PHP_SELF'];  // 返回当前执行脚本的文件名
echo "<br>";

echo $_SERVER['HTTP_HOST']; // 返回来自当前请求的 Host 头
echo "<br>";
?>