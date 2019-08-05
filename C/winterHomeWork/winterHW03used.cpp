#include<stdio.h>



int main(){
	int jacks[15],time=1,n,i,j,ans1=0,ans2=0;
	
	scanf("%d",&n);
	printf("Lumberjacks:\n");
	while(time <= n){
		
		for(i=0;i<10;i++){
			scanf("%d",&jacks[i]);
		}
		
		for(i=1;i<10;i++){
			for(j=i;j<10;j++){
				if(jacks[i]<jacks[j]){
					ans1++;
				}
			}
		}
	//	printf("%d\n",ans1);
		if(ans1==0){
			printf("Ordered\n");
		}
		
		for(i=1;i<10;i++){
			for(j=i;j<10;j++){
				if(jacks[i]>jacks[j]){
					ans2++;
				}
			}
		}
	//	printf("%d\n",ans2);
		if(ans2==0){
			printf("Ordered\n");
		}
		if(ans1  != 0 && ans2 != 0){
			printf("Unordered\n");
		}
		ans1=0;
		ans2=0;
		time++;	
	}
	
	
	return 0;
} 
