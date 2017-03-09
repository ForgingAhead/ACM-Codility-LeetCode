/*
ID:chenfen5
PROB:beads
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    char c;
    char beads[700];

    int num,i,j;
    int no1=0,no2=0,sum=0;

    fin>>num;
    for(i=0; i<num; i++)
    {
        fin>>beads[i];
        beads[num+i] = beads[i];
    }
    for(j=0; j<num; j++)
    {
        while(beads[j]=='w'&&j<num)
        {
            j++;
            no1++;
        }
        if(j<num)
        {
            c = beads[j];
            no1++;
            int n = num + j;
            for(i=j+1; i<n; i++)
            {
                if(beads[i] == c || beads[i] == 'w')
                {
                    no1++;
                    continue;
                }
                break;
            }
        }
        if(no1+no2>sum)
            {
                sum = no1+no2;
                no2 = no1;
                no1 = 0;
            }
            else
            {
                int k = i-1-no1;
                while(k>0&&beads[k]=='w')
                {
                    k--;
                    no1++;
                }
                no2 = no1;
                no1 = 0;
            }
            j = i-1;

    }
    fout<<sum<<endl;
    return 0;
}







