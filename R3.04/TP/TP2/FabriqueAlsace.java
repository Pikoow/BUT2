public class FabriqueAlsace extends Fabrique {
    @Override
    public Pate getPate() {
        return new PateEpaisse();
    }

    @Override
    public List<Garniture> getGarnitures() {
        List<Garniture> garnitures = new ArrayList<>();

        garnitures.add(new GarnitureMunster());
        garnitures.add(new GarnitureEauViePrune());

        return garnitures;
    }

    @Override
    public CuissonMode getModeCuisson() {
        return new CuissonVive();
    }

    @Override
    public PizzaFromage creerPizzaFromage() {
        List<Garniture> ingredients = new ArrayList<>();
        ingredients.add(new GarnitureMarinara());

        return new PizzaFromage(this, ingredients);
    }

    @Override
    public PizzaBarbecue creerPizzaBarbecue() {
        List<Garniture> ingredients = new ArrayList<>();
        ingredients.add(new GarnitureTomate());
        ingredients.add(new GarnitureSauceBarbecue());
        ingredients.add(new GarnitureBacon());

        return new PizzaBarbecue(this, ingredients);
    }
}
