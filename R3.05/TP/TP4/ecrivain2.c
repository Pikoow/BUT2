#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

void sigpipe_handler(int sig) {
    fprintf(stderr, "Erreur : Tube fermé du côté lecteur (SIGPIPE reçu)\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message1> <message2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (signal(SIGPIPE, sigpipe_handler) == SIG_ERR) {
        perror("Erreur lors de l'installation du gestionnaire SIGPIPE");
        return EXIT_FAILURE;
    }

    int fd = open("mon_tube", O_WRONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du tube");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        if (write(fd, argv[i], strlen(argv[i])) == -1) {
            perror("Erreur lors de l'écriture dans le tube");
            fprintf(stderr, "Valeur de errno: %d\n", errno);
            close(fd);
            return EXIT_FAILURE;
        }

        if (write(fd, " ", 1) == -1) {
            perror("Erreur lors de l'écriture du séparateur");
            close(fd);
            return EXIT_FAILURE;
        }

        sleep(1);
    }

    close(fd);

    return 0;
}
