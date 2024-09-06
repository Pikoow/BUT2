<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>
        <?php echo $_GET['page'] ?>
    </h1>
    <ul>
        <?php
            require_once('../regions.php');
         
            foreach ($regions[$_GET['page']] as $value) {
        ?>
        <li>
            <?php
                echo $value; }
            ?>
        </li>
    </ul>

   <a href="http://localhost:8888/exo3-regions-q3.php?page=1">Retour</a>
</body>
</html>
