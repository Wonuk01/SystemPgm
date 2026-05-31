#include <stdio.h>
#include <unistd.h>

int main() {

    char name[100];

    getlogin_r(name, sizeof(name));

    printf("%s\n", name);

    return 0;
}