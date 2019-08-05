#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


typedef struct ListNode {
	struct ListNode* llink;
	int data;
	struct ListNode* rlink;
}ListNode;

typedef struct{
	ListNode* first = NULL;
	ListNode* last = NULL;
	void queue(int data);
	void insertLeft(int data, int position);
	void remove(int position);
	int search(int data);
	void print();
}DoublyLinkedList;

ListNode* newNode(int n){
	ListNode *x;
	x = (ListNode*)malloc(sizeof(ListNode));
	x->data = n;
	x->llink = NULL;
	x->rlink = NULL;
	
	return x;
}

int main(){
	DoublyLinkedList link;
	ListNode *ff = newNode(20);
	link.first = newNode(10);
	link.last = newNode(30);
	link.first->rlink = ff;
	link.first->llink = link.first->rlink;
	ff->llink = link.first;
	ff->rlink = link.last;
	FILE *input;
	char function[5];
	int data,num;
	input = fopen("test.txt","r");
	while(feof(input) == 0){
		memset(function,0,10);
		fscanf(input,"%s",function);
		if(strcmp(function,"q") == 0){
			fscanf(input,"%d",&data);
			link.queue(data);
		}else if(strcmp(function,"i") == 0){
			fscanf(input,"%d",&data);
			fscanf(input,"%d",&num);
			link.insertLeft(data,num);
		}else if(strcmp(function,"r") == 0){
			fscanf(input,"%d",&num);
			link.remove(num);
		}else if(strcmp(function,"s") == 0){
			fscanf(input,"%d",&num);
			printf("%d\n",link.search(num));
		}else if(strcmp(function,"p") == 0){
			link.print();
		}
		
	} 
	return 0;
} 

void DoublyLinkedList::queue(int data){
	ListNode *q = newNode(data);
	q->llink = last;
	last->rlink = q;
	last = q;
	print();
}
void DoublyLinkedList::insertLeft(int data, int position){
	ListNode *current,*tmp;
	current = first;
	int i;
	tmp = newNode(data);
	for(i=1;i<position;i++){
		current = current->rlink;
	}
	if(current == first){
		tmp->rlink = first;
		first->llink = tmp;
		first = tmp;
	}else if(current == last){
		last->rlink = tmp;
		tmp->llink = last;
		last = tmp;
	}else{
		tmp->llink = current;
		tmp->rlink = current->rlink;
		current->rlink = tmp;
	}
	
	print();
}
void DoublyLinkedList::remove(int position){
	ListNode *current;
	current = first;
	int i;
	for(i=0;i<position;i++){
		current = current->rlink;
	}
	if(current == first) first = first->rlink;
	else if(current == last) last = last->llink;
	else{
		current->llink->rlink = current->rlink;
		current->rlink->llink = current->llink;
	}
	print();
}
int DoublyLinkedList::search(int data){
	ListNode *current;
	current = first;
	int i = 0;
	while(current->rlink != NULL){
		if(current->data == data){
			break;
		}
		current = current->rlink;
		i++;
	}
	return i;
}
void DoublyLinkedList::print(){
	ListNode *current;
	current = first;
	printf("| %d |",current->data);
	current = current->rlink;
	while(current != NULL){
		printf(" -> | %d |",current->data);
		current = current->rlink;
	}
	printf("\n");
}
