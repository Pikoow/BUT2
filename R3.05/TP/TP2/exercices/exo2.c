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

    Exercice 2
Il existe 2 signaux sans signification précise, qui peuvent servir pour un usage privé et
personnalisé dans nos programmes. Il s’agit de SIGUSR1 et SIGUSR2. On peut en faire les
usages qu’on souhaite.
Ecrivez un programme qui doit :
● Faire une pause (sleep) de 60 secondes.
● Quitter après 60 secondes.
● Afficher un message "Reçu SIGUSR1", à réception d’un signal SIGUSR1
● Poursuivre sa pause sur le temps restant en cas d’interruption du sleep() sur
réception d’un signal.
Relisez le paragraphe sur Cas particulier du sleep() pour comprendre la nature de la
valeur retournée par sleep().
Affichez des messages aux endroits utiles pour suivre le déroulement du programme.
Testez votre programme en lui envoyant des signaux SIGUSR1 depuis un autre Terminal.