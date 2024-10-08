public class Pizza {
    private Pate pate;
    private Garniture garniture;

    public Pizza(FabriquePizza fabrique) {
        this.pate = fabrique.creerPate();
        this.garniture = fabrique.creerGarniture();
    }

    public void afficherDetails() {
        System.out.println("Pizza avec " + pate.getDescription() + " et " + garniture.getDescription());
    }
}
