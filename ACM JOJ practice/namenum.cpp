/*
ID:chenfen5
PROB:namenum
LANG:C++
*/
#include <iostream>

#include <fstream>

using namespace std;

int main()

{

    ifstream findata ("dict.txt");

    ifstream fin ("namenum.in");

    ofstream fout ("namenum.out");

    int s,i=1,flag=0;;

    string num,change,data;

    int j=0;

    fin >> num;

    while (findata >> data)

    {

        change="";

        for (j=0;j<data.size();j++)

        {

            if (data[j]=='A' || data[j]=='B' || data[j]=='C') change=change+"2";

            if (data[j]=='D' || data[j]=='E' || data[j]=='F') change=change+"3";

            if (data[j]=='G' || data[j]=='H' || data[j]=='I') change=change+"4";

            if (data[j]=='J' || data[j]=='K' || data[j]=='L') change=change+"5";

            if (data[j]=='M' || data[j]=='N' || data[j]=='O') change=change+"6";

            if (data[j]=='P' || data[j]=='R' || data[j]=='S') change=change+"7";

            if (data[j]=='T' || data[j]=='U' || data[j]=='V') change=change+"8";

            if (data[j]=='W' || data[j]=='X' || data[j]=='Y') change=change+"9";

        }

        if (change==num)

        {

            fout << data << endl;

            flag=1;

        }

    }

    if (flag==0) fout << "NONE" << endl;

    findata.close();

    fin.close();

    fout.close();

    return 0;

}
