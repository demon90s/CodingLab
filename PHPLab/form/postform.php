<html>
<body>
<!-- 通过 http post 发送表单数据，不可见 -->
<form action="test_postform.php" method="post">
Name: <input type="text" name="name"><br>
E-mail: <input type="text" name="email"><br>

<p>
Citys:
<select name="city">
    <option value="Guangzhou">Guangzhou</option>
    <option value="Beijing">Beijing</option>
</select>
</p>

<p>
Sex: 
<input type="radio" name="radio_sex" value="male" />male
<input type="radio" name="radio_sex" value="female" />female
</p>

<p>
Comment:<br />
<textarea name="comment" rows="3" cols="30"></textarea>
</p>

<input type="submit" name="submit" value="send to php">
</form>

</body>
</html>