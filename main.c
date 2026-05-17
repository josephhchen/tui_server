#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * goal: run command: ./main add "item" -> write to file
 * steps
 * 1) grab add (done)
 * 2) build string after add (done)
 * 3) properly manipulate string (we can either use "<todo item>", but i don't
 * really wanna do that, need to figure out a way to not need that)
 *
 */

int main(int argc, char *argv[]) {

  size_t total = 0;
  for (int i = 2; i < argc; i++) {
    // we +1 because strings in C have a null terminator ('\0') for it to be
    // valid
    total = total + (strlen(argv[i]) + 1);
  }

  char *allocated_item_size = malloc(total);

  if (allocated_item_size == NULL) {
    return 1;
  }

  if (argc > 1) {
    if (strcmp(argv[1], "add") == 0) {
      for (int i = 2; i < argc; i++) {
        allocated_item_size = strncat(allocated_item_size, argv[i], total);
      }
      save(total, allocated_item_size);
    }

    if (strcmp(argv[1], "list") == 0) {
      list();
    }

    if (strcmp(argv[1], "del") == 0) {
      del();
    }
  }
  free(allocated_item_size);

  return 0;
}
