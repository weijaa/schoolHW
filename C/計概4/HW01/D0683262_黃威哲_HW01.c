#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int num;
	struct node *pre;
	struct node *next;
}node;
node* generateNode(int num){
	node *newNode;
	newNode =(node*)malloc(sizeof(node));
	newNode->num = num;
	newNode->next = NULL;
	newNode->pre = NULL;
}

int main(){
	node *head,*current,*stack;
	int num[5],i,j,popnum=0;
	printf("please enter five number :");
	for(i=0;i<5;i++){
		scanf("%d",&num[i]);
	} 
	for(i=0;i<5;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
	head = generateNode(num[0]);//第一個 
	printf("push：%d\n",head->num);
	current = head;
	stack = head;
	printf("stack：｜");
	while(stack != NULL){
		printf(" %d ",stack->num);
		stack = stack->next;
	}
	printf("｜\n");
/*	current->next = generateNode(num[1]);//第二個 
	current->next->pre = current;
	current = current->next;
	printf("push：%d\n",current->num);
	stack = head;
	printf("stack：｜");
	while(stack != NULL){
		printf(" %d ",stack->num);
		stack = stack->next;
	}
	printf("｜\n");*/ 
	for(i=1;i<5;i++){
		for(j=i;j>=0;j--){
			if(current->num > num[i]){
				current->next = generateNode(num[i]);//第二個 
				current->next->pre = current;
				current = current->next;
				printf("push：%d\n",current->num);			
				stack = head;
				printf("stack：｜");
				while(stack != NULL){
					printf(" %d ",stack->num);
					stack = stack->next;
				}
				printf("｜\n");	
				break;
			}
			else{
				printf("pop：%d\n",current->num);
				
				popnum = current->num;
				if(current->pre == NULL){	
					break;
				}
				current = current->pre;
				current->next =NULL;
				stack = head;
				printf("stack：｜");
				while(stack != NULL){
					printf(" %d ",stack->num);
					stack = stack->next;
				}	
				printf("｜\n");
			}	
		}
		if(current->num < popnum){
					break;
				}
		if(current->pre == NULL){
			printf("stack：｜empty｜\n");
			break;
		}
	}
	if(i==5){
		while(1){
			printf("pop：%d\n",current->num);
			current = current->pre;
			if (current == NULL){
				printf("stack：｜ empty ｜\n");
				break;
			}
			free(current->next);
			current->next = NULL;
	
			printf("stack：｜");
			stack = head;
			while(stack != NULL){
				printf(" %d ",stack->num);
				stack = stack->next;
			}
			printf("｜\n");
		}
		printf("SUCCEED\n");
	}
	else{
		printf("FAILED\n");
	}
	return 0;
}
