#include<stdio.h>
#include<algorithm>
using namespace std;
int max(int x,int y,int z)
{
    if ((x>=y)&&(y>=z))return x;
    else if ((y>=x)&&(x>=z))return y;
    else return z;
}

int min(int x,int y,int z)
{
    if ((x<=y)&&(x<=z))return x;
    else if ((y<=x)&&(y<=z))return y;
    else return z;
}

void week(int i)
{
    switch (i)
    {
    case 1:
        printf("Monday ");
        break;
    case 2:
        printf("Tuesday ");
        break;
    case 3:
        printf("Wednesday ");
        break;
    case 4:
        printf("Thursday ");
        break;
    case 5:
        printf("Friday ");
        break;
    }
}

int main()
{
    int num,temp,ii=1;
    int A[10],B[10],C[10],R[5],P[3];
    int i,j,k,m,n,a,b,c;
    int flag1,flag2,flag3;
    scanf("%d",&num);
    while (ii<=num)
    {
        i=j=k=0;
        n=0;
        while (i<10)
        {
            scanf("%d",&temp);
            if ((temp<=5)&&(temp>0))temp+=12;
            A[i++]=temp;
        }
        while (j<10)
        {
            scanf("%d",&temp);
            if ((temp<=5)&&(temp>0))temp+=12;
            B[j++]=temp;
        }
        while (k<10)
        {
            scanf("%d",&temp);
            if ((temp<=5)&&(temp>0))temp+=12;
            C[k++]=temp;
        }
        for (m=0;m<10;m+=2)
        {
            a=max(A[m],B[m],C[m]);
            b=min(A[m+1],B[m+1],C[m+1]);
            c=b-a;
            if (c>0)R[n++]=c;
            else R[n++]=0;
        }
        P[0]=P[1]=P[2]=0;
        flag1=flag2=flag3=1;
        n=3;
        while (n)
        {
            for (m=0;m<5;m++)
            {
                if ((R[m]>0)&&flag1)
                {
                    P[0]=m+1;
                    flag1=0;
                    continue;
                }
                if ((R[m]>1)&&(flag1==0)&&flag2)
                {
                    P[1]=m+1;
                    flag2=0;
                    continue;
                }
                if ((R[m]>2)&&(flag1==0)&&(flag2==0))
                {
                    P[2]=m+1;
                    flag3=0;
                    continue;
                }
            }
            n--;
        }
        printf("Case %d: ",ii++);
        if (flag1==flag2==flag3==0)
        {
            week(P[0]);
            printf("for 1 hour, ");
            printf("then ");
            week(P[1]);
            printf("for 2 hours, ");
            printf("then ");
            week(P[2]);
            printf("for 3 hours.\n");
        }
        else
        {
            printf("The meetings cannot be scheduled.\n");
        }
    }
    return 0;
}

