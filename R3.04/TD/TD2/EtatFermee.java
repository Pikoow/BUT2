// Etat Fermée
class EtatFermee implements Etat {
    @Override
    public void appuyer(Porte porte) {
        System.out.println("La porte commence à s'ouvrir.");
        porte.setEtat(new EtatOuverture());
    }

    @Override
    public void terminer(Porte porte) {
        System.out.println("La porte est déjà fermée.");
    }
}
