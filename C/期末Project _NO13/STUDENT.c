#include "STUDENT.h"

//typedef struct person{
//	char id[20];
//	char password[20];
//	char name[25];
//	char dept[20];
//	char bir[20];
//	int course[6];
//	struct person *next;
//}person; 


void student(person *data,list *grade){ 
	char enter[20];
	int i;
	list *clist;
	printf("=======   Hello %s   =======\n",data->id);
	memset(enter,0,sizeof(enter));
	fflush(stdin);
	while(1){
		memset(enter,0,sizeof(enter));
		gets(enter);
		fflush(stdin);
		if(strcmp(enter,"help") == 0 || strcmp(enter,"/?") == 0 ){
			printf("logout			登出\n");
			printf("show info		顯示基本資料\n");
			printf("show course		顯示基本修課清單\n");
			printf("show score		顯示成績\n"); 
			printf("end			結束\n");
			printf("\n");
		}else if(strcmp(enter,"show info")==0){
			printf("\nINFORMATION\n");
			printf("ID	:%s\n",data->id);
			printf("NAME	:%s\n",data->name);
			printf("DEPT	:%s\n",data->dept);
			printf("B-DAY	:%s\n",data->bir);
			printf("\n");
		}else if(strcmp(enter,"show course")==0){
			printf("\nCOURSES\n");
			printf("ID		:%s\n",data->id);
			for(i=0;i<6;i++){
				if(data->course[i] != 0){
					printf("COURSE %d	:%d\n",i+1,data->course[i]);
				}
			}
			printf("\n");
		}else if(strcmp(enter,"show score")==0){
			printf("%s's SCORE\n",data->id);
			printf("SCORE	MID	FIN\n");
			clist =grade;
			while(clist != NULL){
				if(strcmp(data->id,clist->id)==0){
					printf("%d	%d	%d\n",clist->classNum,clist->mid,clist->fin);
					
				}
				clist = clist->next;
			}
			printf("\n");
		}else if(strcmp(enter,"logout")==0){
			system("cls");
			printf("=================================================\n"); 
			printf("| NN      N     OOOOO         111      33333333 |\n");
			printf("| N N     N    OO   OO       1111            33 |\n"); 
			printf("| N  N    N   OO     OO        11            33 |\n");
			printf("| N   N   N  OO       OO       11      33333333 |\n");
			printf("| N    N  N   OO     OO        11            33 |\n");
			printf("| N     N N    OO   OO         11            33 |\n");
			printf("| N      NN     OOOOO    0  11111111   33333333 |\n");
			printf("=================================================\n");
			printf("use \"help\" or \"/?\" to get more commands  \n"); 
			printf("\n=======  %s Logout  ======= \n",data->id);
			break;
		}else if(strcmp(enter,"end")==0){
			exit(0);
		}
		else{
			printf("Invalid Command\n");
			printf("\n");
		}
	}
}





