# 📁 Linux File System & File Control Summary

이 문서는 `chmod()`, `fchmod()`, `utime()`, `touch.c`, 그리고 리눅스 파일 시스템 구조에 대한 핵심 개념을 한눈에 정리한 README입니다.

---

## 🔐 1. chmod()

### ✔ 개념

`chmod()`는 파일의 **접근 권한(permission)**을 변경하는 시스템 호출입니다.

### ✔ 함수 원형

```c
#include <sys/stat.h>

int chmod(const char *pathname, mode_t mode);
```

### ✔ 주요 특징

* 파일 경로를 기반으로 권한 변경
* `mode`는 읽기(r), 쓰기(w), 실행(x) 권한을 조합하여 설정

### ✔ 예시

```c
chmod("file.txt", 0644);
```

---

## 🔐 2. fchmod()

### ✔ 개념

`fchmod()`는 **파일 디스크립터(fd)**를 이용하여 권한을 변경합니다.

### ✔ 함수 원형

```c
#include <sys/stat.h>

int fchmod(int fd, mode_t mode);
```

### ✔ 주요 특징

* 이미 열린 파일에 대해 권한 변경
* 파일 경로가 아닌 fd 기반

### ✔ 예시

```c
int fd = open("file.txt", O_RDONLY);
fchmod(fd, 0600);
```

---

## ⏱️ 3. utime()

### ✔ 개념

파일의 **접근 시간(atime)**과 **수정 시간(mtime)**을 변경하는 함수입니다.

### ✔ 함수 원형

```c
#include <utime.h>

int utime(const char *filename, const struct utimbuf *times);
```

### ✔ 구조체

```c
struct utimbuf {
    time_t actime;   // access time
    time_t modtime;  // modification time
};
```

### ✔ 예시

```c
struct utimbuf new_times;
new_times.actime = time(NULL);
new_times.modtime = time(NULL);

utime("file.txt", &new_times);
```

---

## 🧪 4. touch.c 구현 개념

### ✔ touch 명령어 기능

* 파일이 없으면 생성
* 파일이 있으면 시간 갱신

### ✔ 기본 구현 흐름

```c
#include <fcntl.h>
#include <utime.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
    close(fd);

    utime(argv[1], NULL); // 현재 시간으로 갱신
    return 0;
}
```

### ✔ 핵심 포인트

* `open()` + `O_CREAT` → 파일 생성
* `utime()` → 시간 갱신

---

## 🗂️ 5. 리눅스 파일 시스템 구조

### ✔ 전체 구조 개요

리눅스 파일 시스템은 **트리(tree) 구조**를 가지며, 루트 디렉토리(`/`)를 기준으로 모든 파일이 계층적으로 구성됩니다.

```
/
├── bin
├── etc
├── home
├── var
├── tmp
└── usr
```

### ✔ 주요 디렉토리 설명

| 디렉토리    | 설명          |
| ------- | ----------- |
| `/`     | 루트 디렉토리     |
| `/bin`  | 기본 실행 파일    |
| `/etc`  | 설정 파일       |
| `/home` | 사용자 홈 디렉토리  |
| `/var`  | 로그 및 가변 데이터 |
| `/tmp`  | 임시 파일       |
| `/usr`  | 사용자 프로그램    |

---

## 🧱 6. 파일 시스템 내부 구조

### ✔ 구성 요소

리눅스 파일 시스템은 다음과 같은 구조로 이루어져 있습니다:

1. **Boot Block**

   * 부팅 관련 정보

2. **Super Block**

   * 파일 시스템 전체 정보 (크기, 상태 등)

3. **Inode Table**

   * 파일 메타데이터 저장
   * 파일 크기, 권한, 시간 정보 포함

4. **Data Blocks**

   * 실제 파일 데이터 저장

---

### ✔ inode 구조 핵심

* 파일 이름은 포함되지 않음
* 파일의 모든 메타 정보 포함
* 데이터 블록을 가리키는 포인터 포함

---

## 🔗 7. 핵심 개념 정리

* `chmod()` → 경로 기반 권한 변경
* `fchmod()` → fd 기반 권한 변경
* `utime()` → 파일 시간 변경
* `touch.c` → 파일 생성 + 시간 갱신 구현
* 파일 시스템 → 트리 구조 + inode 기반 관리

---

## 📌 추가 팁

* 파일 권한은 `ls -l`로 확인 가능
* inode 확인: `ls -i`
* 시스템 호출은 대부분 실패 시 `-1` 반환 → `errno` 확인 필요

---

## ✅ 마무리

이 문서는 리눅스 파일 권한 관리와 파일 시스템 구조를 이해하기 위한 핵심 내용을 요약한 것입니다.
실습을 통해 각 개념을 직접 확인해보는 것이 중요합니다.

---
