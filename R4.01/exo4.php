<?php

// IUT
stream_context_set_default([
    'http' => [
        'proxy' => '129.20.239.11:3128'
    ]
]);

$contenu = file_get_contents('https://restcountries.com/v3.1/all?fields=name,cca3,capital');

$decode = json_decode($contenu, true);

?>

<form action="exo4.php" method="POST" enctype="multipart/form-data">
    <label for="nom">Nom du pays</label>
    <input type="text" id="name" name="name" />

    <input type="submit" value="Chercher" />
</form>

<?php
if (isset($_POST["name"])) {
    ?>
        <table>
            <tr>
                <th>Nom</th>
                <th>CCA3</th>
                <th>Capitale</th>
            </tr>
            <tr>
                <?php
                for ($i=0; $i < count($decode); $i++) {
                    if (str_contains(strtolower($decode[$i]["name"]["common"]), strtolower($_POST["name"]))) {
                    ?>
                        <td>
                    <?php
                        echo $decode[$i]["name"]["common"];
                    ?>
                        </td>
                        <td>
                    <?php
                        echo $decode[$i]["cca3"];
                    ?>
                        </td>
                        <td>
                    <?php
                        echo $decode[$i]["capital"]["0"];
                    ?>
                        </td>
                        </tr>
                    <?php
                    }
                }
                ?>
            </tr>
    <?php
} else {
    ?>
        <table>
            <tr>
                <td>Nom</td>
                <td>CCA3</td>
                <td>Capitale</td>
            </tr>
        <?php

        for ($i=0; $i < count($decode); $i++) {
        ?>
            <tr>
            <td>
        <?php
            echo $decode[$i]["name"]["common"];
        ?>
            </td>
            <td>
        <?php
            echo $decode[$i]["cca3"];
        ?>
            </td>
            <td>
        <?php
            echo $decode[$i]["capital"]["0"];
        ?>
            </td>
            </tr>
        <?php
        }

        ?>
        </table>
    <?php
}
?>
