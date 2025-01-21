<?php

stream_context_set_default([
    'http' => [
        'proxy' => '129.20.239.11:3128'
    ]
]);

$listePays = file_get_contents('https://restcountries.com/v3.1/all?fields=name,cca3,capital,flags,currencies,languages');

$decodeJson = json_decode($listePays, true);

$currentPage = isset($_GET['page']) && is_numeric($_GET['page']) ? (int)$_GET['page'] : 1;
$articlesPerPage = 10;
$offset = ($currentPage - 1) * $articlesPerPage;

$articles = array_slice($decodeJson, $offset, $articlesPerPage);

$totalPages = ceil(count($decodeJson) / $articlesPerPage);
$previousPage = $currentPage > 1 ? $currentPage - 1 : 1;
$nextPage = $currentPage < $totalPages ? $currentPage + 1 : $totalPages;

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

for ($valeur = $currentPage - 1 * 10 ; $valeur < $currentPage * 10 ; $valeur++) {

?>
    <tr>
        <td><?php echo htmlentities($decodeJson[$valeur]['name']['common']) ?></td>
        <td><?php echo htmlentities($decodeJson[$valeur]['cca3']) ?></td>
        <td><?php echo htmlentities($decodeJson[$valeur]['capital']['0']) ?></td>
        <td><img src="<?php echo htmlentities($decodeJson[$valeur]['flags']['png']) ?>"></td>
        <td><?php echo htmlentities($decodeJson[$valeur]['languages'] ?? ['N/A']); ?></td>
        <td><?php echo htmlentities($decodeJson[$valeur]['currencies'] ?? ['N/A']); ?></td>
    </tr>
<?php

}

?>

<div>
    <?php if ($currentPage > 1): ?>
        <a href="?page=<?php echo $previousPage; ?>">Page précédente</a>
    <?php endif; ?>
    <?php if ($currentPage < $totalPages): ?>
        <a href="?page=<?php echo $nextPage; ?>">Page suivante</a>
    <?php endif; ?>
</div>