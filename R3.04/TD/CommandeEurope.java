class CommandeEurope extends Commande {
    public CommandeEurope(String c, int m) {
        super(c, m, new StrategieTaxeEurope());
    }
}