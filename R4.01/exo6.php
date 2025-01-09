<?php

stream_context_set_default([
    'http' => [
        'proxy' => '129.20.239.11:3128'
    ]
]);

$listePays =  file_get_contents('https://restcountries.com/v3.1/all?fields=name,cca3,capital,flags');

$decodeJson = json_decode($listePays, true);

?>

<table>
    <tr>
        <th>Nom du pays</th>
        <th>CCA3</th>
        <th>Capitale</th>
        <th>Drapeau</th>
        <th>Language</th>
        <th>Devise</th>
    <tr>

<?php

for ($valeur = 0 ; $valeur < 10 ; $valeur++) {

?>

    <tr>
        <td><?php echo htmlentities($decodeJson[$valeur]['name']['common']) ?></td>
        <td><?php echo htmlentities($decodeJson[$valeur]['cca3']) ?></td>
        <td><?php echo htmlentities($decodeJson[$valeur]['capital']['0']) ?></td>
        <td><img src="<?php echo htmlentities($decodeJson[$valeur]['flags']['png']) ?>"></td>
    </tr>
<?php

}

?>

<button href="http://localhost:8080/exo6.php?page=<?php $page + 1 ?>">Précédent</button>
<button href="http://localhost:8080/exo6.php?page=<?php $page - 1 ?>">Suivant</button>
