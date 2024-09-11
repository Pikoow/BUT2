#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine20[21];

typedef struct {
    chaine20 nom;
    int population;
    chaine20 capitale;
} t_region;

typedef t_region* pt_region;

int main() {
    pt_region region = (pt_region)malloc(sizeof(t_region));

    if (region == NULL) {
        printf("Échec de l'allocation mémoire\n");
        return 1;
    }

    printf("Entrez le nom de la région : ");
    fgets(region->nom, 21, stdin); 

    printf("Entrez la population de la région : ");
    scanf("%d", &region->population);

    getchar();

    printf("Entrez le nom de la capitale : ");
    fgets(region->capitale, 21, stdin);

    printf("\n--- Détails de la région ---\n");
    printf("Nom de la région : %s", region->nom);
    printf("Population : %d\n", region->population);
    printf("Capitale : %s", region->capitale);

    free(region);

    return 0;
}
