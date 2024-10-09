#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine10[11];

typedef struct {
    int num;
    chaine10 nom;
    int moyenne;
} etudiant;

typedef struct elem {
    etudiant val;
    struct elem* svt;
} element ;

typedef element*  liste;

void init(liste* l);
void ajouter(liste* l, etudiant e);
void affiche_etudiant(etudiant e);
void afficher(liste l);
int max(liste l);
void separer(liste l, liste* inf10, liste * supEga10);

int main() {
    liste l, linf10, lsup10;
    init(&l);
    init(&linf10);
    init(&lsup10);
    etudiant e1 = {1, "Pierre", 10};
    etudiant e2 = {2, "Stan", 18};
    etudiant e3 = {3, "Mathéo", 9};
    etudiant e4 = {4, "Camille", 16};
    etudiant e5 = {5, "Malo", 7};
    ajouter(&l, e1);
    ajouter(&l, e2);
    ajouter(&l, e3);
    ajouter(&l, e4);
    ajouter(&l, e5);
    printf("Liste de tous les étudiants :\n\n");
    afficher(l);
    printf("\nLa moyenne maximale des étudiants est : %d\n\n", max(l));
    separer(l, &linf10, &lsup10);
    printf("Liste des étudiants avec un moyenne inférieure à 10 :\n\n");
    afficher(linf10);
    printf("\nListe des étudiants avec un moyenne supérieure ou égale à 10 :\n\n");
    afficher(lsup10);
    element* temp;
    while (l != NULL) {
        temp = l;
        l = l->svt;
        free(temp);
    }
    return EXIT_SUCCESS;
}

void init(liste* l) {
    *l = NULL;
}

void ajouter(liste* l, etudiant e) {
    element* nouvelElement = (element*)malloc(sizeof(element));
    if (nouvelElement == NULL) {
        printf("Erreur d'allocation mémoire\n");
    }
    nouvelElement -> val.num = e.num;
    strcpy(nouvelElement -> val.nom, e.nom);
    nouvelElement -> val.moyenne = e.moyenne;
    nouvelElement -> svt = *l; 
    *l = nouvelElement; 
}

void affiche_etudiant(etudiant e) {
    printf("\tNuméro de l'étudiant : %d, nom de l'étudiant : %s, moyenne de l'étudiant : %d\n", e.num, e.nom, e.moyenne);
}

void afficher(liste l) {
    while(l != NULL) {
        affiche_etudiant(l -> val);
        l = l -> svt;
    }
}

int max(liste l) {
    int max = -1;
    while(l != NULL) {
        if (l -> val.moyenne > max) {
            max = l -> val.moyenne;
        }
            l = l -> svt;
    }
    return max;
} 

void separer(liste l, liste* inf10, liste * supEga10) {
    while(l != NULL) {
        if (l -> val.moyenne <= 10) {
            ajouter(supEga10, l -> val);
        } else{
            ajouter(inf10, l -> val);
        }
        l = l -> svt;
    }
}
