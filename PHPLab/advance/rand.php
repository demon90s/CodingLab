<form method="get" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
<input type="submit" name="submit" value="enter to gen a random number" />
</form>

<?php
    $rand_number = rand();
    echo "$rand_number" . "<br/>";

    $rand_number2 = rand(1, 10);
    echo "$rand_number2";
?>