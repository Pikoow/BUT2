public interface Observable {
    void addObserver(Observer observer);      // Ajouter une station (observateur)
    void removeObserver(Observer observer);   // Retirer une station (observateur)
    void notifyObservers(int temperature);    // Notifier toutes les stations de la nouvelle température
}
