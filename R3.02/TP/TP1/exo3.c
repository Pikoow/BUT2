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
    t_capitale capitale;
} t_pays;

typedef t_pays* pt_pays;

void init_pays(t_pays * t) {
    printf("Entrez le nom du pays : ");
    fgets(t->nom, 21, stdin);

    printf("Entrez le nom de la capitale : ");
    fgets(t->capitale.nom, 21, stdin);

    printf("Entrez la population du pays : ");
    scanf("%d", &t->capitale.population);

    getchar();

    printf("Entrez la superficie du pays : ");
    scanf("%d", &t->capitale.superficie);

    getchar();
}

void affiche_pays(t_pays t) {
    printf("\n--- Détails du pays ---\n");
    printf("Nom du pays : %s", t.nom);
    printf("Nom de la capitale : %s", t.capitale.nom);
    printf("Population de la capitale : %d\n", t.capitale.population);
    printf("Superficie de la capitale : %d\n", t.capitale.superficie);
}

int main() {
    pt_pays pays = (pt_pays)malloc(sizeof(t_pays));

    if (pays == NULL) {
        printf("Échec de l'allocation mémoire\n");
        return 1;
    }

    init_pays(pays);

    affiche_pays(*pays);

    free(pays);

    return 0;
}