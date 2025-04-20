#include <stdio.h>

int main() {

  FILE *fptr = fopen("filename.txt", "r");
  char myString[9];
  fgets(myString, 9, fptr);
  printf("%s", myString);
  fclose(fptr);
}
