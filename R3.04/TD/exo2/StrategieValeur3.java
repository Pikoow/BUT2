package exo2;

import java.util.List;

public class StrategieValeur3 implements StrategieValeur {
    @Override
    public int calculeValeur(int capital, List<Voiture> voitures) {
        if (voitures.size() > 0) {
            return capital / voitures.size();
        } else {
            return capital;
        }
    }
}
