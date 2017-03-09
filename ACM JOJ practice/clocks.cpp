/*
ID:chenfen5
PROB:clocks
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void matchPattern(int clock[],int num);
bool is12(int clock[], int num);
vector< vector<int> > pattern;
void init();
int main() {
    ifstream fin("clocks.in");
    ofstream fout("clocks.out");

    int clock[9];
    int i,j;
    for(i=0; i<9; i++)
        fin>>clock[i];
    init();
    while(!is12(clock,9)) {
        matchPattern(clock,9);
    }
    return 0;
}

void init() {
    int A[4]={0,1,2,3};
    int B[3]={0,1,2};
    int C[4]={1,2,4,5};
    int I[3]={0,3,6};
    int D[5]={1,3,4,5,7};
    int E[3]={2,5,8};
    int F[4]={3,4,6,7};
    int G[3]={6,7,8};
    int H[4]={4,5,7,8};
    pattern.push_back(A);
    pattern.push_back(B);
    pattern.push_back(C);
    pattern.push_back(I);
    pattern.push_back(D);
    pattern.push_back(E);
    pattern.push_back(F);
    pattern.push_back(G);
    pattern.push_back(H);
}

void matchPattern(int clock[], int num) {
    int i,j;
    int max=0,count=0;
    for(i=0;i<pattern.size();i++) {
        count=0;
        for(j=0; j<)




