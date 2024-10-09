<?php
    $data = unserialize(file_get_contents("data.txt"));
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Liste</title>
    </head>
    <body>
        <table>
            <tr>
                <th>Nom</th>
                <th>Prenom</th>
                <th>Adresse mail</th>
                <th>Avatar</th>
            <tr>
            <?php foreach ($data as $values) { ?>
            <tr>
                <td>
                   <?php echo htmlentities($values["nom"]) ?>
                </td>
                <td>
                   <?php echo htmlentities($values["prenom"]) ?>
                </td>
                <td>
                   <?php echo htmlentities($values["email"]) ?>
                </td>
                <td>
                    <img src="avatars/<?php echo $values["avatar"] ?>">
                </td>
                <?php } ?>
            </tr>
        </table>
        <p><a href="fiche.html">Fiche</a></p>
    </body>
</html>