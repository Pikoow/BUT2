public class FabriquePizzaAlsace extends FabriquePizza {
    @Override
    public Pate creerPate() {
        return new PateEpaisse();
    }

    @Override
    public Garniture creerGarniture() {
        return new GarnitureMunsterEtPrune();
    }
}
