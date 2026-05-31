#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("사용법: sleep 초\n");
        return 1;
    }

    int sec = atoi(argv[1]);

    sleep(sec);

    return 0;
}