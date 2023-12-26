#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sequence(int n, char* num)
{
    if(n == 1) 
    {
        printf("1\n"); 
        num[0] = '1'; 
        num[1] = '\0'; 

        return strlen(num); 
    }  
     
    int size = sequence(n-1, num); 
    int count = 0, j = 0;  

    char chr = num[0]; 
    char new_num[size * 2];

    for(int i = 0; i < size; i++)
    {
        if(chr == num[i]) count++; 

        else if(chr != num[i]) 
        {
            new_num[j] = count + '0'; 
            new_num[j+1] = chr;

            j+=2;  
            count = 1; 
            chr = num[i]; 
        }
    }

    new_num[j] = count + '0'; 
    new_num[j+1] = chr; 

    j += 2; 
    new_num[j] = '\0'; 

    strcpy(num, new_num); 
    printf("%s\n", new_num); 

    return strlen(new_num); 
}

int main(void) 
{
    int n = 0; 
    scanf("%d", &n); 

    char num[100000];
    sequence(n, num); 
}