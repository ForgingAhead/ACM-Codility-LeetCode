#include "stdio.h"

int main()
{
    float cb;
    float sum = 0.0;
    int i;
    for(i=0; i<12; i++)
    {
        scanf("%f",&cb);
        sum += cb;
    }
    printf("$%.2f",sum/12.0);
    return 0;
}
