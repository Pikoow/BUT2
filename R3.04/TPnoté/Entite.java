public class Entite implements Observateur {
    private String nom;

    public Entite(String nom) {
        this.nom = nom;
    }

    public String getNom() {
        return nom;
    }

    @Override
    public void recevoirAlerte(String message) {
        System.out.println("Alerte reçue par " + nom + " : " + message);
    }
}
