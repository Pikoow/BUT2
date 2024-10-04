package exo1;
public class Main {
    public static void main(String[] args) {
        // Créer des objets Commande
        Commande commande1 = new CommandeEurope("Client A", 100);
        Commande commande2 = new CommandeUSA("Client B", 200);

        // Calculer et afficher la taxe pour chaque commande
        System.out.println("Commande Europe:");
        System.out.println("Client: " + commande1.cli);
        System.out.println("Montant HT: " + commande1.montantHT);
        System.out.println("Taxe calculée: " + commande1.calculeTaxe());

        System.out.println("\nCommande USA:");
        System.out.println("Client: " + commande2.cli);
        System.out.println("Montant HT: " + commande2.montantHT);
        System.out.println("Taxe calculée: " + commande2.calculeTaxe());
    }
}
