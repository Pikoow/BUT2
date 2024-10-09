<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Formulaire</title>
    </head>
    <body>
        <form action="liste-depts.php" method="post" enctype="multipart/form-data">
            <label for="nomdept">Nom dept. :</label>
            <input type="text" id="nomdept" name="nomdept" />
            <br />

            <label for="regions">Region :</label>
            <select id="regions" name="regions">
                <option value="rien" selected="selected">Choisissez une région</option>
                <?php
                    require_once('regions.php');

                    foreach($regions as $nomReg => $values) {
                        echo '<option value="' . $nomReg . '">' . $nomReg . '</option>';
                    }
                ?>
            </select>
            <br />

            <input type="submit" value="Rechercher" />
        </form>
    </body>
</html>
