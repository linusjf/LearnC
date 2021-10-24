/*
 * count_words.c
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "counter.h"

int main(void) {
  int counts[4];
  counter(counts);
  printf("%d %d %d %d\n", counts[0], counts[1], counts[2], counts[3]);
  exit(0);
}
