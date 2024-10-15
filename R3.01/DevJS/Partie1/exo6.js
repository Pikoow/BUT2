function calculPerimEtSurf() {
    let perim;
    let surf;
    let largeur;
    let longueur;
    if (arguments.length === 1) {
      cote = arguments[0];
      perim = 4 * cote;
      surf = cote * cote; 
    } else if (arguments.length === 2) {
      largeur = arguments[0];
      longueur = arguments[1];
      perim = 2*largeur + 2*longueur;
      surf = longueur * largeur;
    }
    alert(`Le perimetre est ${perim}m et la surface est ${surf}m² !`);
}
  
calculPerimEtSurf(4, 5);
calculPerimEtSurf(5);