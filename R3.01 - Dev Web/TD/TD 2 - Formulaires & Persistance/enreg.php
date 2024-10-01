<?php
$dataFile = 'data.txt';

$file = $_FILES['photo'];
$fileTmpName = $file['tmp_name'];
$fileType = $file['type'];

switch ($fileType) {
    case 'image/png':
        $name = time() . ".png";
        break;
    
    case 'image/gif':
        $name = time() . ".gif";
        break;

    case 'image/jpeg':
        $name = time() . ".jpeg";
        break;

    case 'image/webp':
        $name = time() . ".webp";
        break;

    default:
        echo("Le format de l'avatar n'est pas valide (doit être png, gif, jpeg ou webp)");
        exit();
}

$destination = "avatars/$name";
move_uploaded_file($fileTmpName, $destination);

$nom = $_POST["nom"];
$prenom = $_POST["prenom"];
$email = $_POST["email"];

$data = [];
if (file_exists($dataFile)) {
    $data = unserialize(file_get_contents($dataFile));
}

$data[] = [
    'nom' => $nom,
    'prenom' => $prenom,
    'email' => $email,
    'avatar' => $name
];

file_put_contents($dataFile, serialize($data));
?>