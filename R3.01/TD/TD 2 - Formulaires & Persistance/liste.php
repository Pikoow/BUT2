<?php
    $dataFile = 'data.txt';
    $data = unserialize(file_get_contents($dataFile));
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Fiche Signalétique</title>
</head>
<body>
    <table>
        <tr>
            <th>Nom</th>
            <th>Prenom</th>
            <th>Email</th>
            <th>Avatar</th>
        </tr>
        <tr>
            <?php
               foreach ($data as $value) {
            ?>
            <td><?php echo htmlentities($value["nom"]) ?></td>
            <td><?php echo htmlentities($value["prenom"]) ?></td>
            <td><?php echo htmlentities($value["email"]) ?></td>
            <td><img src="avatars/<?php echo $value["avatar"] ?>"></td>
            <?php
                }
            ?>
        </tr>
    </table>
</body>