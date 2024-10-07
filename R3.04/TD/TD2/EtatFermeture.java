// Etat En cours de fermeture
class EtatFermeture implements Etat {
    @Override
    public void appuyer(Porte porte) {
        System.out.println("La porte s'arrête et commence à s'ouvrir.");
        porte.setEtat(new EtatOuverture());
    }

    @Override
    public void terminer(Porte porte) {
        System.out.println("La porte est maintenant fermée.");
        porte.setEtat(new EtatFermee());
    }
}
