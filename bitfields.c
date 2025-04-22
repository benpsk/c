#include <stdio.h>

struct FeatureFlags {
  unsigned int feature1 : 1; // 1 bit for feature1 (on/off)
  unsigned int feature2 : 1;
  unsigned int feature3 : 1;
  unsigned int feature4 : 1;
  unsigned int feature5 : 1;
  unsigned int feature6 : 1;
  unsigned int reserved : 10; // 10 bits reserved (unused for now)
};

void printFlags(struct FeatureFlags flags) {
  printf("Feature 1: %d\n", flags.feature1);
  printf("Feature 2: %d\n", flags.feature2);
  printf("Feature 3: %d\n", flags.feature3);
  printf("Feature 4: %d\n", flags.feature4);
  printf("Feature 5: %d\n", flags.feature5);
  printf("Feature 6: %d\n", flags.feature6);
}
void toggleFeature(struct FeatureFlags *flags, int featureNum) {
  switch (featureNum) {
  case 1:
    flags->feature1 = !flags->feature1;
    break;
  case 2:
    flags->feature2 = !flags->feature2;
    break;
  case 3:
    flags->feature3 = !flags->feature3;
    break;
  case 4:
    flags->feature4 = !flags->feature4;
    break;
  case 5:
    flags->feature5 = !flags->feature5;
    break;
  case 6:
    flags->feature6 = !flags->feature6;
    break;
  default:
    printf("Invalid feature number\n");
    return;
  }
}

int main() {
  struct FeatureFlags flags = {0};
  printf("Initial Feature Flags:\n");
  printFlags(flags);

  toggleFeature(&flags, 1);
  toggleFeature(&flags, 4);
  toggleFeature(&flags, 6);

  printf("\nAfter toggling features:\n");
  printFlags(flags);
  return 0;
}
