#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("README.md", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    fclose(fp);
    return 0;
}
