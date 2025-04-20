#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;
  printf("Enter the max length of your name: ");
  scanf("%d", &size);

  // Allocate memory (+1 for null terminator)
  char *name = malloc((size + 1) * sizeof(char));
  if (name == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter your name: ");
  scanf("%s", name); // reads into allocated memory

  printf("Hello, %s!\n", name);

  // Show memory before freeing
  printf("Memory address before free: %p\n", (void *)name);
  printf("First character: %c\n", *name);

  // Free memory
  free(name);
  name = NULL; // avoid dangling pointer

  // Post-free check
  if (name == NULL)
    printf("Memory has been freed safely.\n");

  return 0;
}
