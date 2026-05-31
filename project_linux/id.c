#include <stdio.h>
#include <unistd.h>

int main() {

    printf("UID: %d\n", getuid());
    printf("GID: %d\n", getgid());

    return 0;
}