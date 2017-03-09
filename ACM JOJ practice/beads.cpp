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
        c = beads[j];
        no1++;
        if(c=='w')
        {
            c = beads[++j];
            while(c=='w'&&j<num)
            {
                no1++;
                c = beads[++j];
            }
        }
        if(j<num){
        int n = num + j;
        cout<<n<<endl;/////////////
        for(i=j+1; i<n; i++)
        {
            if(beads[i] == c||beads[i] =='w')
            {
                no1++;
                continue;
            }
            else
                break;
        }
        }
        if(no1+no2 > sum)
        {
            sum = no1+no2;
            no2 = no1;
        }
        else
        {
            no2 = no1;
            while(beads[i-1]=='w'&&i>0)
            {
                i--;
                no2--;
            }
        }
        no1 = 0;
        j = i - 1;
        cout<<j<<endl;/////////////
    }
    fout<<sum<<endl;
    return 0;
}






