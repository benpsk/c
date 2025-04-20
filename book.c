#include <stdio.h>
#include <string.h>

struct Book {
  char title[100];
  char author[100];
  float price;
};

int main() {
  struct Book b1;

  printf("Enter title: ");
  fgets(b1.title, sizeof(b1.title), stdin);
  b1.title[strcspn(b1.title, "\n")] = '\0';

  printf("Enter author: ");
  fgets(b1.author, sizeof(b1.author), stdin);
  b1.author[strcspn(b1.author, "\n")] = '\0';

  printf("Enter price: ");
  scanf("%f", &b1.price);

  printf("\n--- Book Info ---\n");
  printf("Title: %s\n", b1.title);
  printf("Author: %s\n", b1.author);
  printf("Price: $%.2f\n", b1.price);

  return 0;
}
