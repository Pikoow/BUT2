<?php
    require('depts-fix.php');
    require('regions.php');

    $nom_dept = $_POST['nomdept'];
    $region = $_POST['regions'];

    $departements_affiches = [];

    if ($region != 'rien') {
        if ($nom_dept != '') {
            foreach ($regions[$region] as $value) {
                foreach($depts as $num => $values) {
                    if($value == $num && str_contains(strtolower($values[0]), $nom_dept)) {
                        $departements_affiches[] = $values[0];
                    }
                }
            }
        } else {
            foreach ($regions[$region] as $value) {
                foreach($depts as $num => $values) {
                    if($value == $num) {
                        $departements_affiches[] = $values[0];
                    }
                }
            }
        }
    } else {
        if ($nom_dept != '') {
            foreach($depts as $num => $values) {
                if (str_contains(strtolower($values[0]), $nom_dept)) {
                    $departements_affiches[] = $values[0];
                }
            }
        } else {
            foreach($depts as $num => $values) {
                $departements_affiches[] = $values[0];
            }
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Liste</title>
    </head>
    <body>
        <?php
            if (!empty($departements_affiches)) {
        ?>
        <ul>
            <?php
                foreach ($departements_affiches as $dept) {
            ?>
            <li>
                <?php echo $dept; ?>
            </li>
            <?php
                }
            ?>
        </ul>
        <?php
            } else {
                echo "Aucun département trouvé.";
            }
        ?>
        <br />
        <a href="http://localhost:8888/form-reg.php">Retour</a>
    </body>
</html>