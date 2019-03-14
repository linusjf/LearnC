#include <stdio.h>
#include <string.h>

int main()
{
    char a = 'A';
    char b = 'B';
    const char *name_ptr = &a;

    char * const test_ptr = &a;

    *test_ptr = b;

    const char  *const const_ptr = &a;

//    const_ptr = &b;

  //  *const_ptr = b;

    char string[5] = "Hell";
    strcpy(string,"Bell");
// read-only variable not assignable
// name_ptr = &string[0];
 printf("%s",name_ptr);
// cannot assign to variable 'test_ptr' with const-qualified type 'char *const'
// test_ptr = &string[0];
//*test_ptr = string[0];
printf("%s",test_ptr);
printf("%s\n",string);
//strcpy(test_ptr,"Hell");
return 0;
}
