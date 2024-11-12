#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int val = 10;

    printf("Avant fork(), je suis PID %d", getpid());
    printf(" et val = %d\n", val);

    pid = fork();
    if (pid < 0) { // Erreur
        perror("Erreur lors de fork");
        return EXIT_FAILURE;
    } else if (pid == 0) { // Fils
        printf("Je suis le fils, mon PID est %d et mon pere a le PID %d\n", getpid(), getppid());
        printf("Chez le fils, val = %d\n", val);
        val = 20;
    } else { // Père
        printf("Je suis le père, mon PID est %d et je viens de créer un fils de PID %d\n", getpid(), pid);
        printf("Chez le père, val = %d\n", val);
        wait(NULL);
    }
    
    printf("Je suis PID %d et val = %d\n", getpid(), val);
    return EXIT_SUCCESS;
}
