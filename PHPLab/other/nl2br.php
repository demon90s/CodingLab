<?php

	// nl2br 把换行符转换成 <br/>

	$content = "hello, world
	Line 2\nLine 3";

	echo "<p>content no use nl2br:</p>$content";

	echo "<hr/>";

	$content = nl2br($content);

	echo "<p>content with nl2br:</p>$content";
?>