#include <stdio.h>
char line[100]; // line of data from the input
int result;     // the result of the calculations
char operator;// operator the user specified
int value;// value specified after the operator

int main() {
    result = 0;
  // initialize the final result
  while (1) {
    printf("Result: %d\n", result);
    printf("Enter operator and number: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%c %d", &operator, &value);
    if (operator == '+')
    { // why does "=" also work
        result += value;
    } else if (operator== '-') {
      result -= value;
    } else {
      printf("Exiting loop: unknown operator: %c\n", operator);
      break;
    }
  }
  return 0;
}
