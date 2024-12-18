public class Desarmee implements EtatAlarme {

    @Override
    public void armer(Alarme alarme) {
        System.out.println("l'alarme est armée");
        alarme.setEtat(new Armee());
    }

    @Override
    public void desarmer(Alarme alarme) {
        System.out.println("l'alarme est déjà désarmée");
    }

    @Override
    public void activer(Alarme alarme) {
        System.out.println("l'alarme ne peut pas être activée, elle doit être armée d'abord");
    }

    @Override
    public void retentir(Alarme alarme) {
        System.out.println("l'alarme ne peut pas retentir, elle est désarmée.");
    }
}
