#include<stdio.h>
int main(){
	int n,num1,num2;
	int n1,n2;
	int nn1[16],nn2[16];
	int cal(int,int,int*);
	void sum_out(int,int*,int *,int ,int);
	while((scanf("%d",&n)!=0)&&n>=2&&n<=10){
		scanf("%d%d",&num1,&num2);
		if(n==10)
			printf("%d+%d=%d\n",num1,num2,num1+num2);
		else{
			n1=cal(n,num1,nn1);
			n2=cal(n,num2,nn2);
			for(int i=n1;i>-1;i--)
			     printf("%d",nn1[i]);
			printf(" + ");
			for(int j=n2;j>-1;j--)
				printf("%d",nn2[j]);
			printf(" = ");
			if(n1>=n2)sum_out(n,nn1,nn2,n1,n2);
			else sum_out(n,nn2,nn1,n2,n1);
		}
		
	}
	return 0;
}


int cal(int n,int num,int *p){
	int i=0;
	while((num/n)!=0){
		p[i++]=num%n;
		num/=n;
	}
	p[i]=num;
	return i;
}


void sum_out(int n,int*p1 ,int* p2,int n1,int n2 ){
	int carry=0;
	int sum[17];
	int ii;
	for(int i=0;i<=n2;i++){
        if(((p1[i]+p2[i]+carry)/n)!=0){
			sum[i]=(p1[i]+p2[i]+carry)%n;
			carry=1;
			
		}else{
			sum[i]=p1[i]+p2[i]+carry;
			carry=0;
		}
	}
	for( ii=n2+1;ii<=n1;ii++){
		 if((carry+p1[ii])/n!=0){
			 sum[ii]=(carry+p1[ii])%n;
			 carry=1;
			 
		 }else{
			 sum[ii]=carry+p1[ii];
			 carry=0;
		 }
	}
	int num=ii-1;
    if(carry==1){
		sum[ii]=1;
		num=ii;
	}
    for(int j=num;j>=0;j--){
		printf("%d",sum[j]);
	}
	printf("\n");
}



		
	

			

