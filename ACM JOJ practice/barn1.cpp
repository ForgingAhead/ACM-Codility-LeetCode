/*
ID:chenfen5
PROB:barn1
LANG:C++
*/

#include <iostream>
#include <fstream>
using namespace std;
void sort(int m,int* p);
//void sort2(int m,int* p, int* n);
int main() {
    int m,s,c;
    int i,j=0;
    int amount=0,length=0;
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    fin>>m>>s>>c;
    int* stall = new int[c];
    //int* bkp = new int[s-c];
    int* bka = new int[s-c];
    for(i=0;i<c;i++)
        fin>>stall[i];
    sort(c,stall);
    for(i=0;i<c-1;i++) {
        if((stall[i]+1)!=stall[i+1]) {
            bka[j]=stall[i+1]-stall[i]-1;
            j++;
        }
    }
    amount = j;
    length = c;
    if(j+1>m) {
       sort(amount,bka);
       j=0;
       amount++;
       while(amount>m) {
           //cout<<bka[j]<<" *** ";//////////
           length+=bka[j++];
           amount--;
       }
    }
    fout<<length<<endl;
    delete [] stall;
    //delete [] bkp;
    delete [] bka;
    return 0;
}

void sort(int m, int* price) {
    int i=0,j=1,k=m;
    bool flag=true;
    while(flag) {
        i=0;
        j=1;
        flag = false;
        while(j<k) {
            if(price[i]>price[j]) {
                int temp = price[i];
                price[i] = price[j];
                price[j] = temp;
                flag = true;
            }
            i++;
            j++;
        }
        k--;
    }
}
/*
void sort2(int m, int* price, int* amount) {
    int i=0,j=1,k=m;
    bool flag=true;
    while(flag) {
        i=0;
        j=1;
        flag = false;
        while(j<k) {
            if(price[i]>price[j]) {
                int temp = price[i];
                price[i] = price[j];
                price[j] = temp;
                temp = amount[i];
                amount[i] = amount[j];
                amount[j] = temp;
                flag = true;
            }
            i++;
            j++;
        }
        k--;
    }
}
*/

