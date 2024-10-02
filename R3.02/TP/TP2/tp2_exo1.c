#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];
    int age;
} tpersonne;

typedef struct element {
    tpersonne personne;
    struct element *suivant;
} telement;

typedef telement* tliste;

void initialiser(tliste *l) {
    *l = NULL;
}

void insererEnTete(tliste *l, char nom[], int age) {
    telement *nouveau = (telement*)malloc(sizeof(telement));
    strcpy(nouveau->personne.nom, nom);
    nouveau->personne.age = age;
    nouveau->suivant = *l;
    *l = nouveau;
}   

void afficherPersonne(tpersonne p) {
    printf("Nom: %s, Age: %d\n", p.nom, p.age);
}

void afficherListe(tliste l) {
    telement *current = l;
    while (current != NULL) {
        afficherPersonne(current->personne);
        current = current->suivant;
    }
}

telement* rechercher(tliste l, char nom[]) {
    telement *current = l;
    while (current != NULL) {
        if (strcmp(current->personne.nom, nom) == 0) {
            return current;
        }
        current = current->suivant;
    }
    return NULL;
}

void supprimerTete(tliste *l) {
    if (*l != NULL) {
        telement *temp = *l;
        *l = (*l)->suivant;
        free(temp);
    }
}

int compterOccurrences(tliste l, char nom[]) {
    int count = 0;
    telement *current = l;
    while (current != NULL) {
        if (strcmp(current->personne.nom, nom) == 0) {
            count++;
        }
        current = current->suivant;
    }
    return count;
}

telement* rechercherIeme(tliste l, int i) {
    telement *current = l;
    int index = 0;
    while (current != NULL) {
        if (index == i) {
            return current;
        }
        current = current->suivant;
        index++;
    }
    return NULL;
}

void insererEnFin(tliste *l, char nom[], int age) {
    telement *nouveau = (telement*)malloc(sizeof(telement));
    strcpy(nouveau->personne.nom, nom);
    nouveau->personne.age = age;
    nouveau->suivant = NULL;

    if (*l == NULL) {
        *l = nouveau;
    } else {
        telement *current = *l;
        while (current->suivant != NULL) {
            current = current->suivant;
        }
        current->suivant = nouveau;
    }
}

void insererApres(tliste *l, int i, char nom[], int age) {
    telement *current = rechercherIeme(*l, i);
    if (current != NULL) {
        telement *nouveau = (telement*)malloc(sizeof(telement));
        strcpy(nouveau->personne.nom, nom);
        nouveau->personne.age = age;
        nouveau->suivant = current->suivant;
        current->suivant = nouveau;
    }
}

int main() {
    tliste maListe;
    initialiser(&maListe);

    // Test de l'insertion en tête
    insererEnTete(&maListe, "Alice", 25);
    insererEnTete(&maListe, "Bob", 30);
    insererEnTete(&maListe, "Charlie", 20);

    // Affichage de la liste
    printf("Liste après insertion en tête :\n");
    afficherListe(maListe);

    // Test de la recherche
    telement *resultat = rechercher(maListe, "Bob");
    if (resultat != NULL) {
        printf("\nBob trouvé :\n");
        afficherPersonne(resultat->personne);
    } else {
        printf("\nBob non trouvé\n");
    }

    // Test de la suppression en tête
    printf("\nListe après suppression de la tête :\n");
    supprimerTete(&maListe);
    afficherListe(maListe);

    // Test du comptage des occurrences
    insererEnTete(&maListe, "Alice", 28);
    printf("\nNombre de personnes nommées Alice : %d\n", compterOccurrences(maListe, "Alice"));

    // Test de la recherche du ième élément
    resultat = rechercherIeme(maListe, 1);
    if (resultat != NULL) {
        printf("\nDeuxième élément de la liste :\n");
        afficherPersonne(resultat->personne);
    } else {
        printf("\nAucun deuxième élément trouvé\n");
    }

    // Test de l'insertion en fin de liste
    insererEnFin(&maListe, "David", 35);
    printf("\nListe après insertion en fin :\n");
    afficherListe(maListe);

    // Test de l'insertion après le ième élément
    insererApres(&maListe, 1, "Eve", 22);
    printf("\nListe après insertion après le deuxième élément :\n");
    afficherListe(maListe);

    return 0;
}