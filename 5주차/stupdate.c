#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define START_ID 1001001  // 시작 학번

int main(int argc, char *argv[])
{
    struct student rec;
    int id;
    char c;
    FILE *fp;

    // 프로그램 사용법 확인
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        exit(1);
    }

    // 파일 열기 (바이너리 읽기+쓰기 모드)
    if ((fp = fopen(argv[1], "rb+")) == NULL) {
        fprintf(stderr, "파일 열기 오류\n");
        exit(2);
    }

    // 반복적으로 학생 점수 수정
    do {
        printf("수정할 학생의 학번 입력: ");
        if (scanf("%d", &id) == 1) {
            // 학번 위치로 이동
            fseek(fp, (id - START_ID) * sizeof(rec), SEEK_SET);

            // 레코드 읽기
            if ((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0)) {
                printf("학번: %8d 이름: %4s 점수: %4d\n", rec.id, rec.name, rec.score);

                // 새로운 점수 입력
                printf("새로운 점수 입력: ");
                if (scanf("%d", &rec.score) == 1) {
                    fseek(fp, -sizeof(rec), SEEK_CUR);  // 파일 포인터 되돌리기
                    fwrite(&rec, sizeof(rec), 1, fp);  // 수정된 레코드 쓰기
                } else {
                    printf("점수 입력 오류\n");
                    while (getchar() != '\n');  // 입력 버퍼 비우기
                }
            } else {
                printf("레코드 %d 없음\n", id);
            }
        } else {
            printf("입력 오류\n");
            while (getchar() != '\n');  // 입력 버퍼 비우기
        }

        printf("계속하겠습니까?(Y/N): ");
        scanf(" %c", &c);  // 앞 공백으로 이전 입력의 개행 제거
    } while (c == 'Y' || c == 'y');

    fclose(fp);
    return 0;
}