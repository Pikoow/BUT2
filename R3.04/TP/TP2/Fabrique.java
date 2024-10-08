public interface Fabrique {
    Pate getPate();

    List<Garniture> getGarnitures();

    CuissonMode getModeCuisson();

    PizzaFromage creerPizzaFromage();

    PizzaBarbecue creerPizzaBarbecue();
}