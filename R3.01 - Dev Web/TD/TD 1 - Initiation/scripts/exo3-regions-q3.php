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

         $nouveauTableau = array_slice($regions, ($pageNumber - 1) * PAGE_SIZE, PAGE_SIZE);
         
         foreach ($nouveauTableau as $nomDept => $value) {
      ?>
      <li>
         <a href="http://localhost:8888/exo3-regions-detail.php?page=<?php echo urlencode($nomDept) ?>">
            <?php
               echo htmlentities($nomDept); }
            ?>
         </a>
      </li>
   </ul>

   <?php 
      if ($pageNumber <= 1) {
   ?>
   <a href="http://localhost:8888/exo3-regions-q3.php?page=<?php echo $pageNumber - 1 ?>">Page précedente</a>
   <?php }
      $maxPage = ceil(sizeof($regions)/PAGE_SIZE);
      if($pageNumber>$maxPage) {
   ?>
   <a href="http://localhost:8888/exo3-regions-q3.php?page=<?php echo $maxPage ?>">Page suivante</a>
   <?php } ?>
</body>
</html>
