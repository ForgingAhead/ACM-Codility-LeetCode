#include "stdio.h"
int main()
{
    float pai = 3.1415926;
    float x,y;
    double sq;
    int i,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%f %f",&x,&y);
        sq = 0.5*pai*(x*x+y*y);
        int year = sq/50.0;
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, year+1);
    }
    printf("END OF OUTPUT.");
    return 0;
}
