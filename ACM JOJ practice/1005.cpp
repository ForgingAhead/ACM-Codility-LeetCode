#include <stdio.h>
int main(){
	long num;
	scanf("%ld",&num);
	while(num){
		
		if((num-2)%4==0) 
			printf("%ld is the sum of four consecutive integers.\n",num);
		 else
			printf("%ld is not the sum of four consecutive integers.\n",num);
		scanf("%ld",&num);
	}
    return 0;
}