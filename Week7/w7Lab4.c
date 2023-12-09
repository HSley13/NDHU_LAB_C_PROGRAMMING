#include<stdio.h>
int main()
{
    int n, k;

    while(scanf("%d %d", &n, &k) && n != 0 && k != 0)
	{
        if(n == 1) printf("%d\n", n);

        else
		{
            int arr[101];
            for (int i = 1; i <= n; i++)
			{
                arr[i] = i;
            }

            int dead, count = 1, total = n;
			
            while (total > 1)
			{
                int num = 0;
                while (num < k)
				{
                    if (count > n) count = 1;

                    if (arr[count] > 0) num++;
                
                    count++;
                }

                dead = count - 1;
                arr[dead] = 0;
                num = 0;

                while (num < k)
				{
                    if (count > n) count = 1;

                    if (arr[count] > 0) num++;
                    
                    count++;
                }

                int temp = arr[dead];
                arr[dead] = arr[count - 1];
                arr[count - 1] = temp;

                count = dead + 1;
                total--;
            }

            int survive = dead;

            if (arr[survive] == 1) printf("1\n");

            else printf("%d\n", n-(arr[survive]-1)+1);
            
        }
    }
    return 0;
}
/*
          1(1)
     5(5)    2(2)
      4(4)  3(3)


        1
     5    4
      0  3

       1
     4    0
      0  3

       0
     4    0
      0  1

       0
     0    0
      0  4
*/