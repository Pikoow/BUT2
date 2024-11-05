<?php

class Coureur {
    public $numero;
    public $nom;
    public $prenom;

    function __construct($id, $name, $surname) {
        $this->numero = $id;
        $this->nom = $name;
        $this->prenom = $surname;
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

