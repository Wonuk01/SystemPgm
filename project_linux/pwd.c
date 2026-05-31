#include <stdio.h>

int main() {
    char path[1024];

    if (getcwd(path, sizeof(path)) != NULL)
        printf("%s\n", path);

    return 0;
}