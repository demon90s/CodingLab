<?php

// LOCK 选项：
// LOCK_SH      用于读取的共享锁
// LOCK_EX      用于写入的独享锁
// LOCK_UN      释放一个锁
// LOCK_NB      非阻塞锁

function print_file($fp)
{
    do
    {
        $line = fgets($fp);
        echo $line . "<br>";
    } while (!feof($fp));
}

$file = "tmp.txt";

$fp = fopen($file, 'rb');
if (empty($fp))
{
    die("<p>file open failed</p>");
}
if (flock($fp, LOCK_SH | LOCK_NB))
{
    echo "flock succ<br/>";

    echo "file content:<br/>";
    print_file($fp);

    flock($fp, LOCK_UN);
}

fclose($fp);

?>