<?php
include('connect_params.php');
try {
    $dbh = new PDO("$driver:host=$server;dbname=$dbname", $user, $pass);

    # $matr = '7934';
    $metr = '7782';

    $stmt = $dbh->prepare("SELECT sup FROM distribill_s3._employe WHERE sup = '$matr'");
    $stmt->execute();
    $result = $stmt->fetchAll();
    echo "<pre>";
    print_r($result);
    echo "</pre>";
    
    if ($result == 1) {
        echo "Vous ne pouvez pas supprimez un employé qui n'est pas en bas de l'échelle !";
    } else {
        $stmt = $dbh->prepare(
        "DELETE FROM distribill_s3._personnel WHERE matr = '$matr'");
        $stmt->execute();
        $stmt = $dbh->prepare(
        "DELETE FROM distribill_s3._personnel WHERE matr = '$matr'");
        $stmt->execute();
        echo "Employé supprimé !";
    }
    
    $dbh = null;
} catch (PDOException $e) {
    print "Erreur !: " . $e->getMessage() . "<br/>";
    die();
}
?>
