#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

int main() {
    int ret;

    ret = mkdir("doss", 0777);
    if (ret == -1) {
        if (errno == ENAMETOOLONG) {
            printf("Le nom est trop long !\n");
        } else if(errno == EEXIST) {
            printf("Le dossier existe déjà !\n");
        } else {
            perror("Erreur inconnue");
        }
        return EXIT_FAILURE;
    } else {
        printf("Le dossier à été créé !\n");
    }

    return EXIT_SUCCESS;
}