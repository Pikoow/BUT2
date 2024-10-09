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
                    <?php
                        if (isset($_GET['nom'])) {
                            print_r($_GET['nom']);
                        } else {
                            print_r(" ");
                        }
                    ?>
                </pre>
            </td>
            <td>
                <pre>
                    <?php
                        if (isset($_GET['prenom'])) {
                            print_r($_GET['prenom']);
                        } else {
                            print_r(" ");
                        }
                    ?>
                </pre>
            </td>
        </tr>

    </table>
</body>
</html>
