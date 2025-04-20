#include <stdio.h>
enum Level { LOW, MEDIUM, HIGH };

void which(enum Level l) {

  if (l == MEDIUM) {
    printf("the level is medium");
  }
  if (l == HIGH) {
    printf("the level is high");
  }
}

int main(int argc, char *argv[]) {

  enum Level myVar = MEDIUM;
  which(myVar);
  return 0;
}
