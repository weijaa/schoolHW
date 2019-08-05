#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}Node;
Node*cube(int n){
	Node *x;
	x = (Node*)malloc(sizeof(Node));
	x->num = n;
	x->next = NULL;
	return x;
}
void insert(Node *now, Node *in){
	in->next = now->next;
	now->next = in;
}
void deletecube(Node *pre,Node *deletenode){
	pre->next = deletenode->next;
	free(deletenode);
}
int main(){
	Node *head,*current,*newNode;
	int i=0,a,b,c;
	
	head = cube(i);
	current = head;
	
	for(i=1;i<10;i++){
		current->next = cube(i);
		current = current->next;
	}
	current = head;
	while(current != NULL){
		printf("%d ",current->num);
		current = current->next;
		
	}
	printf("\n");
	while(1){
		
		printf("1.add 2. delete 3.exit:");
		scanf("%d",&c);
		if(c==1)
		{
			current = head;
			printf("add b after a\n");
			printf("a b:");
			scanf("%d %d",&a,&b);
			
			newNode = cube(b);
			while(current != NULL){
				if(current->num==a){
					break;
				}
				//printf("%d ",current->num);
				current = current->next;
			}
			insert(current,newNode);
		}
		else if(c==2){
			current = head;
			printf("delete a:");
			scanf("%d",&a);
			if(head->num==a){
				head = head->next;
			}	
			else{
				while(current != NULL){
					
					if(current->next->num ==a){
						break;
					}
					//printf("%d ",current->num);
					current = current->next;
				}
				newNode = current->next;
				deletecube(current,newNode);
			}
		}
		else{
			break;
		}
		current = head;
		while(current != NULL){
			printf("%d ",current->num);
			current = current->next;
		}
		printf("\n");
	}
	
	
	
	return 0;
}
