<?php
    function verifSexe($sexe) {
        $sexes = array("H", "F");
        if (in_array($sexe, $sexes)) {
            return 0;
        } else {
            return 1;
        }
    }
    function verifClasse($classe) {
        $classes = array("6", "5", "4", "3", "2", "1", "T");
        if (in_array($classe, $classes)) {
            return 0;
        } else {
            return 1;
        }
    }
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Importer</title>
</head>
<body>
    <h1>Choisissez un fichier à importer</h1>
    <?php
    if (isset($_FILES["data"])) {
        $file = file($_FILES["data"]["tmp_name"]);
        foreach($file as $line) {
            $explodedLine = explode(';', $line);
            $sexe = $explodedLine[5];
            $sexe = trim($sexe);
            $verifsexe = verifSexe($sexe);
            if ($verifsexe == 1) {
                echo "Erreur de sexe à la ligne : " . $line;
                exit();
            }
            $verifclasse = verifClasse($explodedLine[4]);
            if ($verifclasse == 1) {
                echo "Erreur de classe à la ligne : " . $line;
                exit();
            }
            file_put_contents('data.csv', $line, FILE_APPEND);
        }
        echo "Tests réussis";
    } else {
    ?>
    <form action="import.php" method="POST" enctype="multipart/form-data">
        <label for="data">Choisissez un fichier à importer</label>
        <input type="file" id="data" name="data" required><br><br>

        <input type="submit" value="Envoyer">
    </form>
    <?php
    }
    ?>
</body>
</html>
