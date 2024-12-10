#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd = open("mon_tube", O_WRONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du tube");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        if (write(fd, argv[i], strlen(argv[i])) == -1) {
            perror("Erreur lors de l'écriture dans le tube");
            close(fd);
            return EXIT_FAILURE;
        }
    }

    close(fd);
    return 0;
}
