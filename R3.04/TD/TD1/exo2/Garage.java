package exo2;

import java.util.ArrayList;
import java.util.List;

public class Garage {
    String nom;
    int capital;
    List<Voiture> voitures;

    StrategieValeur strategie;

    public Garage(String nom, int capital, StrategieValeur strategie) {
        this.nom = nom;
        this.capital = capital;
        this.strategie = strategie;
        this.voitures = new ArrayList<Voiture>();
    }

    public void setStrategieValeur(StrategieValeur strategie) {
        this.strategie = strategie;
    }

    public void printValeurGarage() {
        System.out.println("Valeur du garage : " + this.strategie.calculeValeur(this.capital, this.voitures) + " euros.");
    }
}
