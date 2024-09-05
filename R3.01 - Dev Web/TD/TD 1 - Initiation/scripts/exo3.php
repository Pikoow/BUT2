<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <table>
        <tr>
            <th scope="col">Nom</th>
            <th scope="col">Prénom</th>
        </tr>
        <tr>
            <td>
                <pre>
                    <?php print_r($_GET['nom']); ?>
                </pre>
            </td>
            <td>
                <pre>
                    <?php print_r($_GET['prenom']); ?>
                </pre>
            </td>
        </tr>

    </table>
</body>
</html>
