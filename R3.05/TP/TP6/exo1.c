#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool fini;
void do_job_pere() {
    double pi, res;
    long loop;

    pi = 0;
    fini = false;
    loop = 1;
    while (!fini) {
        pi = pi + 1.0/(double)pow(loop, 2);
        loop++;
    }
    res = sqrt(pi * 6);
    printf("PI = %.18f (précision : %e) en %ld itérations\n",
        res, (res - 3.141592653589793238462643383279502884197),
        loop);
}

void do_job_fils() {
    double pi, res;
    long loop;

    pi = 0;
    loop = 1;
    while (!fini) {
        pi = pi + 1.0 / (double)pow(loop, 4);
        loop++;
    }
    res = pow(pi * 90, 0.25);
    printf("PI = %.18f (précision : %e) en %ld itérations\n",
        res, (res - 3.141592653589793238462643383279502884197),
        loop);
}

int main() {
    do_job_pere();
    do_job_fils();
}