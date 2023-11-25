#include <stdio.h>
#include <stdlib.h>

int maxCycleCount(int n, int m)
{   
    int len = m - n + 1;
    int values[len];

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

        values[i - n] = cycleLength;
    }

    int maxCycle = values[0];
    for (int i = 1; i <= m - n; i++)
    {
        if (values[i] > maxCycle) maxCycle = values[i];
    }

    return maxCycle;
}

int main(void)
{
    int n, m;

    while(1)
    {
        scanf("%d %d", &n, &m);

        if(n == EOF && m == EOF) break;

        printf("%d %d %d\n", n, m, maxCycleCount(n, m));
    }

    return 0;
}
