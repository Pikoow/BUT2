<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
   <table>
      <tr>
         <th scope="col">Nom</th>
      </tr>
      <?php
        require_once('../regions.php');

        foreach ($regions as $nomRegion => $numDept) {
      ?>
      <tr>
         <td>
            <?php
               echo htmlentities($nomRegion); }
            ?>
         </td>
      </tr>
   </table>
</body>
</html>