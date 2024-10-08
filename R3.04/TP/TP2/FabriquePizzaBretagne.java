public class FabriquePizzaBretagne extends FabriquePizza {
    @Override
    public Pate creerPate() {
        return new PateFine();
    }

    @Override
    public Garniture creerGarniture() {
        return new GarnitureFromageChevreEtAndouille();
    }
}
