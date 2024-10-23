let article = document.querySelector('article');
let nom = article.nodeName;
let type = article.nodeType;

let p1 = document.createElement('p');
p1.textContent = `Nom : ${nom}`;
let p2 = document.createElement('p');
p2.textContent = `Type : ${type}`;

article.appendChild(p1);
article.appendChild(p2);