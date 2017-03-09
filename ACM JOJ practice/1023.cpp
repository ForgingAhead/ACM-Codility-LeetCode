#include<stdio.h>
int main(){
	char cc;
	int num=0;
	int root=0;
	int flag;
	char lastc='\n';
	scanf("%c",&cc);
	while(1){
      num=0;
	  if(lastc=='\n')
         if(cc=='0')break;
      while(cc!='\n'&&cc!='0'){
		num+=cc-48;
		lastc=cc;
		scanf("%c",&cc);
		while(cc=='0'){
			if(lastc!='\n'){
				lastc=cc;
				scanf("%c",&cc);
			}
			 else break;
		}
	  }
	    flag=1;
		root=0;
		while(flag){
		   while(num/10!=0){
			  root+=num%10;
			  num/=10;
		   }
		   root+=num;
		   if(root/10!=0){
			 num=root;
			 root=0;
		   }
		   else flag=0;
		}
		if(flag==0)printf("%d\n",root);
	
	  lastc=cc;
	  scanf("%c",&cc);
	}
    return 0;
}
