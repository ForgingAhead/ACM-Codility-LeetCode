#include<stdio.h>
int  main(){
	int num;
	int i,j,flag=0;
	char lastc;
	int array[100];
	for(i=0;i<100;i++){
	     scanf("%d",&(array[i]));
		 if(array[i]==0)break;
	}
	num=array[0];
	int count=1;
    while(num!=0){
		lastc='a';
		for(i=0;i<num;i++){
            if(lastc=='z'){
				printf("z");
				lastc='a';
			}
			else
				printf("%c",lastc++);
		}
		printf("\n");
		for(i=0;i<num-2;i++){
			for(j=0;j<num-2-i;j++)printf(" ");
			if(lastc=='z'){
				printf("z");
				lastc='a';
			}
			else
				printf("%c",lastc++);
			printf("\n");
		}
		for(i=0;i<num;i++){
            if(lastc=='z'){
				printf("z");
				lastc='a';
			}
			else
				printf("%c",lastc++);
		}
		if(flag==0)printf("\n\n");
		num=array[count++];
		if(array[count]==0)flag=1;
	}

	return 0;
}


