<?php

stream_context_set_default([
    'http' => [
        'proxy' => '129.20.239.11:3128'
    ]
]);

?>

<table>
    <tr>
        <th>Nom du pays</th>
        <th>CCA3</th>
        <th>Capitale</th>
        <th>Drapeau</th>
    <tr>

<?php

for ($valeur = 0 ; $valeur < count($decodeJson) ; $valeur++) {

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