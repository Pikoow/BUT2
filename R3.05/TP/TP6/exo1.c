#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

bool fini = false;

void handle_signal(int sig);
void do_job_pere();
void do_job_fils();

int main() {
    pid_t pid;
    signal(SIGUSR1, handle_signal); 
    signal(SIGUSR2, handle_signal); 
    pid = fork();

    if (pid == -1) {
        perror("Erreur lors du fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Fils (%d): Démarrage du travail...\n", getppid());
        kill(getppid(), SIGUSR1);
        do_job_fils();
        printf("Fils (%d): Travail terminé.\n", getppid());
        exit(EXIT_SUCCESS);

    } else {
        printf("Père (%d): En attente de notification du fils...\n", getppid());
        pause(); 
        printf("Père (%d): Notification reçue, démarrage du travail...\n", getppid());
        do_job_pere();
        kill(pid, SIGUSR2);
        printf("Père (%d): Travail terminé.\n", getppid());
    }

    return EXIT_SUCCESS;
}

void handle_signal(int sig) {
    fini = true;
}

void do_job_pere() {
    double pi = 0.0, res = 0.0;
    long loop = 1;

    fini = false;
    while (!fini) {
        pi = pi + 1.0 / (double)pow(loop, 2);
        loop++;
    }

    res = sqrt(pi * 6);
    printf("Père : PI = %.18f (précision : %e) en %ld itérations\n", res, (res - M_PI), loop);
}

void do_job_fils() {
    double pi = 0.0, res = 0.0;
    long loop = 1;

    fini = false;
    while (!fini) {
        pi = pi + 1.0 / (double)pow(loop, 4);
        loop++;
    }

    res = pow(pi * 90, 0.25);
    printf("Fils : PI = %.18f (précision : %e) en %ld itérations\n", res, (res - M_PI), loop);
}