public class tp1app {
    public static void main(String[] args) {
        System.out.println("Nom Inspecteur : " + Inspecteur.getInstance().getNom());

        Inspecteur.getInstance().setNom("New name");

        System.out.println("Nom Inspecteur : " + Inspecteur.getInstance().getNom());
    }
}
