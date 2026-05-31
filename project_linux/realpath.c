#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: realpath 파일명\n");
        return 1;
    }

    char resolved[1024];

    if (realpath(argv[1], resolved) == NULL) {
        perror("realpath");
        return 1;
    }

    printf("%s\n", resolved);

    return 0;
}