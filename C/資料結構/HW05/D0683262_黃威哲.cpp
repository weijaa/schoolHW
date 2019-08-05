#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *right;
	struct node *left;
}node;
node* newNode(int num){
	node *x;
	x =(node*)malloc(sizeof(node));
	x->left = NULL;
	x->right = NULL;
	x->num = num;
	return x;
}

typedef struct steak{
	struct node *tree;
	struct steak *pre;
	struct steak *next;
}steak;
steak* newSteak(node *t){
	steak *x;
	x =(steak*)malloc(sizeof(steak));
	x->pre = NULL;
	x->next = NULL;
	x->tree = t;
	return x;
}

int main(){
	FILE *in = fopen("input.txt","r"); 
	int n,i;
	node *head = NULL;
	node *current = NULL;

	fscanf(in,"%d",&i);
	printf("%d\n",i);
	while(i){						//tree
		fscanf(in,"%d",&n);
		printf("%d ",n);
		if(head == NULL){
			head = newNode(n);
		}else{
			current = head;
			while(1){
				if(n > current->num){
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
		i--;
	}
	printf("\n");
	steak *steakCur = newSteak(head);
	steak *steakPre = NULL;
	while(steakCur != NULL){
		if(steakCur->tree->left != NULL && steakPre != steakCur){
			
			steakCur->next = newSteak(steakCur->tree->left);
			steakCur->next->pre = steakCur;
			steakCur = steakCur->next;
		}else if(steakCur->tree->right != NULL ){
		
			printf("%d ",steakCur->tree->num );
			if(steakCur->pre == NULL) steakCur = newSteak(steakCur->tree->right);
			else {
				steakCur->pre->next = newSteak(steakCur->tree->right);
				steakCur->pre->next->pre = steakCur->pre;
				steakCur = steakCur->pre->next;
			}
			steakPre = steakCur->pre;
		}else{
		
			printf("%d ",steakCur->tree->num);
			steakCur = steakCur->pre;
			steakPre = steakCur;
		}
	}
	
	
	
	return 0;
} 
