<?php
    // 开始 session 部分
    session_start();

    define('TITLE', 'Welcome');
    include 'template/header.html';
?>

<h2>Welcome</h2>

<p>Hi There</p>

<?php
    $user_email = $_SESSION['email'];
    $user_loggedin = $_SESSION['loggedin'];
    print "<p>Hello $user_email</p>";

    // 打印用户登陆时间
    date_default_timezone_set("Asia/Shanghai");
    $loggin_date = date('g:i a', $user_loggedin);
    print "<p>You have been logged in since: $loggin_date</p>";
?>

<p><a href="logout.php">Click here to logout.</a></p>

<?php
    include 'template/footer.html';
?>