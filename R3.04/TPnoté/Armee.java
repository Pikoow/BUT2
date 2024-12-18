public class Armee implements EtatAlarme {

    @Override
    public void armer(Alarme alarme) {
        System.out.println("l'alarme est déjà armée");
    }

    @Override
    public void desarmer(Alarme alarme) {
        System.out.println("l'alarme est maintenant désarmée");
        alarme.setEtat(new Desarmee());
    }

    @Override
    public void activer(Alarme alarme) {
        System.out.println("l'alarme est activée en raison de l'ouverture de la porte");
        alarme.setEtat(new Activee());
        alarme.notifierObservateurs("l'alarme a été activée");
    }

    @Override
    public void retentir(Alarme alarme) {
        System.out.println("l'alarme ne retentit pas, elle n'est pas activée");
    }
}
