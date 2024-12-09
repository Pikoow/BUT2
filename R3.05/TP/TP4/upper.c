#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main() {
    int fd = open("mon_tube", O_RDONLY);
    char c;

    if (fd == -1) {
        perror("Erreur lors de l'ouverture.");
        return EXIT_FAILURE;
    }

    while (read(fd, &c, 1) > 0) {
        if ((c >= 'a') && (c <= 'z')) {
            c = c - 'a' + 'A';
        }
        write(STDOUT_FILENO, &c, 1);
    }

    printf("\n");
    close(fd);
    return 0;
}