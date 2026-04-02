#include <stdio.h>

int main() {
    char string[20];
    char c;

    scanf("%s", string);
    scanf(" %c", &c);  // 앞에 공백 추가 (버퍼 문제 방지)

    printf("%s\n", string);
    printf("!!%c!!\n", c);

    return 0;
}