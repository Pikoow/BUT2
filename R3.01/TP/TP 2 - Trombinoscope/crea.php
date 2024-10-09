<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Fiche Signalétique</title>
</head>
<body>
    <h1>Infos</h1>
    <?php
    if (isset($_POST["nom"])) {
        $nom = $_POST["nom"];
        $insee = $_POST["num_insee"];
        $prenom = $_POST["prenom"];
        $mail = $_POST["email"];
        $sexe = $_POST["sexe"];
        $classe = $_POST["classes"];
        $line = "\n" . strtoupper($nom) . ";" . strtoupper($prenom) . ";" . $mail . ";" . $insee . ";" . $classe . ";" . $sexe;
        file_put_contents('data.csv', $line, FILE_APPEND);

        $file = $_FILES['photo'];
        $fileTmpName = $file['tmp_name'];

        $explodedExplodedLine = explode('/', $insee);
        $insee = trim($explodedExplodedLine[0]);
        $name = $insee . ".png";
        $destination = "avatars/$name";
        move_uploaded_file($fileTmpName, $destination);
    } else {
    ?>
    <form action="crea.php" method="POST" enctype="multipart/form-data">
        <label for="num_insee">Numéro INSEE :</label>
        <input type="text" id="num_insee" name="num_insee" required><br><br>
    
        <label for="nom">Nom :</label>
        <input type="text" id="nom" name="nom" required><br><br>

        <label for="prenom">Prénom :</label>
        <input type="text" id="prenom" name="prenom" required><br><br>

        <label for="email">Adresse mail :</label>
        <input type="email" id="email" name="email" required><br><br>
        
        <label for="sexe">Sexe :</label>
        <input type=radio id="sexe" name="sexe" value="H" checked>
        <label for="homme">Homme</label>
        <input type=radio id="sexe" name="sexe" value="F">
        <label for="femme">Femme</label><br><br>

        <label for="classe">Classe :</label>
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
        
        <label for="photo">Photo :</label>
        <input type="file" id="photo" name="photo" required><br><br>

        <input type="submit" value="Soumettre">
        <br>
        <a href="http://localhost:8888/import.php">Importer avec un fichier</a>
        <br>
        <a href="http://localhost:8888/liste-classe.php">Afficher la liste</a>
    </form>
    <?php
    }
    ?>
</body>
</html>