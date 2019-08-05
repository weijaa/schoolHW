#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* �ŧi���c */
typedef struct node{
	int num;
	struct node *next;
}NODE;

/* �s�W�@�`�I */
NODE* GenerateNode(int num){
	NODE *new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> num = num;
	new_node -> next = NULL;
	return new_node;
}


int main(){
	FILE *outptr = NULL; 
	NODE *head = NULL, *current, *temp_node;
	int i = 0, num = 0, temp = 0, randnum = 0;
	char ch, op;
	
	srand(time(NULL));

	/* �üƲ��ͼƦr */
	for(i = 0; i < 10; i++){
		randnum = rand() % 100;
		
		/* �s�W�`�I */
		if(head == NULL){
			head = GenerateNode(randnum);
			current = head;
		}
		else{
			current -> next = GenerateNode(randnum);
			current = current -> next;			
		}
	}
	
	
	current = head;
	while(1){
		printf("%d ", current -> num);
		current = current -> next;
		if(current == NULL) break;
	}
	
	/* close file pointer*/
	fclose(outptr);
 
	return 0;
}



