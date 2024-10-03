public class StrategieTaxeUSA implements StrategieTaxe {
    public double calcule(int m) {
        return (10+0.08*m);
    }
}