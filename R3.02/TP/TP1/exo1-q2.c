#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pt = (int*)malloc(sizeof(int));

    if (pt == NULL) {
        printf("Échec de l'allocation mémoire\n");
        return 1;
    }

    *pt = 100;

    printf("Valeur pointée par pt : %d\n", *pt);

    free(pt);

    return 0;
}