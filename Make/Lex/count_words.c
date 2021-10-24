/*
 * count_words.c
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

extern int fee_count, fie_count, foe_count, fum_count;
extern int yylex(void);

int main(void) {
  yylex();
  printf("%d %d %d %d\n", fee_count, fie_count, foe_count, fum_count);
  exit(0);
}
