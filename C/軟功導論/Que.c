#include "Que.h"
#define MAX 60 

struct info{
	int k;
	char studi[10];
	char td[MAX][MAX];
	char sd[MAX][MAX];
	char id[MAX][MAX];
};
 
typedef struct data{
	struct info terms[MAX];
}DA;






void Que(char a[]){
	system("cls");
	FILE *inptr=NULL;
	inptr = fopen("data.txt","r");
	DA da;
	int i=0;
	int n=0;
	int s=0;
	while(fscanf(inptr,"%s",da.terms[i].studi)!=EOF){
		da.terms[i].k = 0;
		i++;
	
	}
	char ch[99];
	char ask[99];
	char que[MAX];



	void  printstudentdiscurss(int s){
	int i=0;
	for(i=0;i<=da.terms[s].k;i++){
	printf("��%d�� �d��",i+1); 
	printf("\n");	
	puts(da.terms[s].sd[i]);
	printf("\n");

		}
	}
	while(1){
		fflush(stdin);
		printf("�Q�бЪ��Ѯv(��Jexit�����}):");
		gets(ask);
		if(strcmp(ask,"exit")==0){
			break; 
		}
		else
		while(s<6){
			if(strcmp(ask,da.terms[s].studi)==0){	 
				printf("��J���e (��exit����^�D�e��) :"); 
				gets(que); 
				if(strcmp(que,"exit")==0){
					break;
				}
				else
				for(n=0;n<strlen(que);n++){
					da.terms[s].sd[da.terms[s].k][n]=que[n];
				}
				printstudentdiscurss(s);
				da.terms[s].k+=1;
			}
			else
				s++;
			if(s==5){
				printf("�L���Ѯv :\n"); 
				s=0;
				break;
			}
			
		} 
		
	}
	fclose(inptr);
} 
	

