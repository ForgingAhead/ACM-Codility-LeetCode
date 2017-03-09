#include<stdio.h>
#include<math.h>
int main(){
	int num;
	while(scanf("%d",&num)!=EOF&&num){
		int n;
		n=(int)(-1+sqrt(1+8*num))/2;
		if(n*(n+1)/2==num){
			printf("%d is a triangular number.\n",num);
			for(int i=1;i<=n;i++){
				for(int j=0;j<i;j++)
					printf("*");
				printf("\n");
			}
		}else{
			printf("%d is not a triangular number.\n",num);
		}
	}
	return 0;
}


       