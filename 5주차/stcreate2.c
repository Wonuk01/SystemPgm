#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define START_ID 1001001

/* 
 * 구조체를 이용하여 학생 정보를 파일에 저장하는 프로그램
 * 사용법: ./program 파일이름
 */
int main(int argc, char* argv[])
{
    struct student rec;
    FILE *fp;

    // 프로그램 인자 체크
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        exit(1);
    }

    // 파일 열기 (바이너리 쓰기 모드)
    fp = fopen(argv[1], "wb");
    if (fp == NULL) {
        perror("파일 열기 실패");
        exit(1);
    }

    // 입력 안내
    printf("%7s %6s %4s\n", "학번", "이름", "점수");

    // 사용자로부터 학번, 이름, 점수를 입력받아 파일에 저장
    while (scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3) {
        fseek(fp, (rec.id - START_ID) * sizeof(rec), SEEK_SET);
        fwrite(&rec, sizeof(rec), 1, fp);
    }

    fclose(fp);
    return 0;
}