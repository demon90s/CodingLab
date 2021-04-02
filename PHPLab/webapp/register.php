<?php
define('TITLE', 'Register');
include 'template/header.html';

print '
<h2>Register Form</h2>
<p>Enter your message to register</p>
';

// 添加CSS:
print '
<style type="text/css" media="screen">
    .error { color: red; }
</style>
';

// 检查表单是否已提交
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $problem = FALSE;

    // 检查每个值
    if (empty($_POST['email'])) {
        $problem = TRUE;
        print '<p class="error">Please enter email</p>';
    }

    if (empty($_POST['password'])) {
        $problem = TRUE;
        print '<p class="error">Please enter password</p>';
    }

    if (empty($_POST['confirm_password'])) {
        $problem = TRUE;
        print '<p class="error">Please enter confirm_password</p>';
    }

    if ($_POST['password'] != $_POST['confirm_password']) {
        $problem = TRUE;
        print '<p class="error">password not equal</p>';
    }

    if (!$problem) {
        print '<p>OK~</p>';

        $_POST = array();
    }
}

?>

<!-- 创建表单 -->
<form method="post" action="register.php">

<p>
Email: 
<input type="text" name="email" 
value="<?php 
if (isset($_POST['email'])) 
    print htmlspecialchars($_POST['email']) 
?>"
/>
</p>

<p>
Password: 
<input type="text" name="password" 
value="<?php 
if (isset($_POST['password'])) 
    print htmlspecialchars($_POST['password']) 
?>"
/>
</p>

<p>
Confirm Password: 
<input type="text" name="confirm_password" 
value="<?php 
if (isset($_POST['confirm_password'])) 
    print htmlspecialchars($_POST['confirm_password']) 
?>"
/>
</p>

<p>
    <input type="submit" name="submit" value="Register" />
</p>
</form>

<?php
include 'template/footer.html';
?>