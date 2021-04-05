<?php

// 如果表单已提交，则处理他
if (isset($_POST['font_size'], $_POST['font_color'])) {
    // 发送 cookie
    setcookie('font_size', $_POST['font_size']);
    setcookie('font_color', $_POST['font_color']);

    // 打印一条消息
    $msg = '<p>Your settings have been entered! Click <a href="view_settings.php">here</a> to see them in action</p>';
}

?>

<html>
<head>
</head>

<body>
    <?php
    if (isset($msg)) {
        print $msg;
    }
    ?>

    <p>Use this form to set your preferences:</p>
    <form action="customize.php" method="post">
        <select name="font_size">
            <option value="">Font Size</option>
            <option value="small">small</option>
            <option value="medium">medium</option>
            <option value="large">large</option>
        </select>

        <select name="font_color">
            <option value="">Font Color</option>
            <option value="999">Gray</option>
            <option value="0c0">Green</option>
            <option value="oof">Blue</option>
        </select>

        <input type="submit" name="submit" value="Set My Preferences" />
    </form>
</body>
</html>