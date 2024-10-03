class CommandeUSA extends Commande {
    public CommandeUSA(String c, int m) {
        super(c, m, new StrategieTaxeUSA());
    }
}