#include"MANAGER.h"


void manager(person *data,list *grade){
	system("cls");
	printf("=======   Hello Admin   =======\n");
	person *current;
	int num,i,j;
	list *clist,*temp;
	current = data;
	char enter[20];
	fflush(stdin);
	char id[20];
	while(1){
		memset(enter,0,sizeof(enter));
		gets(enter);
		fflush(stdin);
		if(strcmp(enter,"help")==0 || strcmp(enter,"/?")==0){
			printf("add course	加選\n");
			printf("drop course	退選\n");
			printf("logout		登出\n");
			printf("end		結束\n");
			printf("\n");
		}else if(strcmp(enter,"add course")==0){
			printf("enter student ID\n");
			scanf("%s",id);
			fflush(stdin);
			current = data;
			while(current != NULL){
				if(strcmp(id,current->id)==0) break;
				current = current->next;
			}
			if(current == NULL) printf("No this id\n");
			else if(current->course[4] != 0) printf("Full class\n");
			else{
				printf("enter course\n");
				scanf("%d",&num);
				fflush(stdin);
				for(i=0;i<6;i++){
					if(current->course[i]==num) {
						printf("Already have class\n");
						break;
					}else if(current->course[i]==0){
						current->course[i] = num;
						break;
					}
				}
				clist =grade;
				while(clist != NULL){
					if(clist->classNum == num) break;
					clist = clist->next;
				}
				if(clist ==NULL){
					printf("No this class\n");
					for(i=0;i<6;i++){
						if(current->course[i]==num) current->course[i]=0;
					}
				}else{
						
					temp = clist->next;
					clist->next = newlist();
					clist = clist->next;
					clist->classNum = num;
					strcpy(clist->id,current->id);
					clist->next = temp;
				}
			}
		}else if(strcmp(enter,"drop course")==0){
			printf("enter student ID\n");
			scanf("%s",id);
			fflush(stdin);
			current = data;
			while(current != NULL){
				if(strcmp(id,current->id)==0) break;
				current = current->next;
			}
			if(current == NULL) printf("No this id\n");
			else{
				printf("enter course\n");
				scanf("%d",&num);
				fflush(stdin);
				for(i=0;i<6;i++){
					if(current->course[i]==num){
						current->course[i]=0;
						break;
					}else if (current->course[i]==0){
						printf("No this class\n");
						break;
					}
				}
				clist =grade;
				while(clist != NULL){
					if(clist->next->classNum == num) break;
					clist = clist->next;
				}if(clist ==NULL){
					printf("No this class\n");
					for(i=0;i<6;i++){
						if(current->course[i]==num) current->course[i]=0;
					}
				}else{
					temp = clist->next->next;
					clist->next = temp;
				}
			}
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
			printf("\n=======  Admin Logout  ======= \n");
			break;
		}else if(strcmp(enter,"end")==0){
			exit(0);
		}else {
			printf("Invalid Command\n");
			printf("\n");
		}
	}
} 







