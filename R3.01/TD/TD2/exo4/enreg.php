<?php
// Start the session at the beginning of the script
session_start();

$file = $_FILES['photo'];
$fileTmpName = $file['tmp_name'];
$fileType = $file['type'];

// Validate and store the uploaded image
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

// Get form data
$nom = $_POST["nom"];
$prenom = $_POST["prenom"];
$email = $_POST["email"];

// Store the data in the session instead of a file
if (!isset($_SESSION['users'])) {
    $_SESSION['users'] = [];  // Initialize the session variable if it doesn't exist
}

$_SESSION['users'][] = [
    'nom' => $nom,
    'prenom' => $prenom,
    'email' => $email,
    'avatar' => $name
];

// Redirect the user to the list page
header("Location: liste.php");
exit();
