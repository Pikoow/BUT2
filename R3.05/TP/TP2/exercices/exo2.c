#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    
    if (sig == SIGINT) {
        printf("\nReçu SIGUSR1.\n");
    }
    
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("PID %d", getpid());

    //int temps = sleep(60);
    
    //printf("%d sec\n", temps);

    return 0;
}

    // int temps_restant = sleep(60);

    // if (temps_restant == 0) {
    //     _exit(0);
    // } else {
    //     printf("Temps restant : %d", temps_restant);
    // }
    // printf("PID : %d", getpid());

    // signal(SIGUSR1, handle_sigint);
    // signal(SIGUSR2, handle_sigint);