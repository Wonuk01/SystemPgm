#include <stdio.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("사용법: touch 파일명\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "a");

    if(fp == NULL) {
        perror("touch");
        return 1;
    }

    fclose(fp);
    return 0;
}