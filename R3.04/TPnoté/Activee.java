public class Activee implements EtatAlarme {

    @Override
    public void armer(Alarme alarme) {
        System.out.println("l'alarme est déjà activée");
    }

    @Override
    public void desarmer(Alarme alarme) {
        System.out.println("l'alarme est désactivée");
        alarme.setEtat(new Desarmee());
        alarme.notifierObservateurs("l'alarme a été désactivée");
    }

    @Override
    public void activer(Alarme alarme) {
        System.out.println("l'alarme est déjà activée");
    }

    @Override
    public void retentir(Alarme alarme) {
        System.out.println("l'alarme retentit");
    }
}
