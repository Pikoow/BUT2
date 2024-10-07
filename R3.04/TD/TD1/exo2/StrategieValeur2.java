package exo2;

import java.util.List;

public class StrategieValeur2 implements StrategieValeur {
    @Override
    public int calculeValeur(int capital, List<Voiture> voitures) {
        return capital;
    }
}
