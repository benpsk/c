#include "math_ops.h" // include function declarations
#include <stdio.h>

int main() {
  int x = 20, y = 5;

  printf("x = %d, y = %d\n", x, y);
  printf("Add: %d\n", add(x, y));
  printf("Subtract: %d\n", subtract(x, y));
  printf("Multiply: %d\n", multiply(x, y));
  printf("Divided: %d\n", divide(x, y));
  return 0;
}
