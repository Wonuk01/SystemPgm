#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: wc 파일명\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("wc");
        return 1;
    }

    int ch, lines = 0, words = 0, chars = 0;
    int inWord = 0;

    while ((ch = fgetc(fp)) != EOF) {
        chars++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
            inWord = 0;
        else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    printf("Lines: %d\nWords: %d\nChars: %d\n", lines, words, chars);

    fclose(fp);
    return 0;
}