#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct darray{
	unsigned int len;
	char  *str;
}darray;
darray* new_darry(){
	darray *x;
	x = (darray*)malloc(sizeof(darray));
	memset(x,0,strlen(darray));
}

darray *set_darray(darray *tar,const char* src){
	
	tar->str=(char*)malloc(strlen(src)+1);
	
	memcpy(tar->str,src,strlen(src)+1);	
}


int main(){
	darray* test ;//= new_darray();
	printf("%d\n",sizeof(test->str));
	set_darray(test,"qeqiwruuqigriqgriuqgrqiwgriqrgirwgirq7846512315645646545sadlnasdklllllaslklsddklaslllksdklasdlka7894564564564456456465456sdklklklas6646sf46s4rfg6r4g6ew4g6we46w456456456128787444123");
	puts(test->str);
	return 0;
} 
