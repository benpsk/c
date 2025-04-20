#include <stdio.h>
int global = 0;
void getCount() {
  static int count = 0;
  global++;
  count++;
  printf("Count: %d\n", count);
  printf("Global: %d\n", global);
}
int main() {
  getCount();
  getCount();
  getCount();
  getCount();
}
