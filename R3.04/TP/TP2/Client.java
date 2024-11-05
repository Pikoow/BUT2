public class Client {
    public static void main(String[] args) {
        Fabrique fabriqueBretagne = new FabriqueBretagne();
        Pizza pizzaBretagne = new Pizza(fabriqueBretagne);
        pizzaBretagne.afficherDetails();

        Fabrique fabriqueAlsace = new FabriqueAlsace();
        Pizza pizzaAlsace = new Pizza(fabriqueAlsace);
        pizzaAlsace.afficherDetails();
    }
}
