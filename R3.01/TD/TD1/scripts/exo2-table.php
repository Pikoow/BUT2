<?php
$depts = [
   'Ain',
   'Aisne',
   'Allier',
   'Alpes-de-Haute-Provence',
   'Hautes-Alpes',
   'Alpes-Maritimes',
   'Ardèche',
   'Ardennes',
   'Ariège',
   'Aube',
   'Aude',
   'Aveyron',
   'Bouches-du-Rhône',
   'Calvados',
   'Cantal',
   'Charente',
   'Charente-Maritime',
   'Cher',
   'Corrèze',
   'Corse-du-Sud',
   'Haute-Corse',
   'Côte-d\'Or',
   'Côtes-d\'Armor',
   'Creuse',
   'Dordogne',
   'Doubs',
   'Drôme',
   'Eure',
   'Eure-et-Loir',
   'Finistère',
   'Gard',
   'Haute-Garonne',
   'Gers',
   'Gironde',
   'Hérault',
   'Ille-et-Vilaine',
   'Indre',
   'Indre-et-Loire',
   'Isère',
   'Jura',
   'Landes',
   'Loir-et-Cher',
   'Loire',
   'Haute-Loire',
   'Loire-Atlantique',
   'Loiret',
   'Lot',
   'Lot-et-Garonne',
   'Lozère',
   'Maine-et-Loire',
   'Manche',
   'Marne',
   'Haute-Marne',
   'Mayenne',
   'Meurthe-et-Moselle',
   'Meuse',
   'Morbihan',
   'Moselle',
   'Nièvre',
   'Nord',
   'Oise',
   'Orne',
   'Pas-de-Calais',
   'Puy-de-Dôme',
   'Pyrénées-Atlantiques',
   'Hautes-Pyrénées',
   'Pyrénées-Orientales',
   'Bas-Rhin',
   'Haut-Rhin',
   'Rhône',
   'Haute-Saône',
   'Saône-et-Loire',
   'Sarthe',
   'Savoie',
   'Haute-Savoie',
   'Paris',
   'Seine-Maritime',
   'Seine-et-Marne',
   'Yvelines',
   'Deux-Sèvres',
   'Somme',
   'Tarn',
   'Tarn-et-Garonne',
   'Var',
   'Vaucluse',
   'Vendée',
   'Vienne',
   'Haute-Vienne',
   'Vosges',
   'Yonne',
   'Territoire de Belfort',
   'Essonne',
   'Hauts-de-Seine',
   'Seine-Saint-Denis',
   'Val-de-Marne',
   'Val-d\'Oise',
];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <style>
        table, th, td {
            border:1px solid black;
        }
    </style>
    <table>
        <tr>
            <th scope="col">Numéro</th>
            <th scope="col">Nom</th>
        </tr>
        <?php
            for ($i = 0; $i < count($depts); $i++) {
        ?>
        <tr>
            <td>
                <?php
                    echo htmlentities($i);
                ?>
            </td>
            <td>
                <?php
                    echo htmlentities($depts[$i]); }
                ?>
            </td>
        </tr>
    </table>
</body>
</html>