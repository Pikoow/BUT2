#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int stop = 0;
int i = 1;

void handle_sigchld(int sig) {
    if (sig == SIGCHLD) {
        pid_t new_pid = fork();

        if (new_pid < 0) {
            perror("Erreur lors de fork");
            exit(EXIT_FAILURE);
        } else if (new_pid == 0) {
            printf("Nouveau processus enfant lancé, PID = %d\n", getpid());
            execl("/usr/bin/xeyes", "xeyes", NULL);
        }
    }
}

int main() {
    pid_t pid;

    printf("Avant fork(), je suis PID %d\n", getpid());

    pid = fork();
    if (pid < 0) { // Erreur
        perror("Erreur lors de fork");
        return EXIT_FAILURE;
    } else if (pid == 0) { // Fils
        printf("Je suis le fils, mon PID est %d et mon pere a le PID %d\n", getpid(), getppid());
        
        execl("/usr/bin/xeyes", "xeyes", NULL);
    } else { // Père
        printf("Je suis le père, mon PID est %d et je viens de créer un fils de PID %d\n", getpid(), pid);

        signal(SIGCHLD, handle_sigchld);
        
        while (stop == 0) {
            sleep(1);
            printf("Passage num %d\n", i);
            i++;
        }
    }
    
    printf("Je suis PID %d\n", getpid());
    return EXIT_SUCCESS;
}