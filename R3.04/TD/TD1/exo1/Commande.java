package exo1;
abstract class Commande {
    String cli;
    int montantHT;

    StrategieTaxe strategie;

    public Commande(String c, int m, StrategieTaxe s) {
        cli=c;
        montantHT=m;
        strategie=s;
    }

    double calculeTaxe() {
        return strategie.calcule(montantHT);
    };
}