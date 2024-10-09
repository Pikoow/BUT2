#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE 8
typedef char chaine8[9];
typedef struct {
    char numColonne; // indice de la colonne : A, B ..., H
    chaine8 nom;     // nom de la piece (Roi, Fou, etc.)
    char couleur;    // couleur : N=noir, B=blanc
}piece;

typedef struct elem {
    piece val;
    struct elem * svt;
}element;

typedef element * Echiquier[TAILLE];

void initEchiquier(Echiquier E) {
    for (int i = 0; i < TAILLE; i++) {
        E[i] = NULL;
    }
}

void ajouterPiece(Echiquier E, int I, piece P) {
    element *newElement = (element *)malloc(sizeof(element));

    newElement->val = P;
    newElement->svt = E[I];
    E[I] = newElement;
}

bool caseVide(Echiquier E, int L, char C) {
    int colIndex = C - 'A';

    element *current = E[L];
    while (current != NULL) {
        if (current->val.numColonne == C) {
            return false;
        }
        current = current->svt;
    }

    return true;
}

void afficherEchiquierSchema(Echiquier E) {
    for (int i = 0; i < TAILLE; i++) {
        printf("%d -> ", i);
        element *current = E[i];
        if (current == NULL) {
            printf("[NULL]\n");
        } else {
            while (current != NULL) {
                printf("[%c %s %c]", current->val.numColonne, current->val.nom, current->val.couleur);
                current = current->svt;
            }
            printf("\n");
        }
    }
}

void afficherEchiquierComplet(Echiquier E) {
    printf("      A          B          C          D          E          F          G          H\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", i);
        for (char col = 'A'; col <= 'H'; col++) {
            element *current = E[i];
            bool found = false;
            while (current != NULL) {
                if (current->val.numColonne == col) {
                    printf("[%c %s %c] ", current->val.numColonne, current->val.nom, current->val.couleur);
                    found = true;
                    break;
                }
                current = current->svt;
            }
            if (!found) {
                printf("[        ] ");
            }
        }
        printf("\n");
    }
}

int main() {
    Echiquier E;
    initEchiquier(E);

    // Création des pièces
    piece p1 = {'F', "Roi ", 'N'};
    piece p2 = {'A', "Tour", 'B'};
    piece p3 = {'F', "Fou ", 'N'};
    piece p4 = {'F', "Pion", 'N'};
    piece p5 = {'H', "Pion", 'N'};
    piece p6 = {'F', "Pion", 'B'};
    piece p7 = {'G', "Roi ", 'B'};
    piece p8 = {'G', "Pion", 'B'};
    piece p9 = {'H', "Pion", 'B'};
    
    // Ajout des pièces
    ajouterPiece(E, 0, p1);
    ajouterPiece(E, 1, p3);
    ajouterPiece(E, 1, p2);
    ajouterPiece(E, 2, p4);
    ajouterPiece(E, 3, p5);
    ajouterPiece(E, 5, p7);
    ajouterPiece(E, 5, p6);
    ajouterPiece(E, 6, p9);
    ajouterPiece(E, 6, p8);

    // Test caseVide
    printf("La case (0, A) est vide : %s\n", caseVide(E, 0, 'A') ? "oui" : "non");
    printf("La case (1, B) est vide : %s\n", caseVide(E, 4, 'G') ? "oui" : "non");
    printf("La case (1, F) est vide : %s\n", caseVide(E, 1, 'F') ? "oui" : "non");

    // Afficher l'échiquier
    printf("Quel mode voulez vous afficher : Schéma (S), Complet (C) ? ");
    char mode;
    scanf("%c", &mode);
    if (mode == 'S') {
        afficherEchiquierSchema(E);
    } else if (mode == 'C') {
        afficherEchiquierComplet(E);
    }
    
    return 0;
}