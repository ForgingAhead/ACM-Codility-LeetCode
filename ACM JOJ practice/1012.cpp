#include<stdio.h>
int main(){
	int a,b,c;
	
	int gcd;
	int cal_gcd(int,int);
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&a);
		getchar();
		getchar();
		scanf("%d",&b);
		getchar();
		getchar();
		scanf("%d",&c);
		gcd=cal_gcd(a,b);
		
		if(c%gcd==0)printf("%dx+%dy=%d has a solution.\n",a,b,c);
		else printf("%dx+%dy=%d has no solution.\n",a,b,c);
	}
	return 0;
}

int cal_gcd(int a ,int b){
	int temp;
	if(a==0)return b;
	if(b==0)return a;
	if(a>b){
	    temp=a%b;
		if(temp==0)return b;
		while(a%b){
			temp=a%b;
			a=b;
			b=temp;
		}
		return temp;
	}else{
		temp=b%a;
		if(temp==0)
			return a;
         while(b%a){
			temp=b%a;
			b=a;
			a=temp;
			
		}
		return temp;
	}
}



		
