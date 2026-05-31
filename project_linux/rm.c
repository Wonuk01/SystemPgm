#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: rm 파일명\n");
        return 1;
    }

    if (remove(argv[1]) != 0) {
        perror("rm");
        return 1;
    }

    return 0;
}