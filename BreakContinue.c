#include <stdio.h>
int main() {
    int max = 5;
    for (int i = 0; i < max; i++)
    {
        if (i == 3)
            continue;
        if (i == 4)
            break;
        printf("i : %d\n", i);
    }
    return 0;
}
