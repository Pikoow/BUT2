<?php
    $file = file_get_contents('./data');
    $totalArticles = unserialize($file);

    $currentPage = isset($_GET['page']) && is_numeric($_GET['page']) ? (int)$_GET['page'] : 1;

    $articlesPerPage = 8;
    $offset = ($currentPage - 1) * $articlesPerPage;
    $limit = $articlesPerPage;

    $articles = array_slice($totalArticles, $offset, $limit, true);

    $totalPages = ceil(count($totalArticles) / $articlesPerPage);

    $previousPage = $currentPage > 1 ? $currentPage - 1 : 1;
    $nextPage = $currentPage < $totalPages ? $currentPage + 1 : $totalPages;

    $totalHT = 0;
    $totalStock = 0;
    $totalTTC = 0;
    $totalVendu = 0;

    foreach ($totalArticles as $article) {
        $totalHT += $article['prix'];
        $totalStock += $article['stock'];
        $totalTTC += $article['prix'] * (1 + ($article['tva'] / 100));
        $totalVendu += $article['vendu'];
    }
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <link rel="stylesheet" type="text/css" href="style.css">
        <title>Formulaire</title>
    </head>
    <body>
        <table>
            <tr>
                <th>Code</th>
                <th>Libellé</th>
                <th>Prix HT</th>
                <th>Taux TVA</th>
                <th>Montant TVA</th>
                <th>Prix TTC</th>
                <th>Stock</th>
                <th>Quantité vendue</th>
                <th>Actions</th>
            </tr>
            <?php
                foreach ($articles as $key => $article) {
            ?>
            <tr>
                <td>
                    <?php
                        echo $key;
                    ?>
                </td>
                <td>
                    <?php
                        echo $article['libelle'];
                    ?>
                </td>
                <td>
                    <?php
                        echo $article['prix'];
                    ?>
                </td>
                <td>
                    <?php
                        echo $article['tva'];
                    ?>
                </td>
                <td>
                    <?php
                        echo $article['prix'] * ($article['tva'] / 100);
                    ?>
                </td>
                <td>
                    <?php
                        echo $article['prix'] * (1 + ($article['tva'] / 100));
                    ?>
                </td>
                <td>
                    <?php
                        echo $article['stock'];
                    ?>
                </td>
                <td>
                    <?php
                        echo $article['vendu'];
                    ?>
                </td>
                <td>
                    <a href="stock.php?code=<?php echo $key;?>&qte=10">+10</a>
                    <a href="stock.php?code=<?php echo $key;?>&qte=-1">Vente</a>
                </td>
            </tr>
            <?php
                }
            ?>
        </table>

        <div>
            <p>Total HT du stock: <?php echo $totalHT; ?></p>
            <p>Quantité totale d'articles en stock: <?php echo $totalStock; ?></p>
            <p>Total TTC des produits déjà vendus: <?php echo $totalTTC; ?></p>
            <p>Quantité totale d'articles vendus: <?php echo $totalVendu; ?></p>
        </div>

        <div>
            <?php 
                if ($currentPage !== 1) {
            ?>
            <a href="?page=<?php echo $previousPage; ?>">Page précédente</a>
            <?php } ?>
            <?php
                $maxPage = ceil(count($totalArticles)/$articlesPerPage);
                if ($currentPage < $maxPage) {
            ?>
            <a href="?page=<?php echo $nextPage; ?>">Page suivante</a>
            <?php }?>
        </div>
    </body>
</html>
