/*
ID:chenfen5
PROB:palsquare
LANG:C++
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string tobase(int n, int base);
bool ispalin(string s);
string letter[20]={"0\0","1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0",
                    "A\0","B\0","C\0","D\0","E\0","F\0","G\0","H\0","I\0","J\0"};
ofstream fout("palsquare.out");
int main() {
    ifstream fin("palsquare.in");

    int base,i;
    fin>>base;
    fout<<1<<" "<<1<<endl;
    for(i=2; i<=300; i++) {
        int num=i*i;
        string s=tobase(num,base);
        if(ispalin(s))
            fout<<tobase(i,base)<<" "<<s<<endl;
    }
    return 0;
}

bool ispalin(string s) {
    for(int i=0,j=s.size()-1;i<j;i++,j--)
        if(s[i]!=s[j])
            return false;
    return true;
}

string tobase(int n, int base) {
    string s;
    int temp;
    while(n>=base) {
        temp=n%base;
        n=n/base;
        s.insert(0,letter[temp]);
    }
    s.insert(0,letter[n]);
    return s;
}



