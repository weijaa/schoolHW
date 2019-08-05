#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include"TEACHER.h"
#include"STUDENT.h"
#include"list.h"

//typedef struct person{
//	char id[20];
//	char password[20];
//	char name[25];
//	char dept[20];
//	char bir[20];
//	int course[6];
//	struct person *next;
//}person;

//typedef struct list{
//	int classNum;
//	char id[20];
//	int mid;
//	int fin;
//	struct list *next;
//}list;

//list* newlist(){
//	list *y;
//	y = (list*)malloc(sizeof(list));
//	y->classNum = 0;
//	memset(y->id,0,sizeof(y->id));
//	y->mid=0;
//	y->fin=0;
//	y->next = NULL;
//	return y;
//}
 
//person* node(){
// 	person *x;
// 	int i;
// 	x = (person*)malloc(sizeof(person));
// 	x->next = NULL;
// 	memset(x->id,0,sizeof(x->id));
// 	memset(x->password,0,sizeof(x->password));
// 	memset(x->name,0,sizeof(x->name));
// 	memset(x->dept,0,sizeof(x->dept));
// 	memset(x->bir,0,sizeof(x->bir));
// 	for(i=0;i<6;i++) x->course[i] = 0;
// 	return x;
// }
 


int main(int argc, char *argv[]) {
	
	FILE *inptrId,*inptrCourse,*inptrPassword,*inptrList;
	char enter[30];
	person *head = NULL,*current;
	list *hlist = NULL,*clist;
	char temp[20];
	int i,clas;
	
	inptrList = fopen("course_list.txt","r");//成績單 
	while(feof(inptrList) == 0){
		if(hlist == NULL){
			hlist = newlist();
			fscanf(inptrList,"%d %s %d %d",&hlist->classNum,hlist->id,&hlist->mid,&hlist->fin);
			clist =hlist;
		} else{
			clist->next = newlist();
			clist = clist->next;
			fscanf(inptrList,"%d %s %d %d",&clist->classNum,clist->id,&clist->mid,&clist->fin);
		}	
	}
//	while(hlist != NULL){
//		printf("%d %s %d %d\n",hlist->classNum,hlist->id,hlist->mid,hlist->fin);
//		hlist = hlist->next;
//	} 
	
	inptrId = fopen("info_person.txt","r");//基本資料 
	while(feof(inptrId) == 0) {
		if(head==NULL){
			head= node();
			fscanf(inptrId,"%s %s %s %s",head->id,head->name,head->dept,head->bir);
			current=head;
		} else {
			current->next=node();
			current = current->next;
			fscanf(inptrId,"%s %s %s %s",current->id,current->name,current->dept,current->bir);
		}
	}
	
	current->next = node();//管理員 
	current = current->next;
	
	inptrPassword = fopen("password_book.txt","r");//密碼 
	current = head;
	while(feof(inptrPassword) == 0){
		
		fscanf(inptrPassword,"%s %s",current->id,current->password);
		if(current->next != NULL) current =current->next;
	}
	inptrCourse = fopen("info_course.txt","r");
	current = head;
	while(feof(inptrCourse) == 0 ){     //課程 
		memset(temp,0,sizeof(temp));
		fscanf(inptrCourse,"%s",temp);
		current=head;
		while(current != NULL){
			if(strcmp(current->id,temp)== 0) break;
			current = current->next;
		}
		for(i=0;i<6;i++){
			fscanf(inptrCourse,"%d",&clas);
			if(clas == 9999) {
				i=0;
				break;
			}else current->course[i] = clas;
		}
		
	}
	current = head;
//	while(current != NULL){
//		printf("%s	%s	%s	%s	%s\n",current->id,current->password,current->name,current->dept,current->bir);
//		for(i=0;i<6;i++){
//			if(current->course[i] != 0) printf("%d ",current->course[i]);
//		}
//		printf("\n");
//		current = current->next;
//	}
//	fclose(inptrList); 
	fclose(inptrId);
	fclose(inptrCourse);
	fclose(inptrPassword);
	printf("=================================================\n"); //上面都在讀資料 
	printf("| NN      N     OOOOO         111      33333333 |\n");
	printf("| N N     N    OO   OO       1111            33 |\n"); 
	printf("| N  N    N   OO     OO        11            33 |\n");
	printf("| N   N   N  OO       OO       11      33333333 |\n");
	printf("| N    N  N   OO     OO        11            33 |\n");
	printf("| N     N N    OO   OO         11            33 |\n");
	printf("| N      NN     OOOOO    0  11111111   33333333 |\n");
	printf("=================================================\n");
	printf("use \"help\" or \"/?\" to get more commands  \n"); 
	
	while(1){	
	
		scanf("%s",enter);
		if(strcmp(enter,"help") == 0 || strcmp(enter,"/?") == 0 ){
			printf("login			登入\n");
			printf("end			結束\n"); 
		}else if(strcmp(enter,"login") == 0){
			printf("Please Enter Your Id:\n");
			memset(temp,0,sizeof(temp));
			scanf("%s",temp);
			current=head;
			while(current != NULL){
				if(strcmp(current->id,temp) == 0) break;
				current = current->next;
			}
			if(current == NULL) printf("Id %s Not Found\n",temp);
			else{
				while(1){
					printf("Enter Your Password\n");
					memset(temp,0,sizeof(temp));
					scanf("%s",temp);
					if(strcmp(current->password,temp) == 0){
						if(current->id[0]=='D'){
							system("cls");
							student(current,hlist);
							break;
						}
						else if(current->id[0]=='T'){
							
							teacher(current,hlist);
							break;
						}else{
							manager(head,hlist);
							break;
						}
							
					}
				} 
			}
		}else if(strcmp(enter,"end") == 0){
			break;
		}else{
			printf("Invalid Command\n");
		}
		
	}
	//--------------寫檔----------- 
	FILE *outptrId,*outptrCourse,*outptrPassword,*outptrList;
	outptrId = fopen("info_person.txt","w");
	outptrCourse = fopen("info_course.txt","w");
	outptrPassword = fopen("password_book.txt","w");
	outptrList = fopen("course_list.txt","w");
	
	current=head; // 課程寫入 
	while(current != NULL){
		if(strcmp(current->id,"Admin")==0) break;
		fprintf(outptrCourse,"%s	",current->id);
		for(i=0;i<6;i++){
			if(current->course[i] == 0)break;
			fprintf(outptrCourse,"%d	",current->course[i]);
		}
		fprintf(outptrCourse,"9999\n");
		current = current->next;
	} 
	current=head; // 基本資料寫入 
	while(current != NULL){
		if(strcmp(current->id,"Admin")==0) break;
		fprintf(outptrId,"%s	%s	%s		%s\n",current->id,current->name,current->dept,current->bir);
		current = current->next;
	} 
	current=head; // 密碼本 
	while(current != NULL){
		fprintf(outptrPassword,"%s	%s\n",current->id,current->password);
		current = current->next;
	} 
	clist = hlist;//成績 
	while(clist != NULL){
		fprintf(outptrList,"%d	%s	%d	%d\n",clist->classNum,clist->id,clist->mid,clist->fin);
		clist = clist->next;
	}
	fclose(outptrCourse);
	fclose(outptrPassword);
	fclose(outptrId);
	fclose(outptrList);
	return 0;
}
