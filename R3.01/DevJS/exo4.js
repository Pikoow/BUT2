let uneDate = new Date();
let jour = uneDate.getDay();

switch (jour) {
    case 0:
        jour = 'dimanche';
        break;

    case 1:
        jour = 'lundi';
        break;

    case 2:
        jour = 'mardi';
        break;

    case 3:
        jour = 'mercredi';
        break;

    case 4:
        jour = 'jeudi';
        break;

    case 5:
        jour = 'vendredi';
        break;

    case 6:
        jour = 'samedi';
        break;

    default:
        break;
}

alert(`On est ${jour} !`);