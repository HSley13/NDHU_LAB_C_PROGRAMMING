#include <stdio.h>
#include <stdlib.h>

int maxCycleCount(int n, int m)
{   
    if (n > m)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    
    int maxCycle = 0;

    for (int i = n; i <= m; i++)
    {
        int current = i;
        int cycleLength = 1;

        while (current != 1)
        {
            if (current % 2) current = 3 * current + 1;
            else current /= 2;

            cycleLength++;
        }

        if (cycleLength > maxCycle) maxCycle = cycleLength;
    }

    return maxCycle;
}

int main(void)
{
    int n, m;

    while(scanf("%d %d", &n, &m) == 2)
    {
        printf("%d %d %d\n", n, m, maxCycleCount(n, m));
    }

    return 0;
}

