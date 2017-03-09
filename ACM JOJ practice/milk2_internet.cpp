/*
ID: chenfen5
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("milk2.in");
ofstream fout("milk2.out");
struct time
{
  int start;
  int end;
}milk[5000], present;
int N, MaxWork = 0, MaxBreak = 0;
int Partition(int first, int end);
void QuickSort(int first, int end);
void compute(int j);
bool intersection(struct time, struct time);//判断是否有交集
struct time unite(struct time, struct time);//求并集

int
main()
{
  fin >> N;
  for (int j = 0; j < N; j++)
      fin >> milk[j].start >> milk[j].end;
  QuickSort(0, N - 1);
  present = milk[0];

  for (int j = 1; j < N; j++)
      compute(j);
  MaxWork = max(MaxWork, present.end - present.start);
  fout << MaxWork << ' ' << MaxBreak << endl;
  return 0;
}

void
compute(int j)
{
  if (intersection(milk[j], present))
      present = unite(milk[j], present);
  else
    {
      MaxWork = max(MaxWork, present.end - present.start);
      MaxBreak = max(MaxBreak, milk[j].start - present.end);
      present = milk[j];
    }
}

bool
intersection(struct time a, struct time b)
{
  if (a.end < b.start || b.end < a.start)
      return false;
  else
      return true;
}

struct time
unite(struct time a, struct time b)
{
  struct time x;
  x.start = min(a.start, b.start);
  x.end = max(a.end, b.end);
  return x;
}

void
QuickSort(int first, int end)
{
  if (first < end)
    {
      int pivot = Partition(first, end);
      QuickSort(first, pivot - 1);
      QuickSort(pivot + 1, end);
    }
}
int
Partition(int first, int end)
{
  int i = first, j = end;
  while (i < j)
    {
      while (i < j && milk[i].start <= milk[j].start)
          j--;
      if (i < j)
        {
          swap(milk[i], milk[j]);
          i++;
        }
      while (i < j && milk[i].start <= milk[j].start)
          i++;
      if (i < j)
        {
          swap(milk[i], milk[j]);
          j--;
        }
    }
  return i;
}
