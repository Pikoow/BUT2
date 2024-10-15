let plaque = prompt("Quelle est votre plaque ?");

function verifPlaque(plaque) {
    let motif = /^[1-9][0-9]{1,3}\s[A-HJ-NP-TV-Z]{2,3}\s(0[1-9]|[1-8][0-9]|9[0-5]|2A|2B)$/;
    if (motif.test(plaque)) {
        console.log("Validé !");
    } else {
        console.log("Pas validé !");
    }
}

verifPlaque(plaque);