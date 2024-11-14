console.log("oui");

let image = document.getElementById("monImage");

image.addEventListener("mouseover", lesdeux);
image.addEventListener("mouseout", lesdeux);

function permuterImage() {
    image.src = "images/voitureRouge.jpg";
}

function restaurerImage() {
    image.src = "images/voitureJaune.jpg";
}

function lesdeux(event) {
    if (event.type === "mouseover") {
        image.src = "images/voitureRouge.jpg";
    } else {
        image.src = "images/voitureJaune.jpg";
    }
}