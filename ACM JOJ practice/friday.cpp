/*
ID:chenfen5
PROB:friday
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;

int isleap(int y)
{
    if((y%400 == 0) || (y%4==0&&y%100!=0))
        return 1;
    else return 0;
}

int main()
{
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    int days=13, week = 6, year=1900, n, i, j;
    int wk[7]={0};
    wk[6]=1;
    int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    fin>>n;
    for(i=0; i<n; i++)
    {
        if(isleap(year))
        {
            for(j=1; j<13; j++)
            {
               if(j==2)
                    days = mon[j] + 1;
                else days = mon[j];
                week = (week + days%7) % 7;
                wk[week]++;
            }
        }
        else
        {
            for(j=1; j<13; j++)
            {
                week = (week + mon[j]%7)%7;
                wk[week]++;
            }
        }
        year++;
    }
    wk[week]--;
    fout<<wk[6]<<" ";
    fout<<wk[0]<<" ";
    for(i=1; i<5; i++)
        fout<<wk[i]<<" ";
    fout<<wk[i]<<endl;
    return 0;
}
