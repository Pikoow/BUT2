<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Liste classes</title>
    <style>
        table {
            border-collapse: collapse;
            table-layout: fixed;
            width: 25%;
            margin-bottom: 5px;
        }
        td, th {
            border: 1px solid black;
            width: 100%;
            padding: 8px;
            text-align: left;
        }
        .sexe {
            width: 25%;
        }
        .bold {
            font-weight: bold;
        }
        .image-cell {
            width: 50px;
        }
        img {
            width: 50px;
            height: auto;
        }
        .email-cell {
            text-align: left;
        }
    </style>
</head>
<body>
    <h1>
        <?php
        $classe = $_POST["classes"];
        echo "Liste classes " . $classe;
        ?>
    </h1>
    <?php
    if (isset($_POST["classes"])) {
        $liste = [];
        $file = file('data.csv');

        foreach($file as $line) {
            $explodedLine = explode(';', $line);
            $classeLine = $explodedLine[4];

            if ($classeLine == $classe) {
                $liste[] = $line;
            }
        }
    ?>
        <table>
    <?php
        foreach ($liste as $line) {
            $explodedLine = explode(';', $line);
    ?>
            <table>
                <tr>
                    <th class="sexe"><?php echo $explodedLine[5]; ?></th>
                    <th class="bold"><?php echo $explodedLine[0]; ?></th>
                    <th><?php echo $explodedLine[1]; ?></th>
                    <th rowspan="2" class="image-cell">
                        <img src="avatars/<?php $explodedExplodedLine = explode('/', $explodedLine[3]); echo trim($explodedExplodedLine[0]); ?>.png" alt="Avatar">
                    </th>
                </tr>
                <tr>
                    <td colspan="3" class="email-cell"><?php echo $explodedLine[2]; ?></td>
                </tr>
            </table>
    <?php
        }
    ?>
        <table>
    <?php
    } else {
    ?>
    <form action="liste-classe.php" method="POST" enctype="multipart/form-data">
        <label for="classes">Classe</label>
        <select name="classes" id="classes" required>
            <option value="">--Classes--</option>
            <option value="6">6</option>
            <option value="5">5</option>
            <option value="4">4</option>
            <option value="3">3</option>
            <option value="2">2</option>
            <option value="1">1</option>
            <option value="T">T</option>
        </select><br><br>

        <input type="submit" value="Soumettre">
    </form>
    <br>
    <a href="http://localhost:8888/crea.php">Importer manuellement</a>
    <br>
    <a href="http://localhost:8888/import.php">Importer avec un fichier</a>
    <?php } ?>
</body>