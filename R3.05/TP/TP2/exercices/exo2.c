#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig) {
    
    if (sig == SIGUSR1) {
        printf("\nReçu SIGUSR1.\n");
    }
    
}

int main() {
    printf("PID : %d\n", getpid());
    fflush(stdout);

    signal(SIGUSR1, handle_sigusr1);

    int temps_restant = 60;
    
    while (temps_restant > 0) {
        temps_restant = sleep(temps_restant);
        printf("Temps restant = %d\n", temps_restant);
    }

    printf("Fin de la pause.\n");
    return 0;
}
