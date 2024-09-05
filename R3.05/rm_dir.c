#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int ret;

    ret = rmdir("doss");
    if (ret == -1) {
        if (errno == ENOENT) {
            printf("Le dossier n'existe pas !\n");
        } else if(errno == ENOTEMPTY) {
            printf("Le dossier n'est pas vide !\n");
        } else if(errno == ENOTDIR) {
            printf("Le dossier n'est pas un fichier !\n");
        } else {
            perror("Erreur inconnue");
        }
        return EXIT_FAILURE;
    } else {
        printf("Le dossier à été supprimé !\n");
    }

    return EXIT_SUCCESS;
}