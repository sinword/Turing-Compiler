# Compiler P3
[toc]

## Lex 

---

- 沒變

## Yacc

---

- 修正P2的錯誤
- 另外寫了一個"javaclass.hpp"用於處理輸出檔案，所有檔案輸出都在javaclass中操作
- 對warning進行部分刪減

## Makefile

---

```shell
$ make
$ ./parser ./file_name.st
$ ./javaa/javaa ./filename.jasm
$ java filename
```