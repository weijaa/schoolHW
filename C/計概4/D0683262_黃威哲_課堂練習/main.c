#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
	int i;
	list handle = createlist();
	list handl2 = createlist();
	for(i = 0; i < 10; i++){
		newnode(&handle, i);
		newnode(&handl2, i+10);
	}
	printlist(handle);
	putchar('\n');
	printlist(handl2);
	putchar('\n');
	append(&handle, &handl2);
	delnode(&handle, 0);
	printlist(handle);
	putchar('\n');
	return 0;
}
