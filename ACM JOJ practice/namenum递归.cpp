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
        int j;
        for(j=0;j<maxi;j++) {
            if(nameList[j].compare(name)==0) {
                    fout<<name<<endl;
                    cou++;
                    break;
            }
       }
    }
}

