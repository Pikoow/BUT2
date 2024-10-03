#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int pid = atoi(argv[1]);

    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    if (kill(pid, SIGCONT) == 0) {
        printf("Le processus avec le PID %d a été réveillé (SIGCONT).\n", pid);
    } else {
        perror("Erreur lors de l'envoi du signal");
        return 1;
    }

    return 0;
}
