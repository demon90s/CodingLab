<html>

<style>
.error {color: #FF0000;}
</style>

<?php
$name = "";
$email = "";
$gender = "";
$comment = "";
$website = "";

$nameErr = "";
$emailErr = "";
$genderErr = "";
$websiteErr = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = test_input($_POST["name"]);
    if (empty($name)) {
        $nameErr = "Name is required";
    }
    else if (!preg_match("/^[a-zA-Z]*$/", $name)) {
        $nameErr = "只允许字母和空格";
    }

    $email = test_input($_POST["email"]);
    if (empty($email)) {
        $emailErr = "email is required";
    }
    else if (!preg_match("/([\w\-]+\@[\w\-]+\.[\w\-]+)/",$email)) {
        $emailErr = "无效的 email 格式";
    }

    $gender = test_input($_POST["gender"]);
    if (empty($gender)) {
        $genderErr = "sex is required";
    }

    $comment = test_input($_POST["comment"]);
    $website = test_input($_POST["website"]);
    if (!empty($website) && !preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%
    =~_|]/i",$website)) {
        $websiteErr = "无效的 URL";
    }
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
Name: <input type="text" name="name">
<span class="error">*<?php echo $nameErr; ?></span>
<br>
E-mail: <input type="text", name="email">
<span class="error">*<?php echo $emailErr; ?></span>
<br>
Website: <input type="text", name="website">
<span class="error"><?php echo $websiteErr; ?></span>
<br>

Comment: <textarea name="comment" rows="5", cols="40"></textarea><br>

Gender: 
<input type="radio" name="gender" value="female">Female
<input type="radio" name="gender" value="male">male
<span class="error">*<?php echo $genderErr; ?></span>
<br>

<input type="submit">

</form>

<?php

echo "your input:<br>";
echo "name: " . $name . "<br>";
echo "email: " . $email . "<br>";
echo "gender: " . $gender . "<br>";
echo "comment: " . $comment . "<br>";
echo "website: " . $website . "<br>";
?>

</html>