#include <math.h>
#include <stdio.h>

int main()
{
    double x, y1, y2, y3;
    x = M_PI_4;
    y1 = sin(x);
    y2 = cos(x);
    y3 = tan(x);
    printf("sin( %lf ) = %lf\n", x, y1);
    printf("cos( %lf ) = %lf\n", x, y2);
    printf("tan( %lf ) = %lf\n", x, y3);
    return 0;
}
