#include<stdio.h>
#include<stdlib.h> 

typedef struct list{
	int num;
	struct list *next;
	void push(struct list*);
	void pop(); 
	void peek(struct list*);
	int size;
}queue;

queue* newnode(){
	queue *x;
	x = (queue*)malloc(sizeof(queue));
	x->num = 0;
	x->next = NULL;
	x->size = 0;
}

int main(){
	int num;
	queue *head = NULL,*current = NULL;
	head = newnode();
	current = head;
	while(1){
		printf("Queue¡G1.push 2.pop 3.peek 4.size 5.exit\n");
		scanf("%d",&num);
		fflush(stdin);
		if(num == 1){
			head->push(current);
			current->next = newnode();
			current = current->next;
		}else if(num == 2){
			if(head->num != 0) {
				head->pop();
				head->next->size = head->size;
				head = head->next;
			}else{
				printf("empty\n");
			}
			
		}else if(num == 3){
			head->peek(head);
		}else if(num == 4){
			printf("size = %d\n",head->size);
		}else if(num == 5){
			break;
		}
	}
	return 0;
} 

void queue::push(queue *current){
	int i;
	printf("Enter num : ");
	scanf("%d",&i);
	fflush(stdin);
	current->num = i;
	size++;
}
void queue::pop(){
	printf("pop : %d\n",num);
	size--;
}
void queue::peek(queue *current){
	while(current != NULL){
		if(current->num != 0) printf("%d ",current->num);
		current = current->next;
	}
	printf("\n");
}
