#include<stdio.h>
#include<math.h>
void inorder(char[],int,int);
int main(){
	char word;
	char tree[100]={0};
	int i=0,N=0,j;
	scanf("%d",&N);
	fflush(stdin);
	while(N--){
		i=0;
		word = 0;
		scanf("%c",&word);
		fflush(stdin);
		while(1){
			if(tree[i] == 0){
				tree[i] = word;
				break;
			}
			else{
				if(word > tree[i]){
					i = (i+1)*2;
				}
				else if(word < tree[i]){
					i = (i+1)*2-1;
				}
			}
		}	
	}
	i=0;
	int k=0;
	while(i<6){
		for(j=0;j<(pow(2,i));j++){
			printf("%c",tree[k]);
			k++;
		}
		printf("\n");
		i++;
	}
	inorder(tree,0,63);
	return 0;
} 
void inorder(char root[70],int now,int end){
		if(now > end) return;
  			inorder(root, (now+1)*2-1, end); 

  			if(root[now] != 0) printf("%c ", root[now]); 

 			inorder(root, (now+1)*2, end);
}
