出现权限问题无法执行某些操作，解决方法是把文件夹权限递归设置给 nginx:nginx

```
chown -R nginx:nginx /data/web/PHPLab
```

mysql 官方文档：https://www.php.net/manual/zh/book.mysqli.php