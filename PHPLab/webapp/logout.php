<?php

// 登出页面，会删除 session 数据

// 开始 session 部分
session_start();

// 删除 session 变量
unset($_SESSION);

// 重置 session 数组
$_SESSION = array();

define('TITLE', 'Lougout');
include('template/header.html');

?>

<h2>Bye Bye</h2>
<p>See you next time</p>

<?php
include('template/footer.html');
?>