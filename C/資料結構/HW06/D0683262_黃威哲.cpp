#include<stdio.h>
#include<stdlib.h>



int main(){
	FILE *in = fopen("1.txt","r");
	int num;
	while(feof(in) == 0){
		fscanf(in,"%d",&num);
		printf("%d\n",num); 
	}
	 
	
	return 0;
} 
