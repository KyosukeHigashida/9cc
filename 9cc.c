#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  char *p = argv[1]; //入力された文字列の先頭の文字を指すポインタ

  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");
  printf("      mov rax, %ld\n", strtol(p, &p, 10));

  while(*p) { //pが終端文字でない限り動作する
    if (*p == '+') {
      p++;
      printf("      add rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    if (*p == '-') {
      p++;
      printf("      sub rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    fprintf(stderr, "予期しない文字です：　'%c'\n", *p);
    return 1;
  }

  printf("      ret\n");
  return 0;
}