#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void Show (int Tree[], int sizeadd) {
    int i = sizeadd, height = 0, j = 0, changeline = 0, n = 0;
    while (i != 0) {
        height++;
        i /= 2;
    }

    for (i=1;i<=sizeadd;i++) {
        for (j=0;j<pow(2,height)-1;j++) {
            printf(" ");
        }

        if (Tree[i] == 0) printf("  ");
        else printf("%2d", Tree[i]);
        
        for (j=0;j<pow(2,height)-1;j++) {
            printf(" ");
        }
        changeline++;
        if (changeline  == int(pow(2,n))) {
            printf("\n");
            height--;
            n++;
            changeline = 0;
        }
    }
    printf("\n\n");
}


void adjust(int a[],int root,int n) {
	int child, rootkey;
	int temp;
	rootkey = a[root];
	child = 2*root; // 左子樹
	while (child <= n) {
		if (child < n && a[child] < a[child+1]) {
			child++;
		}
		if (rootkey > a[child]) { // 比較樹根和最大子樹
			break;
		}
		else {
			a[child/2] = a[child]; // 移動成父節點
			child*=2;
		}
	}
	a[child/2] = rootkey;
}

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void minAdjust(int a[], int start, int end) {

	int dad = start;
	int son = dad * 2 ;
	while (son <= end) { 
		if (son + 1 <= end && a[son] > a[son + 1]) 
			son++;
		if (a[dad] < a[son]) 
			return;
		else { 
			swap(&a[dad], &a[son]);
			dad = son;
			son = dad * 2 +1;
		}
	}
}

void heapSort(int a[], int len) {
	int i;
	for (i = len / 2 - 1; i > 0; i--)
		minAdjust(a, i, len );
	for (i = len / 2 - 1; i > 0; i--)
		minAdjust(a, i, len );
	for (i = len ; i > 0; i--) {
		swap(&a[0], &a[i]);
		minAdjust(a, 1, i );
	}
}

int main(){
	
	int a[10] = {0,35,21,17,60,55,27,42,10,36};
	int i,j;
	Show(a,9);
	printf("\n");
	
	for(i=4;i>0;i--){
		adjust(a,i,2*i+1);
	}
	for(i=4;i>0;i--){
		adjust(a,i,2*i+1);
	}
	Show(a,9); 
	heapSort(a,10);
	Show(a,9);
	return 0;
} 
