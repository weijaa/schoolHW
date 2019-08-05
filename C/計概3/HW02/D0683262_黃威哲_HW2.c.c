#include<stdio.h>
#define max 30
//typedef const int cint;
int main(){
	int arr[max]={1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
	int *ptr[max];
	int i,j,*tmp;
	
	for(i=0;i<max;i++){
	 ptr[i] = &arr[i];
	} 
	for(i=0;i<max;i++){ 
		for(j=i;j<max;j++){
			if( *ptr[i] > *ptr[j]){
				tmp =ptr[i];
				ptr[i] = ptr[j];
				ptr[j] =tmp;
			}
			
		}
	}
	for(i=0;i<max;i++){
		printf("%d ",*ptr[i]);
	}
	
	return 0;
} 
