public final class Inspecteur extends Personne {
    private static Inspecteur INSTANCE;

    private Inspecteur() {
        super("Inspecteur");
    }

    public static Inspecteur getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new Inspecteur();
        }

        return INSTANCE;
    }
}
