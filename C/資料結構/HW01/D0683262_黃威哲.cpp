#include<stdio.h>
#include<stdlib.h>

#define max 100
 
typedef struct array{
	int size;
	int Arr[max];
	void bubbleSort();
	void selectionSort();
	int binarySearch(int put);
	void showArr();
}ar;

int main(){
	FILE *input;
	ar sort;
	char ans;
	int i,tmp;
	for(i=0;i<100;i++){
		sort.Arr[i] = 0;
	}
	sort.size=0;
	input = fopen("A1.txt","r");
	
	for(i=0;i<100;i++){
		fscanf(input,"%d",&sort.Arr[i]);
		if(sort.Arr[i] != 0){	
			sort.size++;
		//	printf("%d ",sort.Arr[i]);
		}
	}
	printf("size: %d\n",sort.size);
	sort.showArr();	
	sort.bubbleSort();
	sort.selectionSort();
	scanf("%d",&tmp);
	ans = sort.binarySearch(tmp);
	printf("BinarySearch¡G%c",ans);
	return 0;
}
void ar::showArr(){
	int i;
	printf("Original¡G");
	for(i=0;i<size;i++){
		printf("%d ",Arr[i]);
	}
	printf("\n");
}
void ar::bubbleSort(){
	int bubble[max] ={0};
	int i,j,tmp;
	printf("BubbleSort¡G"); 
	for(i=0;i<size;i++){
		bubble[i] = Arr[i];
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(bubble[i] < bubble[j]){
				tmp = bubble[i];
				bubble[i] = bubble[j];
				bubble[j] = tmp; 
			} 
		}
	}
	for(j=0;j<size;j++){
		printf("%d ",bubble[j]);
	}
	printf("\n");
}
void ar::selectionSort(){
	int i,j,tmp;
	printf("SelectionSort¡G");

	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			if(Arr[i] > Arr[j]){
				tmp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = tmp;
			}
		}
	}
	for(j=0;j<size;j++){
		printf("%d ", Arr[j]);
	}
	printf("\n");
}
int ar::binarySearch(int put){
	int middle,left,right;
	left = 0;
	right = size-1;
	while(left <= right){
		middle = left+right/2;
		if (Arr[middle] == put ){
			return 't';
		} 
		else if(Arr[middle] > put){
			right = middle-1;
		}
		else if(Arr[middle] < put){
			left = middle +1;
		}
	}
	return 'f';
}







