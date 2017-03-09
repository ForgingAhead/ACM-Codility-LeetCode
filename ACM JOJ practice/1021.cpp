#include<stdio.h>
int main(){
    int array[1000001]={0};//////////////bukexing!!!!!1
    int i;
	int temp1,temp2;
	for(i=0;i<1000001;i++){
		temp1=temp2=i;
		while(temp1){
			temp2+=temp1%10;
			temp1/=10;
		}
		array[temp2]=1;
	}
	for(i=0;i<1000001;i++){
		if(array[i]==0){
			printf("%d\n",i);
		}
	}
	return 0;
}


 


