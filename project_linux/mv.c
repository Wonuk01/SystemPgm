#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("사용법: mv 원본 대상\n");
        return 1;
    }

    if (rename(argv[1], argv[2]) != 0) {
        perror("mv");
        return 1;
    }

    return 0;
}