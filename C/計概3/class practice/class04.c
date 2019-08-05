#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list{
	int num;
	struct list *next;
}List;

List* generateList(int i){
	List *node;
	node =(List*)malloc(sizeof(node));
	node->num = i;
	node->next = NULL;
	return node;
}

void add(List *target,List *newData){
	newData->next = target->next;
	target->next = newData;
}
void deleteData(List *delData, List *node){
	node->next = delData->next;
	free(delData);
}

int main(){
	int i=0,a,b,c;
	List *Data;
	List *current;
	List *head;
	head = generateList(i);
	current = head;
	for(i=1;i<10;i++){
		current->next = generateList(i);
		current = current->next;
	}
	printf("data:\n");
	current =head;
	while(current!= NULL){
		printf("%d ",current->num);
		current = current->next;
	}
	printf("\n");
	while(1){
		printf("1.add data 2.deelete data 3.exit:");
		scanf("%d",&a);
		current =head;
		if(a==1){
			printf("add c after b:");
			scanf("%d %d",&c,&b);
			
			while(current!= NULL){
				if(current->num == b){
					break;
				}
				current = current->next;
			}
			Data = generateList(c);
			add(current,Data);
		}
		else if(a==2){
			printf("delete b:");
			scanf("%d",&b);
			while(current!= NULL){
				if(current->next->num == b){
					break;
				}
				current= current->next;
			}
			
			Data = current->next;
			deleteData(Data,current);
		}
		else{
			break;	
		}
	
		current =head;
		while(current!= NULL){
				printf("%d ",current->num);
				current = current->next;
				}
		printf("\n");
	}
	return 0;
} 
