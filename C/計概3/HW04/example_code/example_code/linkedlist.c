#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node* next;
}NODE;

NODE* GenerateNode(int n){
	NODE *new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> num = n;
	new_node -> next = NULL;
	return new_node;
}

void InsertNode(NODE *target, NODE *newnode){
	newnode -> next = target -> next;
	target -> next = newnode;
}

void DeleteNode(NODE *node, NODE *deletenode){
	node -> next = deletenode -> next;
	free(deletenode);
}

void SearchNode(NODE *node, int num){
	NODE *current;
	current = node;
	
	while(current != NULL){
		if(current -> num == num){
			current -> num = 999;
			break;
		}
		current = current -> next;
	}
	
}

void PrintNode(NODE *node){
	/* 印出整個 Linked List */
	NODE *current;
	current = node;

	while(current != NULL){
		printf("%3d  ", current -> num);
		current = current -> next;
	}
	
	printf("\n");
}

int main(){
	int i = 0;
	
	NODE *head, *current, *insertnode;
	head = GenerateNode(0);
	current = head;
	
	for(i = 1; i < 10; i++){
		current -> next = GenerateNode(i);
		current = current -> next;
	}
	
	printf("原始\t : ");
	PrintNode(head);
	
	/* 插入一個節點至 Linked List */
	current = head;
	while(current != NULL){
		if(current -> num == 3){
			insertnode = GenerateNode(99);
			InsertNode(current, insertnode);
			break;
		}
		current = current -> next;
	}
	
	printf("新增節點 : ");
	PrintNode(head);
	
	/* 刪除 Linked List 一個節點 */
	current = head;
	while(current != NULL){
		if(current -> next -> num == 99){
			DeleteNode(current, current -> next);
			break;
		}
		current = current -> next;
	}
	
	printf("刪除節點 : ");
	PrintNode(head);
	
	/* 搜尋並更改 Linked List 一個節點 */
	SearchNode(head, 6);
	
	printf("搜尋節點 : ");
	PrintNode(head);
	
	return 0;
}



