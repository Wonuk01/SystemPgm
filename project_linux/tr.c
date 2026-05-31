#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("사용법: tr 문자1 문자2\n");
        return 1;
    }

    char old = argv[1][0];
    char newc = argv[2][0];

    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch == old)
            ch = newc;

        putchar(ch);
    }

    return 0;
}