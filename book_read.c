#include <stdio.h>
#include <string.h>

struct Book {
  char title[100];
  char author[100];
  float price;
};

int main() {
  struct Book b1;

  FILE *fp = fopen("book.txt", "r");
  if (fp == NULL) {
    printf("Failed to open book.txt!\n");
    return 1;
  }
  fgets(b1.title, sizeof(b1.title), fp);
  b1.title[strcspn(b1.title, "\n")] = '\0';

  fgets(b1.author, sizeof(b1.author), fp);
  b1.author[strcspn(b1.author, "\n")] = '\0';

  fscanf(fp, "%f", &b1.price);
  fclose(fp);

  printf("\n--- Loaded Book ---\n");
  printf("Title: %s\n", b1.title);
  printf("Author: %s\n", b1.author);
  printf("Price: $%.2f\n", b1.price);
  return 0;
}
