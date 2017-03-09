#include<stdio.h>
int main(){
	int m,n;
	int max;
	int num;
	while(scanf("%d%d",&m,&n),m!=0&&n!=0){
		int count;
		count=m*n;
		for(int i=0;i<count;i++){
			scanf("%d",&num);
			if(i==0)max=num;
			else {
				if(max<num)max=num;
			}
		}
		printf("%d\n",max);
	
	}
	return 0;

}