#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ORIG "ORIG.txt"
#define OLD "OLD.txt"

#define BUFSIZE 512

int main() {
    int fd_orig, fd_old, len;
    char * buffer[BUFSIZE];

    if ((fd_orig = open(ORIG, O_RDONLY)) < 0) {
        perror("Pb open ORIG");
        return EXIT_FAILURE;
    }
    if ((fd_old = open(OLD, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) < 0) {
        perror("Pb open OLD");
        return EXIT_FAILURE;
    }

    len = read(fd_orig, buffer, BUFSIZE);

    write(fd_old, buffer, len);

    close(fd_orig);
    close(fd_old);
    
    return EXIT_SUCCESS;
}