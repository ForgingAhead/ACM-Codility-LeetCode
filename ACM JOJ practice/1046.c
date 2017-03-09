#include "stdio.h"

int main()
{
    int g,r,b;
    int target[16][3];
    int i;
    for(i=0; i<16; i++)
        scanf("%d%d%d",&target[i][0],&target[i][1],&target[i][2]);
    int min,index;
    scanf("%d%d%d",&r,&g,&b);
    while(r!=-1)
    {
        index = 0;
        for(i=0; i<16; i++)
        {
            int temp = (r-target[i][0])*(r-target[i][0])+(g-target[i][1])*(g-target[i][1])+(b-target[i][2])*(b-target[i][2]);
            if(i==0)
                min = temp;
            else
            {
                if(min > temp)
                {
                    min = temp;
                    index = i;
                }
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,target[index][0],target[index][1],target[index][2]);
        scanf("%d%d%d",&r,&g,&b);
    }
    return 0;
}



