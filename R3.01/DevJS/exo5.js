let trouve = false;
let valeur = Math.round(Math.random() * 100);
let nombreTentatives = 0;
alert(valeur);

while (trouve == false) {
    nombreTentatives++;
    let nombre = parseInt(prompt('Choisissez une valeur'));
    if (nombre == valeur) {
        alert(`Vous avez trouvé le nombre ${valeur} en ${nombreTentatives} tentatives !`);
        trouve = true;
    } else if (nombre > valeur) {
        alert('Le nombre que vous cherchez est plus petit !');
    } else if (nombre < valeur) {
        alert('Le nombre que vous cherchez est plus grand !')
    }
}