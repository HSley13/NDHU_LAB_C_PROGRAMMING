#include <stdio.h>
#include <string.h>

#define ROWS 9
#define COLS 9

char board[ROWS][COLS];
char visited[ROWS][COLS];

int depth_first_search(int i, int j) 
{
    if (i < 0 || j < 0 || i >= ROWS || j >= COLS) return 0;

    if (board[i][j] == 'O') return 1;

    if (board[i][j] == 'X') return 2;

    if (visited[i][j]) return 0;

    int flag = 0;
    visited[i][j] = 1;

    flag |= depth_first_search(i + 1, j);
    flag |= depth_first_search(i - 1, j);
    flag |= depth_first_search(i, j + 1);
    flag |= depth_first_search(i, j - 1);
    
    return flag;
}

int main() 
{
    int test_cases, i, j;
    scanf("%d", &test_cases);

    while (test_cases--) 
    {
        for (i = 0; i < ROWS; i++) scanf("%s", board[i]);

        int white_count = 0, black_count = 0;

        for (i = 0; i < ROWS; i++) 
        {
            for (j = 0; j < COLS; j++) 
            {
                if (board[i][j] == '.') 
                {
                    memset(visited, 0, sizeof(visited));
                    int flag = depth_first_search(i, j);

                    if (flag == 1) white_count++;

                    if (flag == 2) black_count++;
                } 

                else if (board[i][j] == 'O') white_count++;
                
                else black_count++;
            }
        }
        printf("Black %d White %d\n", black_count, white_count);
    }

    return 0;
}