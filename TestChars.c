#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char ch, line[] = "Abc3 :";
  int i, count, res;
  count = strlen(line);
  for (i = 0; i < count; i++) {
    ch = line[i];
    res = !isblank(ch) ?: printf("%c is a blank\n", ch);
    res = !isdigit(ch) ?: printf("%c is a digit\n", ch);
    res = !isupper(ch) ?: printf("%c is uppercase\n", ch);
    res = !islower(ch) ?: printf("%c is lowercase\n", ch);
    res = !ispunct(ch) ?: printf("%c is punctuation\n", ch);
    res = !isprint(ch) ?: printf("%c is printable\n", ch);
    res = !iscntrl(ch) ?: printf("%c is control character\n", ch);
    res = !isgraph(ch) ?: printf("%c is graphic\n", ch);
    res = !isspace(ch) ?: printf("%c is white space\n", ch);
    res = !isxdigit(ch) ?: printf("%c is hex digit\n", ch);
    res = !isalnum(ch) ?: printf("%c is alphanumeric\n", ch);
    res = !isalpha(ch) ?: printf("%c is alphabetic\n", ch);
    res = !isdigit(ch) ?: printf("%c is digit\n", ch);




    // printf("%c is other type\n", ch);
  }

  return 0;
}
