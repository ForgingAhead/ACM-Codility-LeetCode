#include<stdio.h>
int main(){
	int num,flag=1;
	double hangOver;
	while(scanf("%d",&num)!=EOF){
		hangOver=0.0;
		for(int i=0;i<num;i++)
			hangOver+=1.0/((i+1)*2);
		if(flag){
			printf("# Cards  Overhang\n");
			flag=0;
		}
		printf("%5d%10.3lf\n",num,hangOver);
	}
	return 0;
}



