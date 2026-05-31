#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: mkdir 디렉토리명\n");
        return 1;
    }

    if (mkdir(argv[1], 0755) != 0) {
        perror("mkdir");
        return 1;
    }

    return 0;
}