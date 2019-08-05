#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bint{
	int len;
	char *num;
}nint;

nint* new_nint(){
	nint *x;
	x = (nint*)malloc(sizeof(nint));
	x->len =0;
	x->num = NULL;
	return x; 
}

nint* set_nint(nint* tmp,const char* src){
	int i =0;
	while(*(src+i) != '\0'){
		i++;
		tmp->len+=1; 
	}
	tmp->num = (char*)malloc(sizeof(tmp->num)*tmp->len+1);
	
	strcpy(tmp->num,src);
	printf("%d\n",strlen(tmp->num)); 
	return tmp;
}

int main(){
	nint *a = new_nint();
	char *b;
	b = (char*)malloc(sizeof(b)*10000);
	gets(b);
//	b = (char*)malloc(sizeof(b)*strlen(b)+1);
	set_nint(a,b);
	puts(a->num);
	printf("%d",a->len);
	return 0;
} 
