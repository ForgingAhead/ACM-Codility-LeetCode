#include<stdio.h>  //only by 2  3  5 
int main(){
	int count=0;
	int val;
	while(count<1500){
             if(count==0)val=1;
			 else if(count==1)val=2;
			 else if(count==2)val=3;
			 else if(count==3)val=4;
			 else if(count==4)val=5;
			 else{
				 while(1){
					 val++;
					 int num=val;
					 while(num%2==0)num/=2;
                     while(num%3==0)num/=3;
	                 while(num%5==0)num/=5;
	                 if(num==1)break;
				 }
			 }
			 count++;
			 if(count!=1500)
			     printf("%d,",val);
             else printf("%d",val);
		}
	 return 0;
}