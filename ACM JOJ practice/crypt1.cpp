/*
ID:chenfen5
PROB:crypt1
LANG:C++
*/

#include <iostream>
#include <fstream>
using namespace std;
bool iscrypt(int n,int m);
int digits[10] = {0};

int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int num,i,j,k,m;
    int mult,multk,multh,multj,count=0;
    int pp1,pp2;
    fin>>num;
    for(i=0;i<num;i++) {
        fin>>j;
        digits[j]=1;
    }
    for(i=1;i<9;i++) {
        mult=0;
            if(digits[i]) {
                mult=i*100;
                for(k=1;k<10;k++) {
                    if(digits[k]) {
                        multk=mult+k*10;
                        for(int h=1;h<10;h++) {
                            if(digits[h]){
                                multh=multk+h;
                                int end = 10/i+1;
                                //multj=mult+multk+multh;
                                for(j=1;j<end;j++) {
                                    if(digits[j]) {
                                        pp2 = j*multh;
                                        if(pp2>999)continue;
                                        //pp2 = pp2*10;
                                        for(m=1;m<10;m++) {
                                            if(digits[m]) {
                                                pp1 = m*multh;
                                                if(pp1>999)continue;
                                                //cout<<pp1+pp2<<"------";////////////
                                                if(iscrypt(pp1,pp2)){
                                                    //cout<<pp1+pp2*10<<"&&"<<i<<k<<h<<" "<<j<<m<<"----";
                                                    count++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    }
    fout<<count<<endl;
    return 0;
}

bool iscrypt(int pp1,int pp2) {
    int count=0;
    int p1[3],p2[3],result[4];
    int k=0;
    int m = pp2*10+pp1;
    if(m>9999)return false;
    int number[10]={0};
    while(pp1>0) {
        p1[k] = pp1%10;
        p2[k] = pp2%10;
        result[k] = m%10;
        number[p1[k]] = 1;
        number[p2[k]] = 1;
        number[result[k]] = 1;
       // if(p1[k]==0||p2[k]==0)
         //   return false;
        pp1/=10;
        pp2/=10;
        m/=10;
        k++;
    }
    result[k] = m;
    number[result[k]] = 1;
    for(int h=0;h<10;h++)
        if(digits[h]<number[h])
            return false;

     return true;
}


