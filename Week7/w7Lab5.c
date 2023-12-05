#include <stdio.h>
#include <limits.h>

#define SIZE 10001

int main()
{
	int rside = 0, lside = INT_MAX, i = 0, j = 0, l = 0, h = 0, r = 0;
	int ans[SIZE]= {0};

	while(scanf("%d %d %d", &l, &h, &r) == 3 && l != 0)
	{
		rside = (r > rside) ? r : rside;
		lside = (l < lside) ? l : lside;

		for (j = l; j < r; j++)
		{
			if (ans[j] < h) ans[j] = h;	
		}
	}

	for (i = lside; i < rside; i++)
	{
		if(ans[i] != ans[i-1])
		{
			if(ans[i] == 0) printf("%d 0 ", i);

			else printf("%d %d ", i, ans[i]);
		}
	}
  
	printf("%d 0", rside);

	return 0;
}