#include <stdio.h>

typedef char chaine20[21];

typedef struct {
    chaine20 nom;
    int population;
    chaine20 capitale;
} t_region;

int main() {
    t_region P1;

    printf("Entrez le nom de la région : ");
    scanf("%s", &P1.nom);

    printf("Entrez la population de la région : ");
    scanf("%d", &P1.population);

    getchar();

    printf("Entrez le nom de la capitale : ");
    scanf("%s", &P1.capitale);

    printf("\n--- Détails de la région ---\n");
    printf("Nom : %s", P1.nom);
    printf("Population : %d\n", P1.population);
    printf("Capitale : %s", P1.capitale);

    return 0;
}
