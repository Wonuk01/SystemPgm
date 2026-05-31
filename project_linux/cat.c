#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 파일명이 없는 경우: 표준 입력을 그대로 출력
    if (argc < 2) {
        int ch;
        while ((ch = getchar()) != EOF) {
            putchar(ch);
        }
        return 0;
    }

    // 전달된 파일들을 순서대로 출력
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) {
            perror(argv[i]);
            continue;
        }

        int ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }

        fclose(fp);
    }

    return 0;
}