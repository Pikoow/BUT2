<?php
    require('./liste.php');

    $code = $_GET['code'];
    $qte = $_GET['qte'];
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Formulaire</title>
    </head>
    <body>
        <?php
            if ($qte > 0) {
                $totalArticles[$code]['stock'] += $qte;
        ?>
        <p>Article <?php echo $code;?> a été ajouté à votre stock.</p>
        <?php
            } else {
                $totalArticles[$code]['vendu'] += abs($qte);
                $totalArticles[$code]['stock'] -= abs($qte);
        ?>
            <p>Article <?php echo $code;?> a été vendu.</p>
        <?php }?>

        <a href="liste.php">Retour à la liste</a>
    </body>
</html>