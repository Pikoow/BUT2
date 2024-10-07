#!/usr/bin/php

<?php 
    /* chmod u+x nom.php */
    $lines = file('./articles');
    $articles = [];
    $lines = file('./articles');
    foreach ($lines as $line) {
        list($id, $libelle, $prix, $tva) = explode(",", $line);
        $articles[$id] = [
            'libelle' => $libelle,
            'prix' => $prix,
            'tva' => $tva,
            'stock' => 0,
            'vendu' => 0
        ];

    }
    print_r($articles);
    file_put_contents('./data', serialize($articles));
?>