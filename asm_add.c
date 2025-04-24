#include <stdio.h>

int add(int a, int b);

int main() {
  int result = add(5, 7);
  printf("Result: %d\n", result);
  return 0;
}

// define `add` using GCC inline assembly (SysV calling convention)
__asm__(".globl add             \n"
        "add:                   \n"
        "     mov %rdi, %rax    \n" // move a into rax
        "     add %rsi, %rax    \n" // add 'b' to rax
        "     ret               \n" // return with result in rax
);

// running the program
// gcc -no-pie -o asm_add asm_add.c
// -no-pie => disables position-independent executables,
// which makes linking easier with raw symbol names like add.
