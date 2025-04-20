#include <stdio.h>

int is_even(int num) { return num % 2 == 0; }

int main(int argc, char *argv[]) {
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);
  if (is_even(number)) {
    printf("The number %d is even!", number);
  } else {
    printf("The number %d is odd!", number);
  }
  return 0;
}
