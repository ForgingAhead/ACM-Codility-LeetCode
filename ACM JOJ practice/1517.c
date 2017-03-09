#include "stdio.h"
int main()
{
    int n=2,i;
    double e=2.5;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n1 2\n2 2.5\n");
    for(i=3; i<10; i++)
    {
        n = n*i;
        e += 1.0/n;
        printf("%d %.9lf\n",i,e);
    }
    return 0;
}
