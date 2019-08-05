#include<stdio.h>

int main(){
	int x,n[10000],k=0,k1=0,k2=0,i;
	
	scanf("%d",&x);
	
		
		for(i=0;i<x;i++){
			scanf("%d",&n[i]);
		}	
		
		for(i=0;i<x;i++){
			if(n[i]%3==0){
				k++;
			}
			else if(n[i]%3==1){
				k1++;
			}
			else if(n[i]%3==2){
				k2++;
			}
		}
		
		

	
	printf("%d %d %d",k,k1,k2);
	
	
	return 0;
}
