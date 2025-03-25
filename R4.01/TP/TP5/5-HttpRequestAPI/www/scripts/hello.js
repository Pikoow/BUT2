/**
 * Réagit à la réception du contenu dynamique.
 * @param _event L'événement.
 */
function sayHello(_event) {
    if (this.readyState === 4 && this.status === 200) {
        document.getElementById("m_message").innerHTML = this.responseText;
    }
}

/**
 * Réagit à l'action du bouton.
 */
function handleSayHello() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = sayHello;
    xhr.open("GET", "http://localhost:8081/3-ServletAPI/hello?name=Bob", true);
    xhr.send();
}