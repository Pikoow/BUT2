#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Avant");
    system("ls -1 /home/ | wc -l");
    system("sleep 5");
    printf("Après");
    return EXIT_SUCCESS;
}

/*
Les deux fonctions system s'exécutent avant les printf.
Pourquoi ?

*/