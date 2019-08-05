#include<stdio.h>

 

int main(){
	
	int n,ans=1,len,time=1,i,j;
	
	scanf("%d%d",&i,&j);

	if(i>j){
		for(j;j<i;j++)
		{
			n=j;
			while(n !=1)
			{
				if(n%2==1){
					n=3*n+1;
				}
				else if(n%2==0){
					n=n/2;
				}
			//	printf("%d  ",n);
				time++;
			}
			if(time> ans){
				ans = time;
			}
			time =1;
		}
	}
		if(i<j){
		for(i;i<j;i++)
		{
			n=i;
			while(n !=1)
			{
				if(n%2==1){
					n=3*n+1;
				}
				else if(n%2==0){
					n=n/2;
				}
			//	printf("%d  ",n);
				time++;
			}
			if(time> ans){
				ans = time;
			}
			time = 1;
		}
	}
	printf("\n%d",ans);
	
	return 0;
}


 
