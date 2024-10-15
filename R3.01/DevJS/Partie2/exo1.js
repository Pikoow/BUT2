let message = prompt("Quel mot voulez-vous traduire ?");

formattedMessage = message.toLowerCase().trim();

function louchebem($message) {
    let premiereLettre = message.charAt(0).toLowerCase();

    let fin;

    switch (premiereLettre) {
        case "b":
            fin = "em";
            break;

        case "c":
            fin = "ès";
            break;

        case "d":
            fin = "é";
            break;

        case "f":
            fin = "oque";
            break;

        case "m":
            fin = "uche";
            break;

        case "p":
            fin = "é";
            break;

        default:
            fin = "ès";
            break;
    }

    message = message.substring(1, message.length);

    return `L${message}${premiereLettre}${fin}`;
}

console.log(louchebem(formattedMessage));