// Classe Porte
public class Porte {
    private Etat etat;

    public Porte() {
        this.etat = new EtatFermee(); // Initialement, la porte est fermée
    }

    public void setEtat(Etat etat) {
        this.etat = etat;
    }

    public void appuyer() {
        etat.appuyer(this);
    }

    public void terminer() {
        etat.terminer(this);
    }
}
