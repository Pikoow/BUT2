#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[50];
    int age;
} tpersonne;

typedef struct elem {
    tpersonne pers;
    struct elem* svt;
} telement;

typedef struct {
    telement* queue;
    telement* tete;
} tfile;

typedef struct {
    tfile urgent;
    tfile important;
    tfile standard;
} tfilePrio;

void initFile(tfile* file) {
    file->tete = NULL;
    file->queue = NULL;
}

int estVide(tfile* file) {
    return (file->tete == NULL);
}

tpersonne teteFile(tfile* file) {
    return file->tete->pers;
}

void ajouterFile(tfile* file, tpersonne p) {
    telement* nouveau = (telement*)malloc(sizeof(telement));

    nouveau->pers = p;
    nouveau->svt = NULL;
    
    if (estVide(file)) {
        file->tete = nouveau;
    } else {
        file->queue->svt = nouveau;
    }
    file->queue = nouveau;
}

void supprimerFile(tfile* file) {
    if (!estVide(file)) {
        telement* temp = file->tete;
        file->tete = file->tete->svt;
        
        if (file->tete == NULL) { // Si la file devient vide
            file->queue = NULL;
        }
        
        free(temp);
    } else {
        printf("La file est déjà vide\n");
    }
}

void afficherFile(tfile* file) {
    telement* courant = file->tete;
    if (estVide(file)) {
        printf("La file est vide\n");
    } else {
        while (courant != NULL) {
            printf("Nom: %s, Age: %d\n", courant->pers.nom, courant->pers.age);
            courant = courant->svt;
        }
    }
}

void creationPrio(tfilePrio *fp) {
    initFile(&(fp->urgent));
    initFile(&(fp->important));
    initFile(&(fp->standard));
}

void ajoutePrio(tfilePrio *fp, tpersonne p, int priorite) {
    if (priorite == 1) {
        ajouterFile(&(fp->urgent), p);
    } else if (priorite == 2) {
        ajouterFile(&(fp->important), p);
    } else if (priorite == 3) {
        ajouterFile(&(fp->standard), p);
    } else {
        printf("Priorité non reconnue !");
    }
}

void affichePrio(tfilePrio *fp) {
    if (!estVide(&fp->urgent)) {
        printf("Tête urgent :\n%s, %d\n", teteFile(&fp->urgent).nom, teteFile(&fp->urgent).age);
        supprimerFile(&fp->urgent);
    } if (!estVide(&fp->important)) {
        printf("Tête important :\n%s, %d\n", teteFile(&fp->important).nom, teteFile(&fp->important).age);
        supprimerFile(&fp->important);
    } if (!estVide(&fp->standard)) {
        printf("Tête standard :\n%s, %d\n", teteFile(&fp->standard).nom, teteFile(&fp->standard).age);
        supprimerFile(&fp->standard);
    } else if (estVide(&fp->urgent) && estVide(&fp->important) && estVide(&fp->standard)) {
        printf("Les trois files sont vides !\n");
    }
}

int main() {
    tfile file;
    initFile(&file);
    tfilePrio filePrio;
    
    tpersonne p1 = {"Alice", 30};
    tpersonne p2 = {"Bob", 25};
    tpersonne p3 = {"Charlie", 20};

    printf("Ajout des personnes...\n");    
    ajouterFile(&file, p1);
    ajouterFile(&file, p2);
    ajouterFile(&file, p3);

    printf("Affichage 1 :\n");
    afficherFile(&file);

    printf("Suppression d'une personne...\n");
    supprimerFile(&file);

    printf("Affichage 2 :\n");
    afficherFile(&file);

    printf("Est-ce que la file est vide : %s\n", estVide(&file) ? "oui" : "non");
    printf("La tête est : Nom: %s, Age: %d\n", teteFile(&file).nom, teteFile(&file).age);

    creationPrio(&filePrio);
    ajoutePrio(&filePrio, p1, 1);
    ajoutePrio(&filePrio, p2, 1);
    ajoutePrio(&filePrio, p3, 2);
    affichePrio(&filePrio);
}