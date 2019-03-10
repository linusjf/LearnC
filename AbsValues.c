#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x1 = -4, y1;
    double x2=-11.23,y2;
    y1 = abs(x1);
    printf("The absolute value of %d is %d\n",x1, y1);
    y2 = fabs(x2);
    printf("fabs( %lf ) = %lf\n", x2, y2);
    return 0;
}
