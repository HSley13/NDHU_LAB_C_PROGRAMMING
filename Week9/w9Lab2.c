#include <stdio.h>

int main() 
{
    int *p;
    init(&p);

    int val1, val2;

    val1 = p[4];
    p += 3;
    val2 = p[3];

    printf("%d, %d", val1, val2);
    
    return 0;
}