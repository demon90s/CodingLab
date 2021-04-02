<?php
define("TITLE", "Login");
include "template/header.html";

if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $email = $_POST['email'];
    $password = $_POST['password'];

    if ($email == "demon90s@163.com" && $password == "123456") {
        // print "log in succ";

        ob_end_clean();
        header('location: welcome.php');
        exit();
    }
    else
    {
        //print_login_form();

        print "invalid email or password";
    }
}
else
{
    print '
    <form method="post" action="login.php">
    <p>
        Email Address: <input type="text" name="email" size="20" />
    </p>

    <p>
        Password: <input type="password" name="password" size="20" />
    </p>

    <p>
        <input type="submit" name="submit" value="Log In" />
    </p>
    </form>
    ';
}
?>

<?php
include "template/footer.html"
?>