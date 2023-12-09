#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void failed (int (*courses)[3][1], int (*scores)[2], int cRows, int sRows)
{
    int numFailed = 0, numStudent = 0;

    for (int i = 0; i < cRows; i++)
    {
        int totalScore = 0;
        int numCourses = 0;

        for (int j = 0; j < sRows; j++)
        {
            int SID = courses[i][0][0]; 
            if (scores[j][0] == SID)
            {
                totalScore += scores[j][1];  
                numCourses++;
            }
        }

        if (numCourses > 0 && (totalScore / numCourses) < 60) numFailed++;

        int currentStudentID = courses[i][1][0];
        if (!checkAndStore(currentStudentID, storage, &isStored))  numStudent++; 
    }

    printf("%d %d\n", numStudent, numFailed);
}

int main(void)
{
    int cRows, sRows;
    int courses[SIZE][3][1];
    int scores[SIZE][2];

    while (scanf("%d %d", &cRows, &sRows) == 2)
    {
        for (int i = 0; i < cRows; i++)
        {
           for (int j = 0; j < 3; j++)
           {
              for (int k = 0; k < 1; k++)
              {
                scanf("%d", &courses[i][j][k]);
              }

           }
        }

        for (int i = 0; i < sRows; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                scanf("%d", &scores[i][j]);
            }
        }

        failed(courses, scores, cRows, sRows);  
    }

}