<html>
<head>
    <title>View Your Settings</title>

    <style type="text/css">
        body {
            <?php
            // 检查 font_size 的值
            if (isset($_COOKIE['font_size'])) {
                print "\t\tfont-size: " . htmlentities($_COOKIE['font_size']) . ";\n";
            } else {
                print "\t\tfont-size: medium";
            }

            // 检查 font_color 的值
            if (isset($_COOKIE['font_color'])) {
                print "\t\tcolor: #" . htmlentities($_COOKIE['font_color']) . ";\n";
            } else {
                print "\t\tcolor: #000";
            }
            ?>
        }
    </style>
</head>

<body>
<p><a href="customize.php">Customize Your Settings</a></p>
<p><a href="reset.php">Reset Your Settings</a></p>

<p>
HAHAAH
wwowow
lalallalal
</p>
<body>
</html>