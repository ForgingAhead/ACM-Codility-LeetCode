#include<stdio.h>
int main(){
	double e=2.5;
	double temp;
	
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	temp=1.0/2.0;
	for(int i=3;i<10;i++){
		printf("%d ",i);
		temp/=i;
		
		e+=temp;
		printf("%.9lf\n",e);
	}
	return 0;
}


