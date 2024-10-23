let header = document.querySelector("header").classList;
let element1 = document.getElementsByTagName("p")[0];
let element2 = document.getElementsByTagName("p")[1];

console.log(header)

element1.textContent = header[0];
element2.textContent = header[1];