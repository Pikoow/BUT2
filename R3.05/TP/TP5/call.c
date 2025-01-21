#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define CALL_PIPE "call_pipe"
#define CALL2LIFT "call2lift"
#define LIFT2CALL "lift2call"

int main() {
    char buffer[2];
    int call_fd, call2lift_fd, lift2call_fd;

    // Créer le tube nommé si nécessaire
    mkfifo(CALL_PIPE, 0666);
    mkfifo(CALL2LIFT, 0666);
    mkfifo(LIFT2CALL, 0666);

    // Ouvrir les tubes
    call_fd = open(CALL_PIPE, O_RDONLY);
    if (call_fd == -1) {
        perror("Erreur ouverture call_pipe");
        exit(EXIT_FAILURE);
    }

    call2lift_fd = open(CALL2LIFT, O_WRONLY);
    if (call2lift_fd == -1) {
        perror("Erreur ouverture call2lift");
        exit(EXIT_FAILURE);
    }

    lift2call_fd = open(LIFT2CALL, O_RDONLY);
    if (lift2call_fd == -1) {
        perror("Erreur ouverture lift2call");
        exit(EXIT_FAILURE);
    }

    printf("call : En attente des appels\n");

    while (1) {
        // Lire une demande d'utilisateur
        if (read(call_fd, buffer, 1) > 0) {
            buffer[1] = '\0';
            int etage = atoi(buffer);
            printf("call : appel au %dème étage\n", etage);

            // Envoyer la demande à l'ascenseur
            write(call2lift_fd, buffer, 1);

            // Attendre que l'ascenseur signale qu'il est libre
            if (read(lift2call_fd, buffer, 1) > 0 && buffer[0] == '#') {
                printf("call : ascenseur signale qu'il est libre\n");
            }
        }
    }

    close(call_fd);
    close(call2lift_fd);
    close(lift2call_fd);
    return 0;
}
