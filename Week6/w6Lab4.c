#include <stdio.h>
#include <string.h>

int different(char arrString[], int i, int j) 
{
    int encountered[256] = {0};

    for (int k = i; k <= j; k++) 
    {
        if (encountered[arrString[k]]) return 0;

        encountered[arrString[k]] = 1;
    }
    return 1;
}

void longestSubs(char arrString[], int *start, int *end) 
{
    int n = strlen(arrString);
    int longestLength = 0; 

    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            if (different(arrString, i, j) && (j - i + 1 > longestLength)) 
            {
                longestLength = j - i + 1;
                *start = i;
                *end = j;
            }
        }
    }
}

int main() 
{
    char arrString[100];
    scanf("%s", arrString);

    int start = 0, end = 0;
    longestSubs(arrString, &start, &end);

    for (int i = start; i <= end; i++) 
    {
        printf("%c", arrString[i]);
    }
    printf("\n");
    
    return 0;
}
