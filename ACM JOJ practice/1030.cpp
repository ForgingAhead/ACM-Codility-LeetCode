#include<stdio.h>
int main(){
	void showName(int);
	int p,s;
	int result;
	int count=0;
    while(scanf("%d",&p),p){
        scanf("%d",&s);
		
         printf("Hole #%d\n",++count);
		 if(s==1){
			 printf("Hole-in-one.\n");
		 }else{
		   result=p-s;
		   showName(result);
		 }
		 printf("\n");
	}
	
	return 0;
}


void showName(int r){
	
	if(r<0){
		switch(r){
		case -1:printf("Bogey.\n");break;
		
		default:printf("Double Bogey.\n");break;
		}
	}
	else{
		switch(r){
		case 1:
			printf("Birdie.\n");
			 break;
		case 2:printf("Eagle.\n");
			break;
		case 3:printf("Double Eagle.\n");break;
		default:printf("Par.\n");break;
		}
	}
}