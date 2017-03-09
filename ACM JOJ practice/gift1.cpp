/*
ID:chenfen5
PROB:gift1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int index(string str, string* name, int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        if(str == name[i])
            break;
    }
    return i;
}

int main()
{
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    string name[10], current;
    int i,j,k;
    int num, give,giveNum;
    int money[10]={0};

    fin>>num;
    for(i=0; i<num; i++)
        fin>>name[i];
    for(j=0; j<num && (fin>>current); j++)
    {
        fin>>give>>giveNum;
        if(giveNum!=0 && give)
        {
            int temp = give/giveNum;
            money[index(current,name,num)] -= give - give%giveNum;
            for(k=0; k<giveNum; k++)
            {
                fin>>current;
                money[index(current,name,num)]+=temp;
            }
        }
    }
    for(i=0; i<num; i++)
        fout<<name[i]<<" "<<money[i]<<endl;
}










