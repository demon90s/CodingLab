<?php

function check($num) {
	if ($num == 0) {
		throw new Exception("num must not be 0");
	}
}

echo "begin";

check(0);

echo "never reach here";

?>
