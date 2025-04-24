#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Block {
  size_t size;
  struct Block *next;
};

struct Block *freeList = NULL;

// function to extend the heap by the `size` bytes
void *my_sbrk(size_t size) {
  void *ptr = sbrk(size);
  if (ptr == (void *)-1) {
    return NULL;
  }
  return ptr;
}

// custom malloc function
void *my_malloc(size_t size) {
  struct Block *curr, *prev = NULL;
  size = (size + 7) & ~7;

  for (curr = freeList; curr != NULL; curr = curr->next) {
    if (curr->size >= size) {
      if (prev == NULL) {
        freeList = curr->next;
      } else {
        prev->next = curr->next;
      }
      return (void *)(curr + 1);
    }
    prev = curr;
  }
  curr = (struct Block *)my_sbrk(size + sizeof(struct Block));
  if (curr == NULL) {
    return NULL;
  }
  curr->size = size;
  return (void *)(curr + 1);
}

// custom free function
void my_free(void *ptr) {
  if (ptr == NULL)
    return;

  struct Block *block = (struct Block *)ptr - 1;

  block->next = freeList;
  freeList = block;
}

int main() {
  int *arr1 = (int *)my_malloc(10 * sizeof(int));
  if (arr1 != NULL) {
    arr1[0] = 42;
    printf("arr1[0]: %d\n", arr1[0]);
  }

  my_free(arr1);

  int *arr2 = (int *)my_malloc(20 * sizeof(int));
  if (arr2 != NULL) {
    arr2[0] = 99;
    printf("arr2[0]: %d\n", arr2[0]);
  }

  my_free(arr2);
  return 0;
}
