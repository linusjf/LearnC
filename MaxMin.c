#include <stdio.h>
int main()
{
    int a1=3, a2=8, a3=6,max=0, min=0;
    max = a1;
    min = a1;
    max = max < a2 ? a2: max;
    min =  min > a2 ? a2:min;
    max = max < a3  ? a3:max;
    min = min > a3  ? a3:min;
    printf("ORIGINAL a1: %d a2: %d a3: %d\n", a1, a2, a3);
    printf("MAXIMUM: %d\n", max);
    printf("MINIMUM: %d\n", min);
    return 0;
}
