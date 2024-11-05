<?php

class Horodateur {
    public $maintenant;
    public $label;

    function setNow() {
        $this->maintenant = time();
    }

    function setNom($nom) {
        $this->label = $nom;
    }

    function fmtDate() {
        return date("Y-m-d", $this->maintenant);
    }

    function fmtHeure() {
        return date("H:i:s", $this->maintenant);
    }

    function difference($dt) {
        return ($dt - $this->maintenant);
    }

    function estFutur($dt) {
        return $dt > $this->maintenant;
    }
}

$now = new Horodateur();
$now->setNow();
echo "Objet créé le " . $now->fmtDate() . " à " . $now->fmtHeure();
echo "<br />";

$objet1 = new Horodateur();
$objet2 = new Horodateur();

$objet1->setNom('Objet 1');
$objet2->setNom('Objet 2');

$objet1->setNow();
$objet2->setNow();

$val1 = 1664524330;
$val2 = 2074751530;

echo "Objet (" . $objet1->label . ") créé le " . $objet1->fmtDate() . " à " . $objet1->fmtHeure() .
    ", différence 1 : " . $objet1->difference($val1) . ", différence 2 : " . $objet1->difference($val2) .
    ", estFutur 1 : " . ($objet1->estFutur($val1) ? "Oui" : "Non") . ", estFutur 2 : " . ($objet1->estFutur($val2) ? "Oui" : "Non");
echo "<br />";
echo "Objet (" . $objet2->label . ") créé le " . $objet2->fmtDate() . " à " . $objet2->fmtHeure() .
    ", différence 1 : " . $objet2->difference($val1) . ", différence 2 : " . $objet2->difference($val2) .
    ", estFutur 1 : " . ($objet2->estFutur($val1) ? "Oui" : "Non") . ", estFutur 2 : " . ($objet2->estFutur($val2) ? "Oui" : "Non");
echo "<br />";

?>