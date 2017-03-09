/*
ID:chenfen5
PROB:namenum
LANG:C++
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
char list[][3]= {{' ',' ',' '},{' ',' ',' '},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},
            {'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
void find(string s);
void matchName(char* name,int m,string num);
ofstream fout("namenum.out");
string nameList[5000];
int maxi;
int cou;
int main() {
    string num;
    char name[12];
    ifstream fin("namenum.in");
    ifstream dictin("dict.txt");
    maxi=0;
    cou=0;
    while(!dictin.eof())
        dictin>>nameList[maxi++];
    fin>>num;
    matchName(name,0,num);
    if(cou==0)
        fout<<"NONE\n";
    return 0;
}

void matchName(char* name, int m, string num) {
    if(m<num.size()) {
        int n=m+1;
        for(int i=0;i<3;i++) {
            name[m] = list[num[m]-'0'][i];
            matchName(name,n,num);
        }
    }
    if(m==num.size()) {
        name[m]='\0';
        find(name);
    }
}

void find(string name) {
    int mid,h,l;
    h=maxi-1;
    l=0;
    mid=h/2;
    while(h>=l) {
        if(nameList[mid].compare(name)>0)
            h=mid-1;
        else if(nameList[mid].compare(name)<0)
            l=mid+1;
        else {
            fout<<name<<endl;
            cou++;
            break;
        }
        mid=(l+h)/2;
    }
}





