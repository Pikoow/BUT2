public class StationMeteo implements Observer {
    private String nom;
    private int sommeTemperatures = 0;
    private int nombreMesures = 0;

    public StationMeteo(String nom) {
        this.nom = nom;
    }

    @Override
    public void update(int temperature) {
        sommeTemperatures += temperature;
        nombreMesures++;
        afficherMoyenne();
    }

    private void afficherMoyenne() {
        double moyenne = (double) sommeTemperatures / nombreMesures;
        System.out.println("Station " + nom + " - Moyenne des températures : " + moyenne);
    }
}
