
#include <stdio.h>

#define People 100

int array[People];

int findnextk(int s, int k, int n)//this accept the k and n from the main function, but also the P.
{
    while (k) //As long a k has a value, this loop is true, and we keep running the loop. This loop skipping all the lucky ones that k passes over
    {
        if (array[s = (s + 1) % n]!= -1)// Now, the s=(s+1)%n part is called 'incrimenting the circle', aka, we are checking the array address to see if each one continue a value, or has nothing inside it at all. If they don't  have a value inside of them, skip them.
        {
            k--; //Yay, someone' been found. decrement from 2 to 1, or what ever you set you k to.
        }
    }
    return s; //retuning s are you P position in your pain function.
}

void swap(int *x, int *y) //this functions takes in array[index] and array[P] and swaps them.
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int n ,k;

    while (scanf("%d %d", &n, &k) != EOF && (n || k))
    {//Start of the while loop. This will run as long as n and k are NOT = 0.
       for (int i = 0; i<n; i++) array[i]=i; //Each position will get a number starting from 1. 0 hase 1st, 1 has 2nd, 2 has 3rd.
    
       int P = (k - 1) % n; //P = position of the person currently holding the big fuck off sword, well, at least the INITIAL person with the big fuck off sword. Now, I'll be honest, I'm only % by n because someone told me it kept the P from going outside the bounds of the array.

       for(int i=1; i<n; i++)
       { 
           array[P] = -1;
           int index = findnextk(P, k ,n);
           swap(&array[index], &array[P]);//ya, you see that guy who died, we need to remove him, and have the guy next to him take his place.
           P = findnextk(P, k, n);
       }

    	printf("%d\n",(n - array[P]) % n + 1);

    }
    return 0;
}