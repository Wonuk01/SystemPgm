#include <stdio.h>
#include <string.h>

#define MAX_LINES 100

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: sort 파일명\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        perror("sort");
        return 1;
    }

    char lines[MAX_LINES][1024];
    int count = 0;

    while (fgets(lines[count], sizeof(lines[count]), fp))
        count++;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char temp[1024];
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }

    for (int i = 0; i < count; i++)
        printf("%s", lines[i]);

    fclose(fp);

    return 0;
}