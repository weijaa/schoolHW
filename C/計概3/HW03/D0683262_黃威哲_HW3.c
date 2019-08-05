#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bigint{
	int len;
//	unsigned int space_size;
	char* val;
}bint;

typedef unsigned char uchar;

bint* newbint(){
	bint* x;
	x =(bint*)malloc(sizeof(bint));
	memset(x,0,sizeof(x));
	return x;
}

void reverse(bint* tar){
	int i,j,len;
	char *bnum;
	bnum = (char*)malloc(sizeof(bnum)*tar->len+1);
	strcpy(bnum,tar->val);
	len = tar->len;
	for(i=0,j=len-1;i<len,j>=0;i++,j--){
		tar->val[i] = bnum[j];
	}
}

void set(bint* tar){
	int i=0;
	char *num;
	num = (char*)malloc(sizeof(num)*10000);
	gets(num);
	while(*(num+i) != '\0'){
		tar->len+=1;
		i++;
	}
	tar->val = (char*)malloc(sizeof(tar->val)*tar->len+1);
	strcpy(tar->val,num);
}

bint* add(bint* a, bint* b){
	int i,j,lena,lenb;
	bint *x = newbint();
	x->val = (char*)malloc(sizeof(x->val)*10000);
	memset(x->val,0,sizeof(x->val));
	lena = a->len;
	lenb = b->len;
	
	if(lena > lenb){
		strcpy(x->val,a->val);
		for(i=0;i<lenb;i++){
			x->val[i] = x->val[i]+b->val[i]-'0';
		}
	//	printf("%d %s\n",strlen(x->val),x->val);
		for(i=0;i<strlen(x->val);i++){
			if(x->val[i] > '9'){
				if(x->val[i+1] == 0){
				x->val[i+1]+=48;
				}
				x->val[i+1]+=1;
				x->val[i]-=10;
				
			}
		}
	}
	else{
		strcpy(x->val,b->val);
		for(i=0;i<lena;i++){
			x->val[i] = x->val[i] + a->val[i]-'0';
		}
	//	printf("x=%d\n",strlen(x->val));
		j = strlen(x->val);
		for(i=0;i<j;i++){
		//	printf("%d\n",i);
			if(x->val[i] > '9'){
				if(x->val[i+1] == 0){
				x->val[i+1]+=48;
				}	
				x->val[i+1]+=1;
				x->val[i]-=10;
			}	
		}
	}
	i=0;
	x->len = strlen(x->val);
	//printf("x=%d\n",strlen(x->val));
//	printf("%d\n",strlen(x->val));
	return x;
}



int main(){
	int i;
	bint* a = newbint(), *b = newbint();
	bint* c = NULL;
	while(1){
		set(a);
		
		if( a->len == 1 && a->val[0] == '0') break;
		set(b);
		if(c){
			free(c->val);
			free(c);
		}
		reverse(a);
		reverse(b);
		
		c = add(a, b);

		reverse(c);
	
		for(i=0;i<strlen(c->val);i++){
			if(c->val[i] <= '9' && c->val[i] >= '0'){
				printf("%c",c->val[i]);
			}
		}
		printf("\n");
		//puts(c->val);
		a->len=0;
		b->len=0;
		a->val=NULL;
		b->val=NULL;
	//	printf("%d\n",c->len);
	
	}
	return 0;
}
