# C언어 입출력 버퍼 (I/O Buffer) 정리

## 1. 개요
C언어에서 입출력 함수(`scanf`, `printf`, `getchar`, `puts` 등)는 내부적으로 **버퍼(buffer)**를 사용합니다.  
버퍼는 데이터를 일시적으로 저장했다가 한 번에 입출력 효율을 높이는 메모리 공간입니다.

---

## 2. 표준 스트림과 버퍼

| 스트림 | 기본 버퍼링 모드 | 설명 |
|--------|-----------------|------|
| stdin  | 라인 버퍼(line-buffered) | 입력이 한 줄 끝(`\n`)까지 모일 때까지 대기 |
| stdout | 라인 버퍼(line-buffered, 터미널) | 출력 시 한 줄(`\n`)이 들어가면 자동 flush |
| stderr | 버퍼 없음(unbuffered) | 즉시 화면 출력 |

> 참고: 파일 입출력(`fopen`)은 일반적으로 **블록 버퍼(block-buffered)** 모드를 사용합니다.

---

## 3. 버퍼 관련 함수

| 함수 | 설명 |
|------|------|
| `fflush(FILE *stream)` | 지정한 스트림의 출력 버퍼를 강제로 비움 |
| `setbuf(FILE *stream, char *buf)` | 스트림 버퍼를 지정하거나 제거 가능 |
| `setvbuf(FILE *stream, char *buf, int mode, size_t size)` | 버퍼 모드(line, full, none)와 크기 설정 가능 |

### 버퍼 모드
- `_IONBF` : unbuffered, 즉시 출력  
- `_IOLBF` : line buffered, 줄 단위로 flush  
- `_IOFBF` : full buffered, 버퍼가 가득 찰 때 flush  

---

## 4. scanf와 버퍼

- `scanf`는 **입력 버퍼(stdin)** 에 있는 데이터를 읽음
- 개행 문자(`\n`)나 공백은 버퍼에 남을 수 있음
- 예시:
```c
char c;
scanf("%c", &c); // 이전 입력에서 남은 '\n'을 읽을 수도 있음