let planete = "Lune,Terre,Mars"
let tabPlanete1 = planete.split(",");
console.log(tabPlanete1);

tabPlanete1.shift();
console.log(tabPlanete1);

let tabPlanete2 = ["Cérès", "Saturne", "Pluton"]
let tabPlanete = tabPlanete1.concat(tabPlanete2);
console.log(tabPlanete);

tabPlanete.unshift("Mercure", "Vénus");
console.log(tabPlanete);

tabPlanete.pop();
console.log(tabPlanete);

tabPlanete.push("Uranus");
console.log(tabPlanete);

let index = tabPlanete.indexOf("Cérès");
console.log(index);

tabPlanete[index] = "Jupiter";
console.log(tabPlanete);

console.log(tabPlanete.includes("Lune"));

let tabPlanetes = tabPlanete.slice(2, 4);
console.log(tabPlanetes);
console.log(tabPlanetes.at(-1));