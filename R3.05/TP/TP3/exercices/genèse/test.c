#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid;
    int val = 10;

    printf("Avant fork(), je suis PID %d", getpid());
    printf(" et val = %d\n", val);

    pid = fork();
    if (pid == 0) { // Fils
        //sleep(1);
        printf("Je suis le fils, mon PID est %d et mon pere a le PID %d\n", getpid(), getppid());
        printf("Chez le fils, val = %d\n", val);
        val = 20;
    } else { // Pere
        printf("Je suis le pere, mon PID est %d et je viens de creer un fils de PID %d\n", getpid(), pid);
        printf("Chez le père, val = %d\n", val);
        sleep(1);
    }
    printf("Je suis PID %d et val = %d\n", getpid(), val);
    return EXIT_SUCCESS;
}