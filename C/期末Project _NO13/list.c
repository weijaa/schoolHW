#include"list.h"

list* newlist(){
	list *y;
	y = (list*)malloc(sizeof(list));
	y->classNum = 0;
	memset(y->id,0,sizeof(y->id));
	y->mid=0;
	y->fin=0;
	y->next = NULL;
	return y;
}
person* node(){
 	person *x;
 	int i;
 	x = (person*)malloc(sizeof(person));
 	x->next = NULL;
 	memset(x->id,0,sizeof(x->id));
 	memset(x->password,0,sizeof(x->password));
 	memset(x->name,0,sizeof(x->name));
 	memset(x->dept,0,sizeof(x->dept));
 	memset(x->bir,0,sizeof(x->bir));
 	for(i=0;i<6;i++) x->course[i] = 0;
 	return x;
 }

