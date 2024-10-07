public class TestPorte {
    public static void main(String[] args) {
        Porte porte = new Porte();

        // Simulation des actions
        porte.appuyer(); // La porte commence à s'ouvrir
        porte.terminer(); // La porte est maintenant ouverte
        porte.appuyer(); // La porte commence à se fermer
        porte.terminer(); // La porte est maintenant fermée
        porte.appuyer(); // La porte commence à s'ouvrir
        porte.appuyer(); // La porte s'arrête et commence à se refermer
    }
}
