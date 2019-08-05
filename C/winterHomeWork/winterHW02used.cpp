#include<stdio.h>

int fofx(int n){
	if(n==1){
		return 1;
	}
	else{
		return fofx(n-1)+n-1;
	}
}



int main(){
	int x,time=1,n;
	scanf("%d",&n);
	
	while(time<=n){
	
		scanf("%d",&x);

		printf("%d\n",fofx(x));
		time++;
	}
	
	return 0;
}
 
 
 
 
 
