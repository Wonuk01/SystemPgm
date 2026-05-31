#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: dirname 경로\n");
        return 1;
    }

    char path[1024];
    strcpy(path, argv[1]);

    char *last = strrchr(path, '/');

    if (last) {
        *last = '\0';
        printf("%s\n", path);
    } else {
        printf(".\n");
    }

    return 0;
}