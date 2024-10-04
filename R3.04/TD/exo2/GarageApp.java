package exo2;

class GarageApp {
    public static void main(String[] args) {
        Garage garage1, garage2, garage3;

        garage1 = new Garage("Test 1", 10000, new StrategieValeur1());
        garage2 = new Garage("Test 2", 20000, new StrategieValeur2());
        garage3 = new Garage("Test 3", 30000, new StrategieValeur3());

        garage1.printValeurGarage();
        garage2.printValeurGarage();
        garage3.printValeurGarage();

        garage1.setStrategieValeur(new StrategieValeur2());

        garage1.printValeurGarage();
    }
}
