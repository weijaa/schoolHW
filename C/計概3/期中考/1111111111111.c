#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int num;
	char name[20];
	struct node *next;
}node;

node* newNode(int num,char name[20]){
	node *newn;
	newn = (node*)malloc(sizeof(node));
	
	strcpy(newn->name,name);
	newn->num = num;
	return newn;
}




int main(){
	FILE *inptr, *outptr;
	inptr = fopen("input.txt","r");
	while(eofx ==0){
		
		
	}
	
	return 0;
} 
