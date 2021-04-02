<?php

// set_exception_handler
// the top level exception handler
// handle all exception that not catched by user

function top_exception_handler($exception)
{
	echo "<b>Exception:</b>" . $exception->getMessage();
}

set_exception_handler("top_exception_handler");

throw new Exception("some bad thing not catched");

?>
