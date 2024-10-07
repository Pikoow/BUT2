// Etat Ouverte
class EtatOuverte implements Etat {
    @Override
    public void appuyer(Porte porte) {
        System.out.println("La porte commence à se fermer.");
        porte.setEtat(new EtatFermeture());
    }

    @Override
    public void terminer(Porte porte) {
        System.out.println("La porte est déjà ouverte.");
    }
}
