#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elem {
    int val;
    struct elem* svt;
} telement;

typedef struct {
    telement* queue;
    telement* tete;
    telement* max;
    telement* min;
} tfileD;

void initialisation(tfileD *f) {
    f->queue=NULL;
    f->tete=NULL;
    f->max=NULL;
    f->min=NULL;
}

bool estVide(tfileD f) {
    return (f.tete == NULL);
}

void afficheInfosFile(tfileD f) {
    if (!estVide(f)) {
        printf("La queue est %d.\n", f.queue->val);
        printf("La tête est %d.\n", f.tete->val);
        printf("Le max est %d.\n", f.max->val);
        printf("Le min est %d.\n", f.min->val);
    } else {
        printf("La file est vide.");
    }
}

void ajouteEnQueue(tfileD *f, int v) {
    telement* nouvelElem = (telement*)malloc(sizeof(telement));
    nouvelElem->val = v;
    nouvelElem->svt = NULL;

    if (estVide(*f)) {
        f->tete = nouvelElem;
        f->queue = nouvelElem;
        f->max = nouvelElem;
        f->min = nouvelElem;
    } else {
        f->queue->svt = nouvelElem;
        f->queue = nouvelElem;

        if (v > f->max->val) {
            f->max = nouvelElem;
        }
        if (v < f->min->val) {
            f->min = nouvelElem;
        }
    }
}

void supprime(tfileD *f) {
    if (!estVide(*f)) {
        telement* temp = f->tete;
        f->tete = f->tete->svt;

        if (f->tete == NULL) {
            f->queue = NULL;
            f->max = NULL;
            f->min = NULL;
        }

        free(temp);
    } else {
        printf("La file est déjà vide.\n");
    }
}

int main() {
    tfileD file;
    initialisation(&file);

    printf("Est-ce que la file est vide ? %s", estVide(file) ? "oui\n" : "non\n");

    ajouteEnQueue(&file, 10);
    ajouteEnQueue(&file, 5);
    ajouteEnQueue(&file, 15);

    afficheInfosFile(file);

    supprime(&file);
    afficheInfosFile(file);

    printf("Est-ce que la file est vide ? %s", estVide(file) ? "oui\n" : "non\n");
}