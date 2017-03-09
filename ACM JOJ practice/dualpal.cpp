/*
ID:chenfen5
PROB:dualpal
LANG:C++
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string tobase(int n, int base);
bool ispalin(string s);
string letter[10]={"0\0","1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0"};

int main() {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int n,s,base,count=0;
    fin>>n>>s;
    for(int j=0;j<n;j++) {
        count=0;
        s++;
        while(count<2) {
            base=2;
            while(base<=10) {
                string str=tobase(s,base);
                if(ispalin(str))
                    count++;
                if(count==2)
                    break;
                base++;
            }
            if(base==11 && count<2) {
                s++;
                count=0;
            }
        }
        fout<<s<<endl;
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



