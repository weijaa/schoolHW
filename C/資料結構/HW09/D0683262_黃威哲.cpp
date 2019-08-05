#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertionSort(int data[],int n){
	int j,temp,i;
	clock_t begin = clock();
    for(i=1;i < n;i++) {  
    	temp = data[i];
    	j = i-1; 
    	while (j >= 0 && data[j] > temp) { 
    	   data[j+1] = data[j]; 
           j = j-1; 
    	} 
    	data[j+1] = temp; 
    } 
    clock_t end = clock();
    double time = (double)(end-begin) / CLOCKS_PER_SEC;
    FILE *output = fopen("insertionSorted.txt","w");
    j=0;
    fprintf(output,"%lf\n",time);
    for(i=0;i<n-1;i++){
    	if(data[i] > 0) {
			fprintf(output,"%d ",data[i]);
			j++;
		}
    	if(j%10 == 0) fprintf(output,"\n");
	}
	fclose(output);
}
int partition(int number[], int left, int right) { 
    int i = left - 1; 
    int j,temp;
    for(j = left; j < right; j++) { 
        if(number[j] <= number[right]) { 
            i++; 
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
        } 
    } 
	temp = number[i+1];
    number[i+1] = number[right];
    number[right] = temp;
    return i+1; 
} 
void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int q = partition(number, left, right); 
        quickSort(number, left, q-1); 
        quickSort(number, q+1, right); 
    } 
}
void quickSortWritten(int x[],double time,int n){
	FILE *output = fopen("quickSorted.txt","w");
    int j,i;
	j=0;
    fprintf(output,"%lf\n",time);
    for(i=0;i<n-1;i++){
    	if(x[i] > 0) {
			fprintf(output,"%d ",x[i]);
			j++;
		}
    	if(j%10 == 0) fprintf(output,"\n");
	}
	fclose(output);
}
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}
void mergeSortWritten(int x[],double time,int n){
	FILE *output = fopen("mergeSorted.txt","w");
    int j,i;
	j=0;
    fprintf(output,"%lf\n",time);
    for(i=0;i<n-1;i++){
    	if(x[i] > 0) {
			fprintf(output,"%d ",x[i]);
			j++;
		}
    	if(j%10 == 0) fprintf(output,"\n");
	}
	fclose(output);
}
int main(){
	int x[100000] = {0};
	int x1[100000] = {0};
	int x2[100000] = {0};
	FILE *data = fopen("testData.txt","r");
	int j,i = 0;
	while(feof(data) == 0){
		fscanf(data,"%d",&x[i]);
		i++;
	}
	for(j=0;j<i;j++){
    	x1[j] = x[j];
    	x2[j] = x[j];
	}
	fclose(data);
	insertionSort(x,i);
	clock_t begin = clock();
	quickSort(x1,0,i-1);
	clock_t end = clock();
	quickSortWritten(x1,(double)(end-begin) / CLOCKS_PER_SEC,i);
	begin = clock();
	mergeSort(x2, 0,i-1); 
	end = clock();
	mergeSortWritten(x2,(double)(end-begin) / CLOCKS_PER_SEC,i);
	return 0;
} 
