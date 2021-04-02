<?php

class CustomException extends Exception
{
	public function ErrorMessage()
	{
		$error_msg = 'Error on line' . $this->getLine() . ' in ' . $this->getFile()
			. ': <b>' . $this->getMessage() . '</b> is not a valid E-Mail address';

		return $error_msg;
	}
}

$email = "someone@example ...com";

try {
	if (!filter_var($email, FILTER_VALIDATE_EMAIL))
	{
		throw new CustomException($email);
	}
}
catch (CustomException $e) {
	echo $e->ErrorMessage();
	echo "<br>";
}

echo "end<br>";

?>
