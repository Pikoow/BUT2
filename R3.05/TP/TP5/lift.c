#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define CALL2LIFT "call2lift"
#define LIFT2CALL "lift2call"

#define TEMPS_PAR_ETAGE 2 // 2 secondes par étage

int main() {
    char buffer[2];
    int call2lift_fd, lift2call_fd;

    // Ouvrir les tubes
    call2lift_fd = open(CALL2LIFT, O_RDONLY);
    if (call2lift_fd == -1) {
        perror("Erreur ouverture call2lift");
        exit(EXIT_FAILURE);
    }

    lift2call_fd = open(LIFT2CALL, O_WRONLY);
    if (lift2call_fd == -1) {
        perror("Erreur ouverture lift2call");
        exit(EXIT_FAILURE);
    }

    printf("lift : En attente des demandes\\n");

    while (1) {
        // Lire une demande d'étage
        if (read(call2lift_fd, buffer, 1) > 0) {
            buffer[1] = '\0';
            int etage = atoi(buffer);
            printf("lift : ascenseur appelé au %dème étage\\n", etage);

            // Calculer le temps pour atteindre l'étage
            int temps_monte = etage * TEMPS_PAR_ETAGE;
            printf("lift : Temps estimé pour monter : %d secondes\\n", temps_monte);
            sleep(temps_monte);

            // Retour au RDC
            int temps_descente = etage * TEMPS_PAR_ETAGE;
            printf("lift : ascenseur retourne au RDC. Temps estimé : %d secondes\\n", temps_descente);
            sleep(temps_descente);

            // Signaler que l'ascenseur est libre
            printf("lift : ascenseur libre. Temps total : %d secondes\\n", temps_monte + temps_descente);
            write(lift2call_fd, "#", 1);
        }
    }

    close(call2lift_fd);
    close(lift2call_fd);
    return 0;
}
