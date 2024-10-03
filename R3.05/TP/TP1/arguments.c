#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    // Afficher le nombre d'arguments passés au programme
    printf("Nombre d'arguments (argc) : %d\n", argc);

    // Afficher la liste des arguments (argv)
    printf("Liste des arguments (argv[]) :\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // Afficher la liste des variables d'environnement (envp)
    printf("\nListe des variables d'environnement (envp[]) :\n");
    for (int i = 0; envp[i] != NULL; i++) {
        printf("envp[%d] = %s\n", i, envp[i]);
    }

    return 0;
}
