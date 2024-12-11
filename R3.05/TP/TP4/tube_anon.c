#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    pid_t pid;
    char text[] = "Test message"; 
    // Création d'un tube anonyme
    int fd[2];
    if (pipe(fd) == -1) {
        perror("Erreur lors de la création du pipe");
        return EXIT_FAILURE;
    }

    // Traiter les erreurs
    // après

    pid = fork();
    if (pid < 0) { // Erreur
        perror("Erreur lors de fork");
        return EXIT_FAILURE;
    } else if (pid == 0) { // Fils
        // Ferme le descripteur inutile
        close(fd[0]);
        if (write(fd[1], text, strlen(text)) == -1) {
            perror("Erreur lors de l'écriture dans le pipe");
            close(fd[1]);
            return EXIT_FAILURE;
        }
        close(fd[1]);
    } else { // Père
        // Ferme le descripteur inutile
        close(fd[1]);
        
        char buffer[256];
        ssize_t bytesRead;
        memset(buffer, 0, sizeof(buffer)); // Initialise le buffer

        // Lecture des données envoyées par le fils
        while ((bytesRead = read(fd[0], buffer, sizeof(buffer) - 1)) > 0) {
            printf("Reçu : %s\n", buffer);
            memset(buffer, 0, sizeof(buffer)); // Réinitialise le buffer
        }

        close(fd[0]);
    }

    return 0;
}