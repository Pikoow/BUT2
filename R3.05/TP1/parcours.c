#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define DIRNAME "."

int main() {
    DIR * dir;
    struct dirent * ent;

    dir = opendir(DIRNAME);

    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            printf("%s   ", ent->d_name);
        }
    }
    printf("\n");

    closedir(dir);

    return 0;
}