#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int number;
	struct node *next;
}node;
typedef node *list;

node* createlist();
void newnode(list *dest, int num);	//新增一個指定的數字節點 
void delnode(list *dest, int num);	//刪除串列中所有指定的數字節點 
void append(list *dest, list *src);	//把一個src串列串到dest串列後面
void printlist(list print);

#endif
