#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct queue{
	struct queue *pre;
	struct queue *next;
	int num;
}queue;

queue* node(int num){
	queue *a;
	a = (queue*)malloc(sizeof(queue));
	a->num = num;
	a->next = NULL;
	a->pre = NULL;
}



int main(){
	int i,x;
	queue *head= NULL,*current,*last;
	scanf("%d",&x);	
	for(i=1;i<=x;i++){
		if(head == NULL){
			head = node(i);
			current = head;
		}
		else{
			current->next = node(i);
			current->next->pre = current;
			current = current->next;
		}
	}
	current->next = head;
	head->pre = current;
	last = current;
	current = head;
	printf("Discarded cards: ");
	for(i=1;i<x;i++){
		printf("%d",current->num);
		if(i != x-1){
			printf(",");
		}
		last->next=current->next;
		last = last->next;
		current->next = current->next->next;
		current = current->next;
		
	}
	printf("\nRemaining card: ");
	printf("%d",current->num);
/*	while(current != NULL){
		printf("%d ",current->num);
		current = current->pre;
	}*/
	return 0;
}



 
