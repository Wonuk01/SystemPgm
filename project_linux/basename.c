#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("사용법: basename 경로\n");
        return 1;
    }

    char *name = strrchr(argv[1], '/');

    if (name)
        printf("%s\n", name + 1);
    else
        printf("%s\n", argv[1]);

    return 0;
}