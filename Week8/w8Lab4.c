#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 50

void failed (int (*courses)[3][0], int (*scores)[2], int cRows, int sRows)
{
    int numFailed = 0, numStudent = 0, previousStudentID = - 1;

    for (int i = 0; i < cRows; i++)
    {
        int totalScore = 0;
        int numCourses = 0;

        for (int j = 0; j < sRows; j++)
        {
            int sid = courses[i][0][0]; 
            if (scores[j][0] == sid)
            {
                totalScore += scores[j][1];  
                numCourses++;
            }
        }

        int currentStudentId = courses[i][2][0];
        if (numCourses > 0 && totalScore / numCourses < 60) numFailed++;

        if (i == 0 || currentStudentId != previousStudentID) 
        {
            numStudent++;
            previousStudentID = currentStudentId;
        }
    }

    printf("%d %d\n", numStudent, numFailed);
}

int main(void)
{

    int cRows, sRows;

    int courses[size][3][1];
    int scores[size][2];

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