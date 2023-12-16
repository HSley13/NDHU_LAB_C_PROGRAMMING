#include <stdio.h>

int sumIntegersInString(char *str) 
{
    int sum = 0;
    int currentNumber = 0;
    int isNumber = 0;

    while (*str) 
    {
        if (isdigit(*str)) 
        {
            currentNumber = currentNumber * 10 + (*str - '0');
            isNumber = 1;
        } 

        else 
        {
            if (isNumber) 
            {
                sum += currentNumber;
                currentNumber = 0;
                isNumber = 0;
            }
        }

        str++;
    }

    if (isNumber) 
    {
        sum += currentNumber;
    }

    return sum;
}

int main() 
{
    init();
    char *str = s;
    int result = sumIntegersInString(str);

    printf("%d", result);

    return 0;
}
