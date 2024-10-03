#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    struct stat inode;
    stat("ORIG.txt", &inode);

    printf("Inode : %lu\nUser Id : %d\nGroupe Id : %d\nTaille : %d\n", inode.st_ino, inode.st_uid, inode.st_gid, inode.st_size);
}