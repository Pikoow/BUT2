#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int compteur = 0;

void handle_sigint(int sig) {
    compteur++;
    if (sig == SIGINT) {
        if (compteur < 5) {
            printf("\nReçu un CTRL+C.\n");
            printf("Pour arrêter le programme il faut taper 5 fois CTRL+C.\n");
            printf("Il en manque encore %d.\n", 5 - compteur);
        } else {
            printf("\nVous avez tapé 5 CTRL+C. Fin du programme.\n");
            _exit(0);
        }
    } else if (sig == SIGTSTP) {
        printf("\nReçu un CTRL+Z.\n");
        printf("Remise à zéro du compteur des CTRL+C.\n");
        compteur = 0;
    }
    
}

int main() {
    signal(SIGINT, handle_sigint);
    signal(SIGTSTP, handle_sigint);

    while (true) {
        pause();
    }

    return 0;
}
