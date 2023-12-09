#include <stdio.h>

#define SIZE 50
int storage[SIZE] = {0};
int isStored = 0;

int checkAndStore(int number, int *storage, int *isStored) 
{
    for (int i = 0; i < *isStored; i++) 
    {
        if (storage[i] == number) return 1;
        
    }

    storage[*isStored] = number;
    (*isStored)++;

    return 0;
}


int main() {
    int array[] = {5, 10, 15, 20, 5, 25};
    int size = sizeof(array) / sizeof(array[0]);

    int storage[size];
    int isStored = 0;

    for (int i = 0; i < size; i++) 
    {
        if (!checkAndStore(array[i], storage, &isStored)) printf("GOOD\n");   
    }
    
    printf("Stored numbers for the next iteration: ");
    for (int i = 0; i < isStored; i++) {
        printf("%d ", storage[i]);
    }
    printf("\n");

    return 0;
}
