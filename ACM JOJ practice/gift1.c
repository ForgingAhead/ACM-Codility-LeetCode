/*
ID:chenfen5
LANG:C
TASK:gift1
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int indx(char current[14],char name[][14],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(strcmp(current,name[i])==0)
            break;
    }
    return i;
}

int main()
{
    FILE * fin = fopen("gift1.in","r");
    FILE * fout = fopen("gift1.out","w");
    char name[10][14];
    int i,j,k,m, num, id;
    int giveNum, money[10]={0,0,0,0,0,0,0,0,0,0},give;
    char current[14];
    fscanf(fin,"%d\n",&num);
    for(i=0; i<num; i++)
    {
        fgets(name[i],sizeof(current),fin);
    }
    for(j=0; j<num&&fgets(current,sizeof(current),fin); j++)
    {
        id = indx(current,name,num);
        fscanf(fin,"%d%d",&give,&giveNum);
        if(giveNum!=0)
        {
            int temp = give/giveNum;
            money[id] = money[id] - give + give%giveNum;
            for(k=0; k<giveNum; k++)
            {
                fgets(current,sizeof(current),fin);
                money[indx(current,name,num)] += temp;
            }
        }
    }
    for(i=0; i<num; i++)
    {
        for(m=0; m<14&&name[i][m]!='\n'; m++)
            fprintf(fout,"%c",name[i][m]);
        fprintf(fout," %d\n",money[i]);
    }
    return 0;
}

