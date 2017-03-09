#include<stdio.h>
int array[21][21][21];
int main(){
	int a,b,c;
	
	int w(int a ,int b ,int c);
	scanf("%d%d%d",&a,&b,&c);
	while(a!=-1||b!=-1||c!=-1){
		   printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
		   scanf("%d%d%d",&a,&b,&c);
	}
	return 0;
}



int w(int a ,int b,int c){
	
	if(a>0&&b>0&&c>0){
		if(a>20||b>20||c>20){
			return w(20,20,20);
		}
		else if(array[a][b][c]){
			return array[a][b][c];
		}
		else if(a<b&&b<c){
			return array[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		}
		else return array[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
    else return 1;
}

			

