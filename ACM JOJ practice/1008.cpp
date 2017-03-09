#include<stdio.h>
#include<string.h>
#define MAXLENTH  1000 
int main(){
	char str1[MAXLENTH],str2[MAXLENTH];
	int cur;
	int i,j,k=0;
	int num;
	char temp1,temp2;
	int flag=0;
	scanf("%d",&num);
	getchar();
	for(i=0;i<num;i++){
		flag=0;
		k=0;
		gets(str1);
		cur=strlen(str1);
		for(j=cur-1;j>-1;j--)
			str2[k++]=str1[j];
		str2[k]='\0';
		k--;
		for(j=0,k=0;j<cur;){
			if((str1[j]>='A'&&str1[j]<='Z')||(str1[j]>='a'&&str1[j]<='z')){
				if((str2[k]>='A'&&str2[k]<='Z')||(str2[k]>='a'&&str2[k]<='z')){
					flag=1;
					temp1=str1[j];
					temp2=str2[k];
					if(str1[j]>='A'&&str1[j]<='Z')
						 temp1=str1[j]-'A'+'a';
                     if(str2[k]>='A'&&str2[k]<='Z')
						 temp2=str2[k]-'A'+'a';

					if(temp1!=temp2){
						printf("%s is not a palindrome.\n",str1);
						break;
					}
					else{
						k++;
						j++;
					}
				}else k++;
			}else j++;
		}
		if(flag==0){
			printf("%s is not a palindrome.\n",str1);
		}else{
			if(j==cur)
			printf("%s is a palindrome.\n",str1);
		}
	}
	return 0;
}




