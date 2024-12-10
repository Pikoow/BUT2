#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main() {
    int fd = open("mon_tube", O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du tube");
        return EXIT_FAILURE;
    }

    close(fd);

    return 0;
}
