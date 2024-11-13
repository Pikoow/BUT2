import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PosteMeteo implements Observable {
    private List<Observer> observers;   // Liste des stations (observateurs)

    public PosteMeteo() {
        this.observers = new ArrayList<>();
    }

    @Override
    public void addObserver(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers(int temperature) {
        for (Observer observer : observers) {
            observer.update(temperature);
        }
    }

    public void saisirTemperature() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Entrez la température  de : ");
        int temperature = scanner.nextInt();
        notifyObservers(temperature);   // Notifier les stations de la nouvelle température
    }
}
