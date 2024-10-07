<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
   <ul>
      <?php
         require_once('../regions.php');
         $i = null;
         const PAGE_SIZE = 5;

         if (isset($_GET['page'])) {
            $pageNumber = $_GET['page'];
         } else {
            $pageNumber = 1;
         }

         $nouveauTableau = array_slice($regions, ($pageNumber * PAGE_SIZE) - PAGE_SIZE, PAGE_SIZE);
         
         foreach ($nouveauTableau as $nomDept => $value) {
      ?>
      <li>
         <?php
            echo htmlentities($nomDept); }
         ?>
      </li>
   </ul>

   <a href="http://localhost:8888/exo3-regions.php?page=<?php echo $pageNumber - 1 ?>">Page précedente</a>
   <a href="http://localhost:8888/exo3-regions.php?page=<?php echo $pageNumber + 1 ?>">Page suivante</a>
</body>
</html>
