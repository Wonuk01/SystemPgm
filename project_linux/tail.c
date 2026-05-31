#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: tail 파일명\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        perror("tail");
        return 1;
    }

    char lines[MAX_LINES][1024];
    int count = 0;

    while (fgets(lines[count], sizeof(lines[count]), fp) != NULL) {
        count++;
        if (count >= MAX_LINES)
            break;
    }

    int start = count > 10 ? count - 10 : 0;

    for (int i = start; i < count; i++) {
        printf("%s", lines[i]);
    }

    fclose(fp);
    return 0;
}