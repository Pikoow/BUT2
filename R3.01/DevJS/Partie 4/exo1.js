elem = document.getElementsByClassName("urgent");
for (let i = 0; i < elem.length; i++) {
    elem[i].style.setProperty("background-color", "red");
}

let css = 'h1 { color: blue; }';
let head = document.head;
let style = document.createElement('style');

head.appendChild(style);
style.appendChild(document.createTextNode(css));