#include <stdio.h>
#include <string.h>

int distinct(char arrString[], int i, int j) 
{
    int encountered[256] = {0};

    for (int k = i; k <= j; k++) 
    {
        if (encountered[arrString[k]]) return 0;

        encountered[arrString[k]] = 1;
    }
    return 1;
}

void longest_subs(char arrString[], int *start, int *end) 
{
    int len = strlen(arrString);
    int longestLength = 0; 

    for (int i = 0; i < len; i++) 
    {
        for (int j = i; j < len; j++) 
        {
            if (distinct(arrString, i, j) && (j - i + 1 > longestLength)) 
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
    longest_subs(arrString, &start, &end);

    for (int i = start; i <= end; i++) 
    {
        printf("%c", arrString[i]);
    }
    printf("\n");
    
    return 0;
}
