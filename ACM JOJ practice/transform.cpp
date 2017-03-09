/*
ID:chenfen5
PROB:transform
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;


int match_1(char pattern1[][10],char pattern2[][10],int num)
{
    int i,j;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(pattern1[i][j] != pattern2[j][num-1-i])
            break;
        }
        if(j!=num)
            break;
    }
    if(i!=num&&j!=num)
        return 0;
    else return 1;
}

int match_2(char pattern1[][10],char pattern2[][10],int num)
{
    int i,j;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(pattern1[i][j] != pattern2[num-1-i][num-1-j])
            break;
        }
        if(j!=num)
            break;
    }
    if(i!=num&&j!=num)
        return 0;
    else return 1;
}

int match_3(char pattern1[][10],char pattern2[][10],int num)
{
    int i,j;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(pattern1[i][j] != pattern2[num-1-j][i])
            break;
        }
        if(j!=num)
            break;
    }
    if(i!=num&&j!=num)
        return 0;
    else return 1;
}

int match_4(char pattern1[][10],char pattern2[][10],int num)
{
    int i,j;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(pattern1[i][j] != pattern2[i][num-1-j])
            break;
        }
        if(j!=num)
            break;
    }
    if(i!=num&&j!=num)
        return 0;
    else return 1;
}

int match_5(char pattern1[][10],char pattern2[][10],int num)
{
    int i,j;
    int count1=0,count2=0,count3=0;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(pattern1[i][j] == pattern2[num-1-j][num-1-i])
                count1++;
            if(pattern1[i][j] == pattern2[num-1-i][j])
                count2++;
            if(pattern1[i][j] == pattern2[j][i])
                count3++;
        }
    }
    int sum = num*num;
    if(count1==sum||count2==sum||count3==sum)
        return 1;
    else return 0;
}

int match_6(char pattern1[][10],char pattern2[][10],int num)
{
    int i,j;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(pattern1[i][j] != pattern2[i][j])
                break;
        }
        if(j!=num)
        break;
    }
    if(i!=num&&j!=num)
    return 0;
    else return 1;
}

int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    char pattern1[10][10],pattern2[10][10];
    int i,j;
    int num,type;
    fin>>num;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
            fin>>pattern1[i][j];
    }

    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
            fin>>pattern2[i][j];
    }

    if(match_1(pattern1,pattern2,num))
        type = 1;
    else if(match_2(pattern1,pattern2,num))
        type = 2;
    else if(match_3(pattern1,pattern2,num))
        type = 3;
    else if(match_4(pattern1,pattern2,num))
        type = 4;
    else if(match_5(pattern1,pattern2,num))
        type = 5;
    else if(match_6(pattern1,pattern2,num))
        type = 6;
    else
        type = 7;
    fout<<type<<endl;
    return 0;
}
