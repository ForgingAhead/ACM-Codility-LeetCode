#include<stdio.h>
int main(){
	char ch1,ch2,ch3='C',ch,c;
	char cc[80];

	while(ch3!='D'){
		while((ch1=getchar())&&ch1=='\n');
		ch2=getchar();
		ch3=getchar();
		if(ch1=='E'){
			if(ch3=='C'){//ENCODE
				ch=ch3;
				while(ch!=' ')ch=getchar();
				scanf("%s",cc);
                for(int i=0;c=cc[i];i++){
					if(c=='X'||c=='Y'||c=='Z'){
						cc[i]=c-'X'+'A';
					}else 
						if(c=='x'||c=='y'||c=='z'){
							cc[i]=c-'x'+'a';
						}
						else{
							cc[i]=c+3;
						}
						printf("%c",cc[i]);
				}
				printf("\n");
			}
			else 
				if(ch2=='D')break;
		}
		else 
			if(ch1=='D'){
				ch=ch3;                          //DECODE
				while(ch!=' ')ch=getchar();
				scanf("%s",cc);
                for(int j=0;c=cc[j];j++){
					if(c=='A'||c=='B'||c=='C')
						cc[j]=c-'A'+'X';
					else if(c=='a'||c=='b'||c=='c')
						cc[j]=c-'a'+'x';
					else cc[j]=c-3;
				}
				printf("%s\n",cc);
			}
		//	getchar();
	}
	return 0;
}



