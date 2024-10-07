// Etat En cours d'ouverture
class EtatOuverture implements Etat {
    @Override
    public void appuyer(Porte porte) {
        System.out.println("La porte s'arrête et commence à se refermer.");
        porte.setEtat(new EtatFermeture());
    }

    @Override
    public void terminer(Porte porte) {
        System.out.println("La porte est maintenant ouverte.");
        porte.setEtat(new EtatOuverte());
    }
}
