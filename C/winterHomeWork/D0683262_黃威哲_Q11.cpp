#include<stdio.h>
#include<string.h>



int main(){
	char fib[5001][300];
	int n,i,j,len;
	
	memset(fib,0,sizeof(fib));
	
	fib[0][0]=0;
	fib[1][0]=1;

	for(i=2;i<5001;i++){
		for(j=0;j<300;j++){
			fib[i][j]+=fib[i-1][j] + fib[i-2][j];
			if(fib[i][j] >=10){
				fib[i][j]-=10;
				fib[i][j+1]++;
			}
		}
	}
	while(1){
	scanf("%d",&n);
	printf("The Fibonacci number for %d is ",n);
	for(j=290;j>=0;j--){
		if(fib[n][j]!=0){
			len=j;
			break;
		}
	}
	for(len;len>=0;len--){
		printf("%d",fib[n][len]);
	}
	printf("\n");
	
	}
	return 0;
} 
