#include <stdio.h>

int main(int argc, char *argv[]) {
  float fahr, celcius, lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celcius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %10.1f\n", fahr, celcius);
    fahr += step;
  }
  return 0;
}
