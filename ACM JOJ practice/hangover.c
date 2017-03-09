#include "stdio.h"

int main()
{
    float c;
    float j = 1.0;
    scanf("%f",&c);
    while(c!=0.00)
    {
        //printf("c:%f\n",c);
        j = 1.0;
        while( c > 0.0)
        {
            //printf("here! j: %f \n",j);
            j += 1.0;
            c -= (1.0/j);
        }
        printf("%d card(s)\n",(int)j-1);
        scanf("%f",&c);
    }
    return 0;
}
