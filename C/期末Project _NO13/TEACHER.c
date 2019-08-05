#include"TEACHER.h"


void teacher(person *data,list *grade){
	char command[20];
	int j,i,num,time; 

	list *clist;
	
	printf("=======   Hello %s   =======\n",data->id);
	memset(command,0,sizeof(command));
	fflush(stdin);
	while(1){
		memset(command,0,sizeof(command));
		gets(command);
		fflush(stdin);
		if(strcmp(command,"help") == 0 || strcmp(command,"/?") == 0 ){
			printf("logout			    	登出\n");
			printf("show info		    	顯示基本資料\n");
			printf("show course		 	  顯示教課清單\n");
			printf("course 				顯示課程名單\n");
			printf("enter score 		 	登記分數\n"); 
			printf("end				結束程式\n");
			printf("\n");
		}else if(strcmp(command,"show info")==0){
			printf("\nINFORMATION\n");
			printf("ID	:%s\n",data->id);
			printf("NAME	:%s\n",data->name);
			printf("DEPT	:%s\n",data->dept);
			printf("B-DAY	:%s\n",data->bir);
			printf("\n");
		}else if(strcmp(command,"show course")==0){
			printf("\nCOURSES\n");
			printf("ID		:%s\n",data->id);
			for(i=0;i<6;i++){
				if(data->course[i] != 0){
					printf("COURSE %d	:%d\n",i+1,data->course[i]);
				}
			}
			printf("\n");
		} else if(strcmp(command,"course")==0){
			time=0;
			printf("enter course number\n");
			scanf("%d",&num);
			fflush(stdin);
			for(i=0;i<6;i++){
				if( num == data->course[i]){
					time++;
					break;
				}
			}
			if(time==0) printf("No this class\n");
			else {
				clist = grade;
				printf("COURSE %d\n",data->course[i]);
				printf("ID		MID	FIN\n");
				while(clist != NULL){
					if(clist->classNum == num && clist->id[0] != 'T'){
						printf("%s	%d	%d\n",clist->id,clist->mid,clist->fin);
					}
					clist = clist->next;
				}
			}
			printf("\n");
		} else if(strcmp(command,"enter score")==0){
			time=0;
			printf("enter course number\n");
			scanf("%d",&num);
			fflush(stdin);
			for(i=0;i<6;i++){
				if( num == data->course[i]){
					time++;
					break;
				}
			}
			if(time==0) printf("No this class\n");
			else {
				clist = grade;
				printf("COURSE %d\n",data->course[i]);
				printf("ID		MID FIN\n");
				while(clist != NULL){
					if(clist->classNum == num && clist->id[0] == 'D'){
						printf("%s	",clist->id);
						scanf("%d %d",&clist->mid,&clist->fin);
						fflush(stdin);
					} 
					clist = clist->next;
				}
			}
			printf("\n");
		} else if(strcmp(command,"logout")==0){
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
		}else if(strcmp(command,"end")==0){
			exit(0);
		}
		else {
			printf("Invalid Command\n");
			printf("\n");
		}
	}
}
