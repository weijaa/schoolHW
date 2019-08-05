#include<stdio.h>

#define MAX 100

typedef struct polynomial{
	int coef;
	int expon;
}polynomial;

typedef struct mypoly{
	polynomial terms[MAX];
	int size;
	void showPoly();
	void add(mypoly);
	void singleMult(int);
	int leadExp();
	void attach(int,int);
	void del(int);
}mypoly;

int main(){
	FILE *POLY1,*POLY2; 
	mypoly poly1,poly2;
	int i;
	for(i=0;i<100;i++){
		poly1.terms[i].coef = 0;
		poly1.terms[i].expon = 0;
		poly2.terms[i].coef = 0;
		poly2.terms[i].expon = 0;
	}
	POLY1 = fopen("poly1.txt","r");
	POLY2 = fopen("poly2.txt","r");
	poly1.size = 0;
	poly2.size = 0;
	i=0;
	while(feof(POLY1) == 0){
		fscanf(POLY1,"%d %d",&poly1.terms[i].coef,&poly1.terms[i].expon);
		i++;
		poly1.size++;
	}
	i=0;
	//printf("%d\n",poly1.size);
	while(feof(POLY2) == 0){
		fscanf(POLY2,"%d %d",&poly2.terms[i].coef,&poly2.terms[i].expon);
		i++;
		poly2.size++;
	}
	//printf("%d\n",poly2.size);
	fclose(POLY1);
	fclose(POLY2);
	int num,x,a,b;
	while(1){
		printf("1.印出多項式\n");
		printf("2.多項式相加\n");
		printf("3.多項式乘上一數值\n");
		printf("4.印出多項式中最大指數的係數\n");
		printf("5.新增式子\n");
		printf("6.刪除多項式中的項式\n");
		scanf("%d",&num);
		fflush(stdin);
		switch(num){
			case 1:
				poly1.showPoly();
				break;
			case 2:
				poly1.add(poly2);
				break;
			case 3:
				scanf("%d",&x);
				fflush(stdin);
				poly1.singleMult(x);
				break;
			case 4:
				printf("%d\n",poly1.leadExp());
				break;
			case 5:
				scanf("%d %d",&a,&b);
				fflush(stdin);
				poly1.attach(a,b);
				break;
			case 6:
				scanf("%d",&x);
				fflush(stdin);
				poly1.del(x);
				break;
		}
		
		
		 
	}


	
	return 0;
}
void mypoly::showPoly(){
	int i;
	for(i=0;i<size-1;i++){
		printf("%dx^%d + ",terms[i].coef,terms[i].expon);
	}
	printf("%dx^%d\n",terms[i].coef,terms[i].expon);
}
void mypoly::add(mypoly poly2){
	int i,j,tmp;
	for(i=0;i<poly2.size;i++){
		for(j=0;j<MAX;j++){
			if(terms[j].coef==0 && terms[j].expon==0){
				terms[j].coef = poly2.terms[i].coef;
				terms[j].expon = poly2.terms[i].expon;
				break;
			}
			if(terms[j].expon == poly2.terms[i].expon){
				terms[j].coef += poly2.terms[i].coef;
				break;
			}
		}
	}
	size = 0;
	for(i=0;i<MAX;i++){
		if(terms[i].coef==0 && terms[i].expon==0){
			break;
		}
		size++;
	}
	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			if(terms[j].expon > terms[i].expon){
				tmp = terms[j].coef;
				terms[j].coef = terms[i].coef;
				terms[i].coef = tmp;
				tmp = terms[j].expon;
				terms[j].expon = terms[i].expon;
				terms[i].expon = tmp;
			}
		}
	}
//	for(i=0;i<size-1;i++){
//		printf("%dx^%d + ",terms[i].coef,terms[i].expon);
//	}
//	printf("%dx^%d\n",terms[i].coef,terms[i].expon);
}
void mypoly::singleMult(int x){
	int i;
	for(i=0;i<size;i++){
		terms[i].coef *= x;
	}
//	for(i=0;i<size-1;i++){
//		printf("%dx^%d + ",terms[i].coef,terms[i].expon);
//	}
//	printf("%dx^%d\n",terms[i].coef,terms[i].expon);
	
}
int mypoly::leadExp(){
	return terms[0].coef;
}
void mypoly::attach(int a,int b){
	int tmp,i,x,y;
	for(i=0;i<MAX;i++){
		if(terms[i].expon < b){
			
			tmp = terms[i].coef;
			terms[i].coef = a;
			a = tmp; 
			tmp = terms[i].expon;
			terms[i].expon = b;
			b = tmp;
		}
		else if(terms[i].expon == b){
			size++;
			terms[i].coef += a;
			break;
		}
		if(terms[i].expon == 0 && terms[i].coef == 0){
			size++;
			terms[i].expon = b;
			terms[i].coef = a;
			break;
		}
	}
//	for(i=0;i<size-1;i++){
//		printf("%dx^%d + ",terms[i].coef,terms[i].expon);
//	}
//	printf("%dx^%d\n",terms[i].coef,terms[i].expon);
}
void mypoly::del(int x){
	int i,j,tmp;
	for(i=0;i<size;i++){
		if(terms[i].expon == x){
			size--;
			terms[i].expon = 0;
			terms[i].coef = 0;
			break;
		}
	}
	for(i=0;i<size+1;i++){
		for(j=i;j<size+1;j++){
			if(terms[j].expon > terms[i].expon){
				tmp = terms[j].coef;
				terms[j].coef = terms[i].coef;
				terms[i].coef = tmp;
				tmp = terms[j].expon;
				terms[j].expon = terms[i].expon;
				terms[i].expon = tmp;
			}
		}
	}
	for(i=0;i<size+1;i++){
		for(j=i;j<size+1;j++){
			if(terms[j].expon >= terms[i].expon && terms[j].expon >= terms[i].expon){
				tmp = terms[j].coef;
				terms[j].coef = terms[i].coef;
				terms[i].coef = tmp;
				tmp = terms[j].expon;
				terms[j].expon = terms[i].expon;
				terms[i].expon = tmp;
			}
		}
	}
//	for(i=0;i<size-1;i++){
//		printf("%dx^%d + ",terms[i].coef,terms[i].expon);
//	}
//	printf("%dx^%d\n",terms[i].coef,terms[i].expon);
}
