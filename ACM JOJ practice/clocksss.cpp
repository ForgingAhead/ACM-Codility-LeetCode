/*
ID:chenfen5
PROB:clocks
LANG:C++
*/

#include <fstream>

#define MAX 262144    //���鿪��ô���ok��

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
    //������ rules[x][0]��ʾ�ƶ��ı����� �����ı��Ϊ�˷��������0��ʼ

unsigned int father[MAX];    //��¼���ڵ�
int s[MAX];                    //���Ѷ��� ��¼״̬
short set[MAX];                //��¼����
bool f[MAX];                //ɢ�б�

ofstream fout("clocks.out");

void change(short s[], int &x, const bool f);    //����ת��
void input();                                    //����
void output(const unsigned int x);                //���
void expand(const unsigned int a,unsigned int &b,const short c);    //������չ�ڵ�
void lookfor();                                    //BPS

int main()
{
    input();
    lookfor();
}

void change(short s[], int &x, const bool f)//f=trueʱ��ʾ4->10 ��֮10->4 xʮ���� s�Ľ���
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
}    //�������ת���Ͳ���˵�˰ɡ�����

void input()
{
    ifstream fin("clocks.in");
    short t[9];
    for (short i=0; i<9; i++)
    {
        fin>>t[i];
        t[i]=t[i]/3-1;    //Ϊ�˷������� �涨3���Ϊ0 12���Ϊ3
    }
    fin.close();
    change(t,s[0],true);
    f[s[0]]=true;
}

void output(const unsigned int x)
{
    if (father[x]>0)
        output(father[x]);    //������� ��ʵ��дһ��ѭ���ͺ��� ��������д �����д
    fout<<set[x]+1<<" ";    //������+1
}

void expand(const unsigned int a,unsigned int &b,const short c)
    //a ���ڵ� b�ӽڵ� c��չ����
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
        //���Ͻ��в���
    if (f[s[b]]==false)    //�ж�״̬�Ƿ��ظ�
    {
        father[b]=a;
        set[b]=c;
        if (s[b]==(MAX-1))    //��-1����ѭ���� ���������� ����ԭ������ѧ��ʦȥ��
        {
            if (father[b]>0)
                output(father[b]);
            fout<<set[b]+1<<endl;    //���һ��������� ��Ϊ������û�пո���Ҫ�п���
            fout.close();
            exit(0);        //ֱ���˳�����
        }
        f[s[b++]]=true;    //��¼״̬    СС��������һ��b�ĸ�ЧӦ
    }
}

void lookfor()
{
    unsigned int j=0,k=1;
    short i;
    for (;;j++)
    //û�� ����һ����ѭ�� ��Ϊ����϶����� ���ҿ϶��н� �ҵ����ֱ���˳��� ��ǧ�����j++
        for (i=0; i<9; expand(j,k,i++));    //��չ�ڵ� ע��i�ĸ�ЧӦ
}
