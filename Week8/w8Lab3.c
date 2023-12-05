#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 100
int matrix[size][size] = {{0}};
int visited[size][size] = {{0}};

int isValid(int x, int y, int row, int column)
{
    if (x >= 0 && x < row && y >= 0 && y < column && !visited[x][y]) return 1;

    else return 0;
}

void clockWiseSpiralOrder(int row, int column)
{
    int x = 0, y = 0;
    int direction = 6; 
    // 6 for right; 8 for down; 3 for left and 2 for up

    for (int i = 0; i < row * column; i++)
    {
        printf("%d ", matrix[x][y]);
        visited[x][y] = 1;

        switch (direction)
        {
            case 6:
            if (isValid(x, y + 1, row, column)) y++;
            else 
            {
                direction = 8;
                x++;
            }
            break;

            case 8:
            if (isValid(x + 1, y, row, column)) x++;
            else 
            {
                direction = 3;
                y--;
            }
            break;

            case 3:
            if (isValid(x, y - 1, row, column)) y--;
            else 
            {
                direction = 2;                 
                x--;
            }
            break;

            case 2:
            if (isValid(x - 1, y, row, column)) x--;
            else 
            {
                direction = 6;
                y++;
            }
            break;
        }
    }  
}

int main(void)
{
    int rows, columns;
    scanf("%d %d", &rows, &columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    clockWiseSpiralOrder(rows, columns);
}