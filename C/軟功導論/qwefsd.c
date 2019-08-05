#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 60 

struct info{
	char studi[10];
	char td[MAX][MAX];
	char sd[MAX][MAX];
	char id[MAX][MAX];
};
 
typedef struct data{
	struct info terms[MAX];
}DA;

int k=0;
int j=0;




 
int main(){
	
	FILE *inptr=NULL;
	inptr = fopen("data.txt","r");
	DA da;
	int i=0;
	int n=0;
	while(fscanf(inptr,"%s",da.terms[i].studi)!=EOF){
		i++;
	
	}
	char ch[99];
	char stu[99];
	char ask[99];
	char que[MAX];void  studiscuess(char que[],char ch[]){
	
	int n=0;
	for(n=0;n<strlen(que);n++){
	da.terms[1].td[j][n] = que[n];
	}
	for(n=0;n<strlen(ch);n++){
	da.terms[1].id[j][n]=ch[n];
	}
	j++;
}

void  teadiscuess(char que[],char ch[]){
	
	int n=0;
	for(n=0;n<strlen(que);n++){
	da.terms[0].sd[k][n] = que[n];
	}
	for(n=0;n<strlen(ch);n++){
	da.terms[0].id[k][n]=ch[n];
	}	
	k++;
}
	
void  printstudentdiscurss(){
	int i=0;
	for(i=0;i<k;i++){
	printf("\n");	
	puts(da.terms[0].id[i]);
	printf("\n");
	printf("\n    ");
	puts(da.terms[0].sd[i]);
		}
	
}
void  printteacherdiscurss(){
	int i=0;
	for(i=0;i<j;i++){
	printf("\n");
	puts(da.terms[1].id[i]);
	printf("\n");
	printf("\n   ");
	puts(da.terms[1].td[i]);
		}
	
}
	while(1){
		printf("學生OR老師帳號 :");
		gets(ch);
		printf("想請教的老師or要回應的學生 :"); 
		gets(ask);
		if(strcmp(ch,da.terms[0].studi)==0&&strcmp(ask,da.terms[1].studi)==0){
		printstudentdiscurss();
		}
		if(strcmp(ch,da.terms[1].studi)==0&&strcmp(ask,da.terms[0].studi)==0){
		printteacherdiscurss();	
		}
		while(1){ 
			if(strcmp(ch,da.terms[0].studi)==0&&strcmp(ask,da.terms[1].studi)==0){	
				printf("輸入內容 (打exit為返回主畫面) :"); 
				gets(que); 
				if(strcmp(que,"exit")==0){
				break;
			}
			else
			{
				for(n=0;n<strlen(que);n++){
				da.terms[0].sd[k][n]=que[n];
				}
				for(n=0;n<strlen(ch);n++){
				da.terms[0].id[k][n]=ch[n];
				}	
				studiscuess(que,ch);
				k++;
				printstudentdiscurss();
			}
			} 
			if(strcmp(ch,da.terms[1].studi)==0&&strcmp(ask,da.terms[0].studi)==0){
				printf("輸入內容 (打exit為返回主畫面) :"); 
				gets(que);
				if(strcmp(que,"exit")==0){
				break;
			}	
			else
			{
				for(n=0;n<strlen(que);n++){
				da.terms[1].td[j][n] = que[n];
				}
				for(n=0;n<strlen(ch);n++){
				da.terms[1].id[j][n]=ch[n];
				}
				teadiscuess(que,ch);
				j++;
				printteacherdiscurss();
				
			}
			} 
		}
	} 
	fclose(inptr);
}

