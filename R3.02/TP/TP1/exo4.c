#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine20[21];

typedef struct {
    chaine20 nom;
    int population;
    int superficie;
} t_capitale;

typedef struct {
    chaine20 nom;
    t_capitale *capitale;
} t_pays;

typedef t_pays* pt_pays;

void init_pays(t_pays *pays) {
    printf("Entrez le nom du pays : ");
    fgets(pays->nom, 21, stdin);

    pays->capitale = (t_capitale *)malloc(sizeof(t_capitale));
    if (pays->capitale == NULL) {
        printf("Échec de l'allocation mémoire pour la capitale\n");
        exit(1);
    }

    printf("Entrez le nom de la capitale : ");
    fgets(pays->capitale->nom, 21, stdin);

    printf("Entrez la population de la capitale : ");
    scanf("%d", &pays->capitale->population);

    getchar();

    printf("Entrez la superficie de la capitale : ");
    scanf("%d", &pays->capitale->superficie);

    getchar();
}

void affiche_pays(t_pays pays) {
    printf("\n--- Détails du pays ---\n");
    printf("Nom du pays : %s", pays.nom);
    printf("Nom de la capitale : %s", pays.capitale->nom);
    printf("Population de la capitale : %d\n", pays.capitale->population);
    printf("Superficie de la capitale : %d\n", pays.capitale->superficie);
}

int main() {
    pt_pays pays = (pt_pays)malloc(sizeof(t_pays));

    if (pays == NULL) {
        printf("Échec de l'allocation mémoire\n");
        return 1;
    }

    init_pays(pays);

    affiche_pays(*pays);

    free(pays->capitale);
    free(pays);
    
    return 0;
}
