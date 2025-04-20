#include <stdio.h>

struct Car {
  char brand[30];
  char model[30];
  int year;
};

int main(int argc, char *argv[]) {

  struct Car c1 = {"BMW", "X5", 1999};
  struct Car c2 = {"Ford", "Mustang", 1969};
  struct Car c3 = {"Toyota", "Corolla", 2011};

  printf("%s %s %d\n", c1.brand, c1.model, c1.year);
  printf("%s %s %d\n", c2.brand, c2.model, c2.year);
  printf("%s %s %d\n", c3.brand, c3.model, c3.year);
  return 0;
}
