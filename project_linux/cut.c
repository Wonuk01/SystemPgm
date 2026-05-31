#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("사용법: cut 열번호 파일명\n");
        return 1;
    }

    int field = atoi(argv[1]);

    FILE *fp = fopen(argv[2], "r");

    if (!fp) {
        perror("cut");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), fp)) {

        char *token = strtok(line, " \t\n");
        int count = 1;

        while (token) {

            if (count == field) {
                printf("%s\n", token);
                break;
            }

            token = strtok(NULL, " \t\n");
            count++;
        }
    }

    fclose(fp);

    return 0;
}