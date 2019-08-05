#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	
	FILE *in = fopen("1.txt","r");
	
	int tree[70]={0};
	int i,j,x,k,num;
	i=1;
	while(feof(in) == 0){
		fscanf(in,"%d",&tree[i]);
	//	printf("%d ",tree[i]); 
		i++;
	}
	x=0;
	k=1;
	while(x<6){
		for(j=0;j<(pow(2,x));j++){
			if(tree[k] != 0) printf("%d ",tree[k]);
			k++;
		}
		printf("\n");
		x++;
	}
	while(1){
		printf("1.push 2.pop \n");
		scanf("%d",&num);
		fflush(stdin);
		if(num == 1){
			scanf("%d",&tree[i]);
			fflush(stdin);
			x=i;
			i++;
			while(x>1){
				if(tree[x] > tree[x/2]){
					j = tree[x];
					tree[x] = tree[x/2];
					tree[x/2] = j; 
				}
				x = x/2;
			}
		}else if(num ==2){
			x=1;
			i--;
			tree[x] = tree[i];
			tree[i] = 0;
			while(tree[2*x] != 0 || tree[2*x+1] != 0  ){
				
				if(tree[2*x] > tree[x]){
					j = tree[2*x];
					tree[2*x] = tree[x];
					tree[x] = j;
					x = 2*x;
				}else if(tree[2*x+1] > tree[x]){
					j = tree[2*x+1];
					tree[2*x+1] = tree[x];
					tree[x] = j;
					x = 2*x+1;
				}else{
					break;
				}
			}
		}else{
			break;
		}
		x=0;
		k=1;
		printf("i=%d\n",i);
		while(x<6){
			for(j=0;j<(pow(2,x));j++){
				if(tree[k] != 0) printf("%d ",tree[k]);
				k++;
			}
			printf("\n");
			x++;
		}
	}
	
	
	
	
	return 0;
} 
