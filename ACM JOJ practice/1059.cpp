#include<stdio.h>
int main(){
	int count=1,flag1=1,flag2=1;
	int score,topClass,max=0,maxInClass=0;
	int class_max[200];
	while(flag1){
		
		maxInClass=0;
		flag2=1;
		while(flag2){
			scanf("%d",&score);
		  if(score>0){
			if(max<score){
				max=score;
				topClass=count;
			}
			if(score>maxInClass)maxInClass=score;

		}else 
			if(score==0){
				flag2=0;
				count++;
				
			}
			else if(score==-1){
				flag1=0;
				break;
			}
			
		}
        if(flag1)class_max[count-1]=maxInClass;
	}
	for(int i=1;i<count;i++)
		printf("%d\n",class_max[i]);
	printf("%d At Class %d\n",max,topClass);
	return 0;
}



