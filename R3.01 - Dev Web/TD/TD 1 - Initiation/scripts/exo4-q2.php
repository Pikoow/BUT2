<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $var = file_get_contents("../data");

        $var2 = unserialize($var);

        print_r($var2);

        $deserContent[2014] = [
            Artiste = "bob";
        ];

        $serContent = unserialize($deserContent);
        file_put_contents("data_new", $serContent);
    ?>
</body>
</html>