<?php
include('connect_params.php');
try {
    $dbh = new PDO("$driver:host=$server;dbname=$dbname", $user, $pass);

    $newnome = 'BOBOBOB';
    $matr = '9322';

    $stmt = $dbh->prepare(
    "UPDATE distribill_s3._personnel SET nome = '$newnome' WHERE matr = '$matr'");
    $stmt->execute();

    if ($stmt->rowCount() > 0) {
        echo "Le nom a été update !";
    } else {
        echo "Le matricule n'existe pas !";
    }
    
    $dbh = null;
} catch (PDOException $e) {
    print "Erreur !: " . $e->getMessage() . "<br/>";
    die();
}
?>
