public class Main {
    public static void main(String[] args) {
        /*
        // Tests états
        
        Alarme alarme = new Alarme();
        
        alarme.armer();   // passage état armé
        alarme.activer(); // passage état activé
        alarme.retentir(); // retentissement
        alarme.desarmer(); // passage état désarmé

        alarme.activer(); // ne peut pas être activée (pas armée)
        alarme.retentir(); // ne peut pas retentir (pas armée)
        alarme.armer(); // s'arme
        alarme.retentir(); // ne peut pas retentir (pas activée)
        
        */

        // Tests observateurs
        Entite entrepriseSecurite = new Entite("Entreprise de Sécurité");
        Entite dirigeant = new Entite("Dirigeant de l'entreprise");

        Alarme alarme2 = new Alarme();

        alarme2.ajouterObservateur(entrepriseSecurite);
        alarme2.ajouterObservateur(dirigeant);

        alarme2.armer();   // passage état armé
        alarme2.activer(); // passage état activé + envoi d'une notification
        alarme2.retentir(); // retentissement
        alarme2.desarmer(); // passage état désarmé + envoi d'une notification
    }
}
