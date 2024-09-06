<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        require_once("../serial.php");

        echo serialize($ser_var1);
        echo serialize($ser_var2);
        echo serialize($ser_var3);
        echo serialize($ser_var4);
        echo serialize($ser_var5);
    ?>
</body>
</html>