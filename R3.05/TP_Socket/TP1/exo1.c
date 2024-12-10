#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 1

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int ret;

    // Création
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Erreur lors de la création du socket");
        exit(EXIT_FAILURE);
    }
    printf("Socket créé avec succès.\n");

    // Liaison à une adresse et un port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");;
    server_addr.sin_port = htons(PORT);

    ret = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("Erreur lors de la liaison (bind)");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    printf("Socket lié à l'adresse et au port %d.\n", PORT);

    // Mise en écoute
    ret = listen(server_sock, BACKLOG);
    if (ret == -1) {
        perror("Erreur lors de la mise en écoute (listen)");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    printf("Serveur en attente de connexion sur le port %d...\n", PORT);

    // Acceptation d'une connexion
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock == -1) {
        perror("Erreur lors de l'acceptation (accept)");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    printf("Connexion acceptée depuis %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Fermeture
    close(client_sock);
    close(server_sock);
    printf("Serveur fermé.\n");

    return 0;
}
    