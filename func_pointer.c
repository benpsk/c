#include <stdio.h>

int add(int a, int b) { return a + b; }

int substract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
  int a, b;
  char op;

  printf("Enter first number: ");
  scanf("%d", &a);
  printf("Enter second number: ");
  scanf("%d", &b);

  printf("Choose operation (+ - * /): ");
  scanf(" %c", &op);

  int (*operation)(int, int) = NULL;

  switch (op) {
  case '+':
    operation = add;
    break;
  case '-':
    operation = substract;
    break;
  case '*':
    operation = multiply;
    break;
  case '/':
    operation = divide;
    break;
  default:
    printf("Invalid operator!\n");
    return 1;
  }
  int result = operation(a, b);
  printf("Result: %d\n", result);
  return 0;
}
