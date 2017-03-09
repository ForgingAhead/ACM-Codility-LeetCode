#include<stdio.h>
int main(){
	int num;
	int j,count=0;
	int time1[5],time2[5],time3[5];
	int time[3];
	int flag1=0,flag2=0,flag3=0;
	void cal_time(int *,int *);
	void print(int);
	int sch1[10],sch2[10],sch3[10];
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		flag1=flag2=flag3=0;
		for( j=0;j<10;j++)
			scanf("%d",&sch1[j]);
        for( j=0;j<10;j++)
			scanf("%d",&sch2[j]);
		for( j=0;j<10;j++)
			scanf("%d",&sch3[j]);
		
		cal_time(sch1,time1);//daxiao shijiancha
		cal_time(sch2,time2);
		cal_time(sch3,time3);
		while((!flag1||!flag2||!flag3)&&count!=3){
		  for(j=0;j<5;j++){
			if(flag1==0){
			 if(time1[j]>=1)
				if(time2[j]>=1)
					if(time3[j]>=1){
						time[0]=j;
						flag1=1;
                        continue;
					}
			}
			if(flag2==0&&flag1==1){
			    if(time1[j]>=2)
					if(time2[j]>=2)
						if(time3[j]>=2){
							time[1]=j;
							flag2=1;
							continue;
						}
			}
			if(flag3==0&&flag1==1&&flag2==1){
				if(time1[j]>=3)
					if(time2[j]>=3)
						if(time3[j]>=3){
							time[2]=j;
							flag3=1;
							continue;
						}
			}
		  }
		  count++;
		}
		if(flag1==flag2==flag3==1){
            printf("Case %d: ",i+1);
			print(time[0]);
			printf(" for 1 hour,then ");
			print(time[1]);
			printf(" for 2 hours,then ");
			print(time[2]);
			printf(" for 3 hours.\n");
		}else{
			printf("Case %d: The meetings cannot be scheduled.\n",i+1);
		}
	}
	return 0;
}


void cal_time(int *aa,int *tt){
	int i,j;
	for(i=0,j=0;i<10;i+=2,j++){
		if(aa[i+1]<aa[i])
			tt[j]=aa[i+1]+12-aa[i];
         else
			 tt[j]=aa[i+1]-aa[i];
	}
}


void print(int t){
	switch(t){
	case 0:
		printf("Monday");
		break;
	case 1:
		printf("Tuesday");
		break;
	case 2:
		printf("Wednesday");
		break;
	case 3:
		printf("Thursday");
		break;
	case 4:
		printf("Friday");
	}
}










			
				


			

