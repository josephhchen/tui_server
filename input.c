#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save(int count, char item[]) {
  printf("saving... \n");
  printf("item %s", item);
  FILE *fptr;

  fptr = fopen("todo.txt", "a");

  if (fptr == NULL) {
    printf("file could not be created \n");
    return;
  }

  fprintf(fptr, "%s\n", item);

  fclose(fptr);

  printf("saved! \n");
}

void list(void) {
  FILE *fptr;
  fptr = fopen("todo.txt", "r");

  char character;

  if (fptr == NULL) {
    return;
  }

  while ((character = fgetc(fptr)) != EOF) {
    printf("%c", character);
  }

  fclose(fptr);

  return;
}

void del(void);
