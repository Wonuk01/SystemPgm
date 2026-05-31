#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: tee 파일명\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "w");

    if (!fp) {
        perror("tee");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), stdin)) {
        printf("%s", line);
        fputs(line, fp);
    }

    fclose(fp);

    return 0;
}