let uneDate = new Date();
let jour = uneDate.getDay();

alert(`${((jour == 0) || (jour == 6)) ? "Bon weekend" : "Bonne semaine"}`);