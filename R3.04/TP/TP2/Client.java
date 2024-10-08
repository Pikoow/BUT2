public class Client {
    public static void main(String[] args) {
        FabriquePizza fabriqueBretagne = new FabriquePizzaBretagne();
        Pizza pizzaBretagne = new Pizza(fabriqueBretagne);
        pizzaBretagne.afficherDetails();

        FabriquePizza fabriqueAlsace = new FabriquePizzaAlsace();
        Pizza pizzaAlsace = new Pizza(fabriqueAlsace);
        pizzaAlsace.afficherDetails();
    }
}
