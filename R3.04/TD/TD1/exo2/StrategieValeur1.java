package exo2;

import java.util.List;

public class StrategieValeur1 implements StrategieValeur {

    @Override
    public int calculeValeur(int capital, List<Voiture> voitures) {
        int valeur = 0;

        for (Voiture voiture : voitures) {
            valeur += voiture.prix;
        }

        return valeur;
    }
}
