#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("사용법: cp 원본 대상\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");

    if (src == NULL) {
        perror("원본 파일");
        return 1;
    }

    FILE *dest = fopen(argv[2], "wb");

    if (dest == NULL) {
        perror("대상 파일");
        fclose(src);
        return 1;
    }

    int ch;

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}