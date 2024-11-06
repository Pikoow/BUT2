<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Liste des Équipes et Coureurs - Tour de France 2023</title>
    <style>
        .team-container {
            border: 1px solid black;
            width: 100%;
            font-family: Arial, sans-serif;
        }

        .team-header {
            background-color: black;
            color: white;
            padding: 10px;
            font-size: 1.2em;
            text-align: center;
        }

        .team-row {
            display: flex;
        }

        .cyclist-row {
            display: flex;
            border-bottom: 1px solid black;
        }

        .team-cell {
            border-right: 1px solid black;
            text-align: left;
        }

        .cyclist-cell {
            padding: 8px;
            border-left: 1px solid black;
            text-align: left;
        }

        .team-number {
            width: 5%;
            font-weight: bold;
            font-size: 1.2em;
            display: flex;
            align-items: center;
            justify-content: center;
        }

        .team-cell:first-child {
            width: 15%;
            font-weight: bold;
        }

        .team-cell:last-child {
            flex-grow: 1;
        }

        .team-cell:last-child {
            border-right: none;
        }

        .team-number,
        .team-cell:first-child {
            text-align: center;
        }
    </style>
</head>
<body>

<?php

class Coureur {
    public $numero;
    public $nom;
    public $prenom;
    private $abandon = false;

    function __construct($id, $name, $surname) {
        $this->numero = $id;
        $this->nom = $name;
        $this->prenom = $surname;
    }

    function abandonner($numero) {
        
    }

    function __set($nom_att, $val) {
        if ($nom_att === 'nom') {
            $this->nom = strtoupper($val);
        } else if ($nom_att === 'prenom') {
            $this->prenom = substr($val, 0, 10);
        } else if ($nom_att === 'numero') {
            $this->numero = $val;
        }
    }

    function __get($nom_att) {
        if ($nom_att === 'nom') {
            return $this->nom;
        } else if ($nom_att === 'prenom') {
            return $this->prenom;
        } else if ($nom_att === 'numero') {
            return $this->numero;
        }
    }
}

class Equipe {
    public $nom;
    public $coureurs;

    function __construct($name, $list) {
        $this->nom = $name;
        $this->coureurs = $list;
    }

    public function remplirListeCoureurs() {
        $nomFichier = str_replace(" ", "_", $this->nom);
        $cheminFichier = 'TDF_2023/' . trim($nomFichier);
    
        $contenuFichier = file_get_contents($cheminFichier);
        if ($contenuFichier !== false) {
            $lignes = explode("\n", $contenuFichier);
            
            array_shift($lignes);
    
            foreach ($lignes as $ligne) {
                if (trim($ligne) !== '') {
                    $elements = explode(" ", trim($ligne), 2);
                    $numeroCoureur = $elements[0];
                    $nomComplet = $elements[1];
                    
                    list($prenom, $nom) = explode(" ", $nomComplet, 2);
    
                    $coureur = new Coureur($numeroCoureur, $nom, $prenom);
    
                    $this->coureurs[$numeroCoureur] = $coureur;
                }
            }
        } else {
            echo "Erreur lors de l'ouverture du fichier $cheminFichier.";
        }
    }

    function __set($nom_att, $val) {
        if ($nom_att === 'nom') {
            $this->nom = strtoupper($val);
        } else if ($nom_att === 'coureurs') {
            $this->nom = $val;
        }
    }

    function __get($nom_att) {
        if ($nom_att === 'nom') {
            return $this->nom;
        } else if ($nom_att === 'coureurs') {
            return $this->coureurs;
        }
    }
}

$equipes = array();
$index = 1;

$contenuFichier = file_get_contents("TDF_2023/EQUIPES_TDF_2023");

if ($contenuFichier !== false) {
    $lignes = explode("\n", $contenuFichier);

    foreach ($lignes as $ligne) {
        if (trim($ligne) !== '') {  // To ignore empty lines
            $numeroEquipe = $index;
            $nomEquipe = trim($ligne);

            $equipe = new Equipe($nomEquipe, array());

            $equipes[$numeroEquipe] = $equipe;
            $index++;
        }
    }
} else {
    echo "Erreur lors de l'ouverture du fichier EQUIPES_TDF_2023.";
}

foreach ($equipes as $equipe) {
    $equipe->remplirListeCoureurs();
}
?>

<?php
foreach ($equipes as $numeroEquipe => $equipe) {
?>
    <div class="team-container">
        <div class="team-header"><?php echo htmlspecialchars($equipe->nom)?></div>
        <div class="team-body">
            <div class="team-row">
                <div class="team-cell team-number"><?php echo htmlspecialchars($numeroEquipe)?></div>
                <div class="team-cell" style="width: 100%;"> 
                    <?php
                    foreach ($equipe->coureurs as $coureur) {
                    ?>
                        <div class="cyclist-row">
                            <div class="cyclist-cell"><?php echo htmlspecialchars($coureur->numero)?></div>
                            <div class="cyclist-cell"><?php echo htmlspecialchars($coureur->prenom . ' ' . $coureur->nom)?></div>
                        </div>
                    <?php
                    }
                    ?>
                </div>
            </div>
        </div>
    </div>
<?php
}
?>