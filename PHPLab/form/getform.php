<html>
<body>
<!-- 通过 url 发送表单数据，可见 -->
<form action="test_getform.php" method="get">
Name: <input type="text" name="name"><br>
E-mail: <input type="text"m name="email"><br>

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