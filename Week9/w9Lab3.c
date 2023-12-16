#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countSubstringOccurrences(char *str, char *key) 
{
    int count = 0;
    int strLen = strlen(str);
    int keyLen = strlen(key);

    for (int i = 0; i <= strLen - keyLen; i++) 
    {
        if (!strncmp(str + i, key, keyLen)) 
        {
            count++;
        }
    }

    return count;
}

int main(void)
{
    init();
    char *str = s1;
    char *key = s2;

    //add your code here
    
    printf("%d", countSubstringOccurrences(str, key) );
    return 0;

}