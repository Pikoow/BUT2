#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 100;
    int *pt = &x;

    *pt += 10;

    printf("Valeur pointée par pt : %d\n", *pt);
    printf("Valeur de x : %d\n", x);

    free(pt);

    return 0;
}