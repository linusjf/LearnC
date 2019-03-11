#include <stdio.h>
int main()
{
    int z = 10;
    if(z % 2 == 0)
    {
        printf("z is even: %d\n", z);
    }
    else
    {
        printf("z is odd: %d\n", z);
    }
    (z % 2 == 0) ? printf("z is even: %d\n", z):printf("z is odd: %d\n", z);

    return 0;
} 
