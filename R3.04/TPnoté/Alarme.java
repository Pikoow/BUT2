import java.util.ArrayList;
import java.util.List;

public class Alarme {
    private EtatAlarme etat; // état de l'alarme
    private List<Observateur> observateurs; // liste des personnes à notifier

    public Alarme() {
        this.etat = new Desarmee(); // commence à désarmée
        this.observateurs = new ArrayList<>();
    }

    public void setEtat(EtatAlarme etat) {
        this.etat = etat;
    }

    // changement d'états de l'alame
    public void armer() {
        etat.armer(this);
    }

    public void desarmer() {
        etat.desarmer(this);
    }

    public void activer() {
        etat.activer(this);
    }

    public void retentir() {
        etat.retentir(this);
    }

    // notifier et ajouter obsevateurs
    public void ajouterObservateur(Observateur observateur) {
        observateurs.add(observateur);
    }

    public void notifierObservateurs(String message) {
        for (Observateur observateur : observateurs) {
            observateur.recevoirAlerte(message);
        }
    }
}
