public class FabriqueBretagne extends Fabrique {
    @Override
    public Pate getPate() {
        return new PateEpaisse();
    }

    @Override
    public List<Garniture> getGarnitures() {
        List<Garniture> garnitures = new ArrayList<>();

        garnitures.add(new GarnitureAndouille());
        garnitures.add(new GarnitureFromageChevre());

        return garnitures;
    }

    @Override
    public CuissonMode getModeCuisson() {
        return new CuissonLente();
    }

    @Override
    public PizzaFromage creerPizzaFromage() {
        List<Garniture> ingredients = new ArrayList<>();
        ingredients.add(new GarnitureGorgonzola());
        ingredients.add(new GarnitureAil());

        return new PizzaFromage(this, ingredients);
    }

    @Override
    public PizzaBarbecue creerPizzaBarbecue() {
        List<Garniture> ingredients = new ArrayList<>();
        ingredients.add(new GarnitureCreme());
        ingredients.add(new GarnitureSauceBarbecue());
        ingredients.add(new GarnitureJambon());

        return new PizzaBarbecue(this, ingredients);
    }
}