<?php
    date_default_timezone_set("Asia/Shanghai");

    function get_time_asc()
    {
        $ymd = date("Y-m-d H:i:s l");
        return $ymd;
    }
?>

<html>
<head>
</head>

<body>
    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST')
    {
        $time_asc = get_time_asc();
        echo "<p>opera at: $time_asc</p>";

        $content = "some content write at " . $time_asc . PHP_EOL;
        $file = "tmp.txt";

        // 加 FILE_APPEND 表示追加内容，不加的话就覆盖内容
        file_put_contents($file, $content, FILE_APPEND);
    }
    ?>

    <form method="post" action="file_put_contents.php">
        <input type="submit" name="submit" value="add some content"/>
    </form>
</body>
</html>