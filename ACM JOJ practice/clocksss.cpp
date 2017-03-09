/*
ID:chenfen5
PROB:clocks
LANG:C++
*/

#include <fstream>

#define MAX 262144    //数组开这么大就ok了

using namespace std;

const short rules[9][6]={{4,0,1,3,4},
                         {3,0,1,2},
                         {4,1,2,4,5},
                         {3,0,3,6},
                         {5,1,3,4,5,7},
                         {3,2,5,8},
                         {4,3,4,6,7},
                         {3,6,7,8},
                         {4,4,5,7,8}};
    //规则常量 rules[x][0]表示移动的表数量 后面表的编号为了方便运算从0开始

unsigned int father[MAX];    //记录父节点
int s[MAX];                    //宽搜队列 记录状态
short set[MAX];                //记录操作
bool f[MAX];                //散列表

ofstream fout("clocks.out");

void change(short s[], int &x, const bool f);    //进制转换
void input();                                    //输入
void output(const unsigned int x);                //输出
void expand(const unsigned int a,unsigned int &b,const short c);    //宽搜扩展节点
void lookfor();                                    //BPS

int main()
{
    input();
    lookfor();
}

void change(short s[], int &x, const bool f)//f=true时表示4->10 反之10->4 x十进制 s四进制
{
    if (f)
    {
        x=0;
        short i;
        int t=1;
        for (i=0; i<9; i++)
        {
            x+=s[i]*t;
            t*=4;
        }
    }
    else
    {
        int t=x;
        for (short i=0; i<9; i++)
        {
            s[i]=t%4;
            t/=4;
        }
    }
}    //这个进制转换就不多说了吧。。。

void input()
{
    ifstream fin("clocks.in");
    short t[9];
    for (short i=0; i<9; i++)
    {
        fin>>t[i];
        t[i]=t[i]/3-1;    //为了方便运算 规定3点记为0 12点记为3
    }
    fin.close();
    change(t,s[0],true);
    f[s[0]]=true;
}

void output(const unsigned int x)
{
    if (father[x]>0)
        output(father[x]);    //回溯输出 其实用写一个循环就好了 但是懒的写 这个好写
    fout<<set[x]+1<<" ";    //别忘了+1
}

void expand(const unsigned int a,unsigned int &b,const short c)
    //a 父节点 b子节点 c拓展规则
{
    short t[9];
    change(t,s[a],false);
    short i;
    for (i=1; i<=rules[c][0]; i++)
    {
        t[rules[c][i]]++;
        if (t[rules[c][i]]==4)
            t[rules[c][i]]=0;
    }
    change(t,s[b],true);
        //以上进行操作
    if (f[s[b]]==false)    //判断状态是否重复
    {
        father[b]=a;
        set[b]=c;
        if (s[b]==(MAX-1))    //不-1就死循环了 不信你试试 具体原理问数学老师去吧
        {
            if (father[b]>0)
                output(father[b]);
            fout<<set[b]+1<<endl;    //最后一步单独输出 因为他后面没有空格并且要有空行
            fout.close();
            exit(0);        //直接退出程序
        }
        f[s[b++]]=true;    //记录状态    小小地利用了一下b的副效应
    }
}

void lookfor()
{
    unsigned int j=0,k=1;
    short i;
    for (;;j++)
    //没错 这是一个死循环 因为数组肯定够用 并且肯定有解 找到解就直接退出了 但千万别忘j++
        for (i=0; i<9; expand(j,k,i++));    //扩展节点 注意i的副效应
}
