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

    strcpy(region->nom, "Bretagne");
    region->population = 600000;
    strcpy(region->capitale, "Rennes");

    printf("Nom de la région : %s\n", region->nom);
    printf("Population : %d\n", region->population);
    printf("Capitale : %s\n", region->capitale);

    free(region);

    return 0;
}
