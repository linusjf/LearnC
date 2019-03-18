#include <stdio.h>
#include <string.h>
//#pragma pack(push,1)
// define simple structure
typedef struct {
  unsigned int widthValidated;
  unsigned int heightValidated;
} STATUS1;

// define a structure with bit fields
typedef struct {
  unsigned int widthValidated : 8;
  unsigned int heightValidated : 8;
} STATUS2;
//#pragma pack(pop)
int main() {
  printf("Memory size occupied by status1: %ld\n", sizeof(STATUS1));
  printf("Memory size occupied by status2: %ld\n", sizeof(STATUS2));
  return 0;
}
