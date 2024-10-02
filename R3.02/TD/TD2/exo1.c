#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

Element* initEnsemble() {
    return NULL;
}

int appartient(Element* ensemble, int valeur) {
    Element* current = ensemble;
    while (current != NULL) {
        if (current->valeur == valeur) {
            return 1;
        }
        current = current->suivant;
    }
    return 0;
}

void ajouter(Element** ensemble, int valeur) {
    if (!appartient(*ensemble, valeur)) {
        Element* nouvelElement = (Element*)malloc(sizeof(Element));
        nouvelElement->valeur = valeur;
        nouvelElement->suivant = *ensemble;
        *ensemble = nouvelElement;
    }
}

void afficherEnsemble(Element* ensemble) {
    Element* current = ensemble;
    printf("{ ");
    while (current != NULL) {
        printf("%d ", current->valeur);
        current = current->suivant;
    }
    printf("}\n");
}

void ajouterTableau(Element** ensemble, int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        ajouter(ensemble, tableau[i]);
    }
}

int cardinal(Element* ensemble) {
    int count = 0;
    Element* current = ensemble;
    while (current != NULL) {
        count++;
        current = current->suivant;
    }
    return count;
}

void unionEnsembles(Element* e1, Element* e2, Element** e3) {
    Element* current = e1;
    while (current != NULL) {
        ajouter(e3, current->valeur);
        current = current->suivant;
    }
    current = e2;
    while (current != NULL) {
        ajouter(e3, current->valeur);
        current = current->suivant;
    }
}

void intersectionEnsembles(Element* e1, Element* e2, Element** e3) {
    Element* current = e1;
    while (current != NULL) {
        if (appartient(e2, current->valeur)) {
            ajouter(e3, current->valeur);
        }
        current = current->suivant;
    }
}

int main() {
    Element* ensemble1 = initEnsemble();
    Element* ensemble2 = initEnsemble();
    Element* ensembleUnion = initEnsemble();
    Element* ensembleIntersection = initEnsemble();

    ajouter(&ensemble1, 1);
    ajouter(&ensemble1, 2);
    ajouter(&ensemble1, 3);

    ajouter(&ensemble2, 3);
    ajouter(&ensemble2, 4);
    ajouter(&ensemble2, 5);

    printf("Ensemble 1 : ");
    afficherEnsemble(ensemble1);
    printf("Ensemble 2 : ");
    afficherEnsemble(ensemble2);

    unionEnsembles(ensemble1, ensemble2, &ensembleUnion);
    printf("Union : ");
    afficherEnsemble(ensembleUnion);

    intersectionEnsembles(ensemble1, ensemble2, &ensembleIntersection);
    printf("Intersection : ");
    afficherEnsemble(ensembleIntersection);

    printf("Cardinalité de l'union : %d\n", cardinal(ensembleUnion));

    return 0;
}