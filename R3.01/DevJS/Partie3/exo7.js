let paragraphe = document.querySelector("p");

function fonction() {
    document.querySelectorAll("p")[1].textContent = "Texte de remplacement";
}

paragraphe.addEventListener("mouseover", fonction);