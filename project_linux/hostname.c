#include <stdio.h>
#include <unistd.h>

int main() {

    char host[256];

    gethostname(host, sizeof(host));

    printf("%s\n", host);

    return 0;
}