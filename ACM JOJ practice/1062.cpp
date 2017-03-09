#include<stdio.h>
int main(){
	int a,b,pro;
	int gcd,lcm;
	int tmp;
	while(scanf("%d%d",&a,&b),a&&b){
		if(a<b){
			tmp=a;
			a=b;
			b=tmp;
		}
        pro=a*b;
		while(b){
			tmp=a%b;
			a=b;
			b=tmp;
		}
		gcd=a;
		lcm=pro/gcd;
		printf("%d %d\n",gcd,lcm);
	}
	return 0;
}
