#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Login.h"
#include "StudyClub.h" 
#include "Commit.h"
#include "QuestionDiscuss.h" 
#include "Que.h"
#include "SampleQuestion.h" 
int main(int argc, char *argv[]) {
	char id[100];
	strcpy(id,Login());
	while(1){
		system("cls");
		printf("=======================================\n");
		printf("| FFFFFFF CCCCCCC U     U   +     +   |\n");
		printf("| F       C       U     U   +     +   |\n");
		printf("| FFFFFFF C       U     U +++++ +++++ |\n");
		printf("| F       C       U     U   +     +   |\n");
		printf("| F       CCCCCCC UUUUUUU   +     +   |\n");
		printf("=======================================\n");
		int i;
		printf("�z�n%s ! \n",id);
		printf("1.�ҵ{����\n");
		printf("2.���D�Q��\n");
		printf("3.�Юv�Q��\n");
		printf("4.�ҥj�D&�W�ү���\n");
		printf("5.Ū�ѷ|\n");
		printf("��L���N�ץ󵲧�\n");
		scanf("%d",&i);
		if(i==1){
			Commit();
		}else if(i==2){
			QuestionDiscuss(id);
		}else if(i==3){
			Que(id);
		}else if(i==4){
			SampleQuestion();
		}else if(i==5){
			StudyClub(id);	
		}else{
			break;
		}
	}
	
	return 0;
}
