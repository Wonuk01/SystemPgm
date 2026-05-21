# Linux & 시스템 프로그래밍 정리

---

# 1. 하드링크(Hard Link)

## 하드링크란?
하드링크는 하나의 파일에 여러 개의 이름을 연결하는 방식이다.  
즉, 서로 다른 파일명처럼 보이지만 실제로는 같은 inode(아이노드)를 공유한다.

쉽게 말하면:
- 원본 파일과 복사본처럼 보이지만
- 실제 데이터는 하나만 존재한다.

---

## 특징
- 같은 inode 번호를 사용
- 원본 파일 삭제해도 다른 하드링크가 남아있으면 파일 유지
- 같은 파일 시스템 내에서만 생성 가능
- 디렉토리에는 일반적으로 생성 불가

---

## 하드링크 생성 명령어

```bash
ln 원본파일 링크파일
```

예시:

```bash
ln test.txt hard.txt
```

---

## inode 확인

```bash
ls -i
```

같은 inode 번호가 나오면 하드링크이다.

---

## 하드링크 구조

```text
hard.txt ─┐
          ├── inode ─── 실제 데이터
test.txt ─┘
```

---

# 2. 파일 시스템 구조(File System Structure)

## 파일 시스템이란?
운영체제가 파일과 디렉토리를 저장하고 관리하는 구조이다.

대표적인 Linux 파일 시스템:
- ext4
- xfs
- btrfs

Windows:
- NTFS
- FAT32

---

# Linux 디렉토리 구조

## 루트 디렉토리

```text
/
```

모든 디렉토리의 시작점이다.

---

## 주요 디렉토리 설명

| 디렉토리 | 설명 |
|---|---|
| /bin | 기본 명령어 저장 |
| /etc | 시스템 설정 파일 |
| /home | 사용자 홈 디렉토리 |
| /dev | 장치 파일 |
| /tmp | 임시 파일 |
| /usr | 프로그램 및 라이브러리 |
| /var | 로그 및 가변 데이터 |
| /boot | 부팅 파일 |
| /root | 관리자(root) 홈 디렉토리 |

---

## 파일 시스템 구조 예시

```text
/
├── bin
├── etc
├── home
│   └── user
├── dev
├── tmp
└── usr
```

---

## inode란?

inode는 파일의 메타데이터를 저장하는 구조이다.

포함 정보:
- 파일 크기
- 권한
- 소유자
- 생성 시간
- 데이터 위치

하지만 파일 이름은 inode에 저장되지 않는다.

---

# 3. GCC

## GCC란?
GCC(GNU Compiler Collection)는 C, C++ 등의 프로그램을 컴파일하는 컴파일러이다.

---

## 기본 컴파일 명령어

```bash
gcc 파일명.c
```

예시:

```bash
gcc hello.c
```

실행 파일:

```text
a.out
```

실행:

```bash
./a.out
```

---

## 실행 파일 이름 지정

```bash
gcc hello.c -o hello
```

실행:

```bash
./hello
```

---

## 여러 파일 컴파일

```bash
gcc main.c sub.c -o program
```

---

## 컴파일 과정

```text
소스코드(.c)
   ↓
전처리
   ↓
컴파일
   ↓
어셈블
   ↓
링킹
   ↓
실행파일
```

---

## 자주 사용하는 옵션

| 옵션 | 설명 |
|---|---|
| -o | 실행 파일 이름 지정 |
| -c | 목적 파일 생성 |
| -Wall | 경고 메시지 출력 |
| -g | 디버깅 정보 포함 |

예시:

```bash
gcc -Wall test.c -o test
```

---

# 4. gedit

## gedit란?
gedit은 Linux GUI 환경에서 사용하는 텍스트 편집기이다.

Windows의 메모장과 비슷하다.

---

## 실행 방법

```bash
gedit 파일명.c
```

예시:

```bash
gedit hello.c
```

---

## 특징
- GUI 기반
- 코드 작성 가능
- 문법 강조 지원
- 사용이 쉬움

---

## gedit 백그라운드 실행

```bash
gedit hello.c &
```

`&`를 붙이면 터미널을 계속 사용할 수 있다.

---

# 5. Makefile

## Makefile이란?
프로그램 컴파일을 자동화하는 파일이다.

대규모 프로젝트에서 매우 많이 사용된다.

---

## 사용하는 이유
- 반복 컴파일 자동화
- 수정된 파일만 다시 컴파일
- 빌드 과정 단순화

---

## 기본 구조

```make
실행파일이름: 의존파일
    명령어
```

※ 명령어 앞은 반드시 Tab 사용

---

## Makefile 예시

### 파일 구성

```text
main.c
sub.c
sub.h
Makefile
```

---

### Makefile 내용

```make
app: main.o sub.o
	gcc main.o sub.o -o app

main.o: main.c sub.h
	gcc -c main.c

sub.o: sub.c sub.h
	gcc -c sub.c

clean:
	rm -f *.o app
```

---

## 실행 방법

### 컴파일

```bash
make
```

---

### 삭제(clean)

```bash
make clean
```

---

## Makefile 동작 과정

```text
소스 수정
   ↓
make 실행
   ↓
변경된 파일만 재컴파일
   ↓
실행 파일 생성
```

---

# 최종 정리

| 항목 | 핵심 내용 |
|---|---|
| 하드링크 | 같은 inode를 공유하는 파일 |
| 파일 시스템 | 파일을 저장/관리하는 구조 |
| GCC | C 프로그램 컴파일러 |
| gedit | Linux GUI 텍스트 편집기 |
| Makefile | 컴파일 자동화 파일 |

---

# 자주 사용하는 명령어 모음

```bash
# 하드링크 생성
ln test.txt hard.txt

# inode 확인
ls -i

# gcc 컴파일
gcc hello.c -o hello

# 프로그램 실행
./hello

# gedit 실행
gedit hello.c &

# make 실행
make

# make clean 실행
make clean
```