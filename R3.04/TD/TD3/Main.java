public class Main {
    public static void main(String[] args) {
        // Création des stations
        StationMeteo stationEurope = new StationMeteo("Europe");
        StationMeteo stationFrance = new StationMeteo("France");
        StationMeteo stationUK = new StationMeteo("UK");

        // Création des postes météorologiques
        PosteMeteo posteBrest = new PosteMeteo();
        PosteMeteo posteParis = new PosteMeteo();
        PosteMeteo posteLyon = new PosteMeteo();
        PosteMeteo posteLondres = new PosteMeteo();
        PosteMeteo posteSouthampton = new PosteMeteo();

        // Association des stations aux postes
        posteBrest.addObserver(stationEurope);
        posteBrest.addObserver(stationFrance);
        posteBrest.addObserver(stationUK);

        posteParis.addObserver(stationEurope);
        posteParis.addObserver(stationFrance);

        posteLyon.addObserver(stationEurope);
        posteLyon.addObserver(stationFrance);

        posteLondres.addObserver(stationEurope);
        posteLondres.addObserver(stationUK);

        posteSouthampton.addObserver(stationEurope);
        posteSouthampton.addObserver(stationFrance);
        posteSouthampton.addObserver(stationUK);

        // Exemple d'une mesure par le poste de Brest
        posteBrest.saisirTemperature();
        posteParis.saisirTemperature();
        posteLyon.saisirTemperature();
        posteLondres.saisirTemperature();
        posteSouthampton.saisirTemperature();
    }
}
