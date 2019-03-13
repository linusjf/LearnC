#include <stdio.h>

float perimeter(width, height) int width;
float height;
{ return 2 * (width + height); }
int main() {
  float perim = perimeter(10.0, 5);
  printf("Perimeter = %f\n", perim);
  return (0);
}
