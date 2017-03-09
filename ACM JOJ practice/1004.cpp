#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 10000

int main(void)
{
char from[MAXLENGTH], to[MAXLENGTH];
int num, cur, index, temp, j;
	while(scanf("%s", from) != EOF)
	{
		strcpy(to, "");
		cur = strlen(from) - 1;
		index = 0;


		while(cur > 1)
		{
			num = from[cur--] - '0';
			for(j = 0; j < index; ++j)
			{
				num *= 10;
				temp = num + to[j] - '0';
				to[j] = temp / 8 + '0';
				num = temp % 8;
			}
			while(num)
			{
				num *= 10;
				to[j++] = num / 8 + '0';
				num %= 8;
			}
			index = j;
		}


		to[j] = '\0';
		printf("%s [8] = 0.%s [10]\n", from, to);
	}
	return 0;
}
			







