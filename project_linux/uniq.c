#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: uniq 파일명\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        perror("uniq");
        return 1;
    }

    char prev[1024] = "";
    char curr[1024];

    while (fgets(curr, sizeof(curr), fp)) {
        if (strcmp(prev, curr) != 0)
            printf("%s", curr);

        strcpy(prev, curr);
    }

    fclose(fp);

    return 0;
}