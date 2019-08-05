#include<stdio.h>
#include<string.h>


int main(){
	int generator[20000]={0},num,i;
	
	for(i=1;i<=10000;i++){
		if(i<100){
			num=i+i/10+i%10;
		}
		else if(i<1000 && i>99){
			num=i+i/100+(i/10)%10+i%10;
		}
		else if(i<10000 && i>999){
			num=i+i/1000+(i/100)%10+(i/10)%10+i%10;
		}
		generator[num]=num;
		num=0;
	}
	
	
	
	for(i=1;i<=10000;i++){
		if(i != generator[i]){
			printf("%d\n",i);
		}
	}
	
	
	return 0;
} 
