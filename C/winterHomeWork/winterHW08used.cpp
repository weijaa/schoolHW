#include<stdio.h>
#include<math.h>



int main(){
	double a,b;
	int i,ans=0,time=1,n;
	scanf("%d",&n);
	while(time <=n){
	
		scanf("%lf",&a);
		scanf("%lf",&b);
		for(i=a;i<=b;i++){
			
			if(sqrt(i)-int(sqrt(i))==0){
				ans=ans+i;
			}
		}
		printf("%d\n",ans);
		ans=0;
		time++;
	}
	return 0;
} 
