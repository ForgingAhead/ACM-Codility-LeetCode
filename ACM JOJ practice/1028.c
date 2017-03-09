#include "stdio.h"
#include "string.h"
int main()
{
    char keys[][9] = {"VISIT","BACK","FORWARD","QUIT"};
    char fwd[100][71];
    char bwd[100][71];
    int fwdindex=0,bwdindex=0;
    char cmmd[9];
    char curt[71] = "http://www.acm.org/";
    scanf("%s",cmmd);
    while(strcmp(cmmd,keys[3]))
    {
        if(strcmp(cmmd,keys[0]) == 0)
        {//VISIT
            strcpy(bwd[bwdindex],curt);
            scanf("%s",curt);
            bwdindex++;
            fwdindex = 0;
            printf("%s\n",curt);
        }
        else if(strcmp(cmmd,keys[1]) == 0)
        {//BACK
            if(bwdindex == 0)
                printf("Ignored\n");
            else
            {
                strcpy(fwd[fwdindex++],curt);
                strcpy(curt,bwd[--bwdindex]);
                printf("%s\n",curt);
            }
        }
        else if(strcmp(cmmd,keys[2]) == 0)
        {//BACKWARD
            if(fwdindex == 0)
                printf("Ignored\n");
            else
            {
                strcpy(bwd[bwdindex++],curt);
                strcpy(curt,fwd[--fwdindex]);
                printf("%s\n",curt);
            }
        }
        scanf("%s",cmmd);
    }
    return 0;
}

