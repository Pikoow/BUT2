<?php
include('connect_params.php');
try {
    $dbh = new PDO("$driver:host=$server;dbname=$dbname", $user, $pass);

    $nodept = '50';
    $nomdept = "BOB";
    $lieu = "BOBLAND";

    $stmt = $dbh->prepare(
    "INSERT INTO distribill_s3._dept(nodept, nomdept, lieu) VALUES('$nodept', '$nomdept','$lieu')");
    $stmt->execute();
    
    $dbh = null;
} catch (PDOException $e) {
    print "Erreur !: " . $e->getMessage() . "<br/>";
    die();
}
?>