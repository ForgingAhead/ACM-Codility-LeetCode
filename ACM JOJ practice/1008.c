#include "stdio.h"
#include "string.h"
char month1[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char month2[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main()
{
 int n,i,j;
 scanf("%d",&n);
 printf("%d\n",n);
 for(i=0;i<n;i++)
 {
  int day,year,dates;
  char month[10];
  scanf("%d.%s%d",&day,month,&year);
  for(j=0;j<19;j++)
  {
   if(!strcmp(month1[j],month))
    break;
  }
  dates=year*365+j*20+day;
  printf("%d %s %d\n",dates%13+1,month2[dates%20],dates/260);
 }
 system("pause");
 return 0;
}
