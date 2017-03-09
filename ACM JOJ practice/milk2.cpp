/*
ID:chenfen5
PROB:milk2
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;
int milk=0,nomilk=0;

struct Milking
{
    int start;
    int end;
}milking[5000],current;

void insert_sort(Milking* milking, int num)
{
    int i,j,k;
    for(i=0; i<num-1; i++)
    {
        j = i+1;
        for(k=i; k>=0; k--)
        {
            if(milking[j].start > milking[k].start)
                break;
        }
        int temp1 = milking[j].start;
        int temp2 = milking[j].end;
        for(; j>k+1; j--)
        {
            milking[j].start = milking[j-1].start;
            milking[j].end = milking[j-1].end;
        }
         milking[j].start = temp1;
         milking[j].end = temp2;
    }
}

int main()
{
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int temp1,temp2;
    int i;
    int num;

    fin>>num;
    for(i=0; i<num; i++)
        fin>>milking[i].start>>milking[i].end;

    insert_sort(milking,num);
    current = milking[0];
    for(i=1; i<num; i++)
    {
        if(milking[i].start>current.end)
        {
            temp2=milking[i].start - current.end;
            if(nomilk < temp2)
                nomilk = temp2;
            temp1 = current.end - current.start;
            if(milk<temp1)
                milk = temp1;
            current = milking[i];
        }
        else{
            if(milking[i].end > current.end)
             current.end = milking[i].end;
        }
    }
    if(milk < current.end - current.start)
            milk = current.end - current.start;
    fout<<milk<<" "<<nomilk<<endl;
    return 0;
}






