#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToRoman(int num) 
{
    int decimalValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int len = sizeof(decimalValues) / sizeof(decimalValues[0]);

    for (int i = 0; i < len; i++) 
    {
        while (num >= decimalValues[i]) 
        {
            printf("%s", romanSymbols[i]);
            num -= decimalValues[i];
        }
    }
}


int main(void) 
{
    int n;
    scanf("%d", &n);
    
    decimalToRoman(n);
}