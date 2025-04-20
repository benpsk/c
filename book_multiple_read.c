#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50

struct Book {
  char title[100];
  char author[100];
  float price;
};

int main() {

  FILE *fp = fopen("book.txt", "r");
  if (fp == NULL) {
    printf("Failed to open book.txt!\n");
    return 1;
  }
  struct Book books[MAX_BOOKS];
  int count = 0;

  while (!feof(fp)) {
    struct Book b;
    if (fgets(b.title, sizeof(b.title), fp) == NULL)
      break;
    b.title[strcspn(b.title, "\n")] = '\0';

    if (fgets(b.author, sizeof(b.author), fp) == NULL)
      break;
    b.author[strcspn(b.author, "\n")] = '\0';

    if (fscanf(fp, "%f\n", &b.price) != 1)
      break;

    books[count++] = b;

    if (count >= MAX_BOOKS)
      break;
  }
  fclose(fp);

  printf("\n--- Loaded %d Book (s) ---\n", count);
  for (int i = 0; i < count; i++) {
    printf("\nBook #%d\n", i + 1);
    printf("Title: %s\n", books[i].title);
    printf("Author: %s\n", books[i].author);
    printf("Price: $%.2f\n", books[i].price);
  }
  return 0;
}
