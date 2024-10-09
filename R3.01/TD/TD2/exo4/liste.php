<?php
// Start the session at the beginning of the script
session_start();
?>

<!DOCTYPE html>
<html lang="fr">
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
        </tr>
        <?php if (isset($_SESSION['users']) && !empty($_SESSION['users'])) { ?>
            <?php foreach ($_SESSION['users'] as $user) { ?>
            <tr>
                <td><?php echo htmlentities($user['nom']); ?></td>
                <td><?php echo htmlentities($user['prenom']); ?></td>
                <td><?php echo htmlentities($user['email']); ?></td>
                <td><img src="avatars/<?php echo htmlentities($user['avatar']); ?>" alt="Avatar" width="100" height="100"></td>
            </tr>
            <?php } ?>
        <?php } else { ?>
            <tr>
                <td colspan="4">Pas de données.</td>
            </tr>
        <?php } ?>
    </table>
    <p><a href="fiche.html">Fiche</a></p>
</body>
</html>
