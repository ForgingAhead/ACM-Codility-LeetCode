/*
ID:chenfen5
PROB:milk
LANG:C++
*/

#include <iostream>
#include <fstream>
using namespace std;
void sort(int n, int* price, int* amount);
int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n,m;
    int i=0,left;
    int mincost=0;
    fin>>n>>m;
    left=n;
    int* amount = new int[m];
    int* price = new int[m];
    for(int j=0;j<m;j++)
        fin>>price[j]>>amount[j];
    sort(m,price,amount);
    while(left>amount[i]) {
        mincost+=price[i]*amount[i];
        left-=amount[i];
        i++;
    }
    if(left>0)
        mincost+=price[i]*left;
    fout<<mincost<<endl;
    delete [] price;
    delete [] amount;
    return 0;
}

void sort(int m, int* price, int* amount) {
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




