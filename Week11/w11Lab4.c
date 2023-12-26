#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int fx(char *expression);
int gxy(char* expression);

int main(void)
{
    char expression[1000]= {}; 
    int ans = 0; 
    fgets(expression, 1000, stdin); 

    for (int i = 0; i< strlen(expression); i++)
    {
        if(expression[i] == '\n') expression[i] ='\0'; 
        if(expression[i] == 'f') expression[i] = 'F'; 
        if(expression[i] == 'g') expression[i] = 'G'; 
    }

    if (expression[0] == 'F')
    {
        expression[0] = '-'; 
        expression[1] = '-'; 
        expression[strlen(expression)] = '\0'; 
        ans = fx(expression); 
    } 

    else if (expression[0] == 'G')
    {
        expression[0] = '-'; 
        expression[1] = '-'; 
        expression[strlen(expression)] = '\0';
        ans = gxy(expression); 
    }

    printf("%d", ans); 
    return 0; 
}

int fx(char *expression)
{
    int ans = 0;  

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == 'F')
        {
            expression[i] = '-'; 
            expression[i+1] = '-'; 
            expression[strlen(expression)] = '\0'; 
            ans = fx(expression); 
        } 

        else if (expression[i] == 'G')
        {
            expression[i] = '-'; 
            expression[i+1] = '-'; 
            expression[strlen(expression)] = '\0';
            ans = gxy(expression); 
        } 

        else
        {
            if (isdigit(expression[i]))
            {
                ans = (ans * 10) + (expression[i] - '0'); 
                expression[i] = '-'; 
            } 

            else if (expression[i] == ')')
            {
                expression[i] = '-'; 
                break; 
            }
        }
    } 

    return (ans * 3) + 1; 
}

int gxy(char* expression)
{
    int x = 0, y = 0, flag = 0; 

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == ',')
        {
            expression[i] = '-'; 
            flag = 1; 
        }

        if (expression[i] == 'F')
        {
            expression[i] = '-'; 
            expression[i+1] = '-'; 
            expression[strlen(expression)] = '\0'; 
            if(flag == 0) x = fx(expression); 
            else y = fx(expression); 
        } 

        else if (expression[i] == 'G')
        {
            expression[i] = '-'; 
            expression[i+1] = '-'; 
            expression[strlen(expression)] = '\0';
            if(flag == 0) x = gxy(expression); 
            else y = gxy(expression); 
        } 

        else
        {
            if (isdigit(expression[i]))
            {
                if(flag == 0)
                {
                    x = (x * 10) + (expression[i] - '0'); 
                    expression[i] = '-'; 
                } 

                else 
                {
                    y = (y * 10) + (expression[i] - '0'); 
                    expression[i] = '-'; 
                }
                
            } 

            else if (expression[i] == ')')
            {
                expression[i] = '-'; 
                break; 
            }
        }
    }

    return (x * y) - 3; 
}
