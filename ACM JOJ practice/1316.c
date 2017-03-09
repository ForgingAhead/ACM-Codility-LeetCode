#include "stdio.h"
int flag[10001]={0};
int d(int n);
int main()
{
    int n = 1;
    while(n<10000)
    {
        flag[d(n)] = 1;
        n++;
    }

    for(n=1; n<10000; n++)
        if(flag[n]==0)
            printf("%d\n",n);
    return 0;
}

int d(int n)
{
    int sum=n;
    int tmp;
    while(n)
    {
        tmp = n%10;
        sum += tmp;
        n = n/10;
    }
    return sum;
}
