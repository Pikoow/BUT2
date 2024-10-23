let fenetre;

function ouvrir() {
    fenetre = open("", "popUp", "width=250,height=100");
    fenetre.document.write("<h1>Hello world !</h1>");
    fenetre.focus();
}

function placer() {
    fenetre.moveTo(100, 250);
}

function decaler() {
    fenetre.moveBy(200, 0);
}

function agrandir() {
    fenetre.resizeBy(500, 200);
}

function fermer() {
    fenetre.close();
}

ouvrir();
placer();
decaler();
agrandir();