#include <stdio.h>



int main(void)
{
int n, i;
double sum, tmp;
	scanf("%d", &n);
	while(n)
	{
		sum = 0;
		for(i = 0; i < n; ++i)
		{
			scanf("%lf", &tmp);
			sum += tmp;
		}
		printf("%.15g\n", sum);
		scanf("%d", &n);
	}
	return 0;
}
