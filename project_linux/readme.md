# Linux Commands Implementation in C

## 프로젝트 소개

본 프로젝트는 리눅스에서 자주 사용되는 30개의 명령어를 C 언어로 직접 구현한 프로젝트이다.

각 명령어는 독립적인 `.c` 파일로 작성되었으며, 파일 입출력(File I/O), 디렉토리 처리, 문자열 처리, 시스템 호출(System Call) 등의 기능을 활용하여 구현하였다.

---

## 개발 환경

* Language : C
* Compiler : GCC
* OS : Linux (Ubuntu)
* Standard Library : stdio.h, stdlib.h, string.h 등
* System Programming Library : unistd.h, dirent.h, sys/stat.h 등

---

## 구현 명령어 목록

### 1. 파일 및 디렉토리 관련 명령어

| 명령어      | 설명            |
| -------- | ------------- |
| cat      | 파일 내용을 출력     |
| pwd      | 현재 작업 디렉토리 출력 |
| touch    | 빈 파일 생성       |
| ls       | 디렉토리 목록 출력    |
| mkdir    | 디렉토리 생성       |
| rmdir    | 빈 디렉토리 삭제     |
| rm       | 파일 삭제         |
| cp       | 파일 복사         |
| mv       | 파일 이동 및 이름 변경 |
| basename | 경로에서 파일명 추출   |
| dirname  | 경로에서 디렉토리명 추출 |
| realpath | 절대 경로 출력      |

---

### 2. 텍스트 처리 명령어

| 명령어  | 설명                 |
| ---- | ------------------ |
| echo | 문자열 출력             |
| wc   | 문자 수, 단어 수, 줄 수 출력 |
| head | 파일의 처음 10줄 출력      |
| tail | 파일의 마지막 10줄 출력     |
| grep | 특정 문자열 검색          |
| sort | 파일 내용 정렬           |
| uniq | 중복된 행 제거           |
| tee  | 화면 출력과 파일 저장 동시 수행 |
| tr   | 문자 치환              |
| cut  | 특정 필드 추출           |

---

### 3. 시스템 정보 명령어

| 명령어      | 설명             |
| -------- | -------------- |
| date     | 현재 날짜 및 시간 출력  |
| whoami   | 현재 사용자 출력      |
| hostname | 호스트 이름 출력      |
| uname    | 시스템 정보 출력      |
| id       | 사용자 UID/GID 출력 |
| uptime   | 시스템 가동 시간 출력   |

---

### 4. 기타 명령어

| 명령어   | 설명           |
| ----- | ------------ |
| clear | 터미널 화면 지우기   |
| sleep | 지정된 시간 동안 대기 |

---

## 구현 파일 목록

```text
cat.c
pwd.c
echo.c
touch.c
clear.c
date.c
whoami.c
hostname.c
uname.c
sleep.c

ls.c
mkdir.c
rmdir.c
rm.c
cp.c
mv.c
wc.c
head.c
tail.c
grep.c

sort.c
uniq.c
tee.c
tr.c
cut.c

basename.c
dirname.c
realpath.c
id.c
uptime.c
```

## 컴파일 방법

개별 컴파일

```bash
gcc cat.c -o cat
gcc pwd.c -o pwd
gcc ls.c -o ls
```

전체 컴파일

```bash
for f in *.c
do
    gcc "$f" -o "${f%.c}"
done
```

---

## 실행 예시

```bash
./cat sample.txt
./pwd
./ls
./mkdir testdir
./cp file1.txt file2.txt
./grep hello sample.txt
```

---

## 프로젝트를 통해 학습한 내용

* C 언어 파일 입출력
* 디렉토리 탐색
* 문자열 처리
* 시스템 호출 활용
* 명령행 인자 처리
* Linux 환경에서의 프로그램 개발
* GCC 컴파일러 사용법

---

## 결론

본 프로젝트를 통해 리눅스 명령어의 동작 원리를 이해하고, C 언어를 이용한 시스템 프로그래밍 기초를 학습하였다. 또한 파일 관리, 디렉토리 관리, 텍스트 처리, 시스템 정보 조회 등의 기능을 직접 구현함으로써 운영체제와 시스템 프로그래밍에 대한 이해를 높일 수 있었다.
