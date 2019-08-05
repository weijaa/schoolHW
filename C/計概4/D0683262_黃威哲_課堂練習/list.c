#include"list.h" 

node* createlist(){
	list x;
	x = (node*)malloc(sizeof(node));
	x->next = NULL;
	x->number = -1;
	return x;
};
void newnode(list *dest, int num){
	list NODE = createlist();
	NODE->number = num;
	list head = createlist();
	list current = createlist();
	head = *dest;
	if(head->number == -1){
		head->number = num;
	}
	else{
		current = head;
		while(1){
			if(current->next == NULL){
				current->next = NODE;
				break;
			}
			else{
				current = current->next;
			}
		}
	}
}
void delnode(list *dest, int num){
	list head = createlist();
	list current = createlist();
	//list temp = createlist();
	head = *dest;
	if(head->number == num){
		head = head->next;
		*dest = head;
	}
	current = head;
	while(current->next!= NULL){
		if(current->next->number == num){
			current->next = current->next->next;
		}
		current = current->next;
	}
}
void append(list *dest, list *src){
	list other = createlist();
	list current = createlist();
	current = *dest;
	other = *src;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = *src;
}
void printlist(list print){
	while(print != NULL){
		printf("%d ",print->number);
		print= print->next;
	}
}


