# TD 3

Etant donné ... et ...
quand ...
alors ... et ...

## COMPTES

### Créer un compte

Etant donné que je suis sur la page de création et que j'ai entré une adresse email valide et que j'ai entré un mot de passe assez fort
quand je clique sur le bouton "Créer un compte"
alors mon compte est créer et j'arrive sur la page d'accueil du site

Etant donné que je suis sur la page de création et que j'ai entré une adresse email déja utilisée et que j'ai entré un mot de passe assez fort
quand je clique sur le bouton "Créer un compte"
alors mon compte n'est pas créer et je vois un erreur "Email déjà utilisé"

Etant donné que je suis sur la page de création et que j'ai entré une adresse email non valide et que j'ai entré un mot de passe assez fort
quand je clique sur le bouton "Créer un compte"
alors mon compte n'est pas créer et je vois un erreur "Email non valide"

Etant donné que je suis sur la page de création et que j'ai entré une adresse email valide et que j'ai entré un mot de passe pas assez fort
quand je clique sur le bouton "Créer un compte"
alors mon compte n'est pas créer et je vois un erreur "Mot de passe trop faible"

### Récupérer son mot de passe par mail

Etant donné que je suis sur la page de récupération et que j'ai entré une adresse email valide
quand je clique sur le bouton "Recevoir son mot de passe"
alors je reçois un email avec mon mot de passe

Etant donné que je suis sur la page de récupération et que j'ai entré une adresse email non valide
quand je clique sur le bouton "Recevoir son mot de passe"
alors je vois un erreur "Email non valide"

Etant donné que je suis sur la page de récupération et que j'ai entré une adresse email raccordé à aucun compte
quand je clique sur le bouton "Recevoir son mot de passe"
alors je vois une erreur "Email raccordé à aucun compte"

## AVIS

### Répondre à un avis

Etant donné que je suis sur un avis et que j'ai entré un titre et un contenu
quand je clique sur le bouton "Répondre"
alors ma réponse est publiée

Etant donné que je suis sur un avis et que je n'ai entré de titre
quand je clique sur le bouton "Répondre"
alors ma réponse n'est pas publiée et je vois un erreur "Vous devez rentrer un titre"

Etant donné que je suis sur un avis et que je n'ai entré de contenu
quand je clique sur le bouton "Répondre"
alors ma réponse n'est pas publiée et je vois un erreur "Vous devez rentrer du contenu"

### Publier un avis

Etant donné que je suis sur la page d'une annonce et que j'ai entré une titre, un contenu et une note
quand je clique sur le bouton "Publier mon avis"
alors mon avis est publié

Etant donné que je suis sur la page d'une annonce et que je n'ai pas entré de titre
quand je clique sur le bouton "Publier mon avis"
alors mon avis n'est pas publié et je vois une erreur "Vous devez rentrer un titre"

Etant donné que je suis sur la page d'une annonce et que je n'ai pas entré de contenu
quand je clique sur le bouton "Publier mon avis"
alors mon avis n'est pas publié et je vois une erreur "Vous devez rentrer un contenu"

Etant donné que je suis sur la page d'une annonce et que je n'ai pas entré de note
quand je clique sur le bouton "Publier mon avis"
alors mon avis n'est pas publié et je vois une erreur "Vous devez rentrer une note"
