#include<stdio.h>
#include<stdlib.h>




typedef struct tree{
	int n;
	struct tree *right;
	struct tree *left;
}tree;
 tree* newNode(int num){
 	tree *x;
 	x = (tree*)malloc(sizeof(tree));
 	x->left = NULL;
 	x->right = NULL;
 	x->n = num;
 	
 }
 void order(tree *z){
 	if(z){
 		printf("%d ",z->n);
		 order(z->left);
		 order(z->right); 
	 }
 }
 
 int main(){
 	tree *root=NULL;
 	tree *current=NULL;
 	int n,i;
 	while(1){
	 	printf("1.add\n");
	 	printf("2.search\n");
	 	scanf("%d",&n);
	 	if(n==3) break;
	 	if(n==1){
	 		printf("add:");
	 		scanf("%d",&n);
	 		if(root == NULL){
	 			root = newNode(n);
			 }else{
			 	current = root;
			 	while(1){
			 		if(n>current->n){
			 			if(current->right == NULL){
			 				current->right = newNode(n);
			 				break;
						 }else{
						 	current = current->right;
						 }
					 }else{
					 	if(current->left == NULL){
			 				current->left = newNode(n);
			 				break;
						 }else{
						 	current = current->left;
						 }
					 }
				 }
			 }
		 }
 	}
 	order(root);
 	
 	
 	return 0;
 }
