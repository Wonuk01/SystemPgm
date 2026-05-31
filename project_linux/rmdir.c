#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: rmdir 디렉토리명\n");
        return 1;
    }

    if (rmdir(argv[1]) != 0) {
        perror("rmdir");
        return 1;
    }

    return 0;
}