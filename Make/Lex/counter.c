/*
 * counter.c
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */

#include "counter.h"
#include "lexer.h"

void counter(int counts[4]) {
  while (yylex())
    ;

  counts[0] = fee_count;
  counts[1] = fie_count;
  counts[2] = foe_count;
  counts[3] = fum_count;
}
