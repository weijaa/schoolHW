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
		printf("您好%s ! \n",id);
		printf("1.課程評價\n");
		printf("2.問題討論\n");
		printf("3.教師討論\n");
		printf("4.考古題&上課素材\n");
		printf("5.讀書會\n");
		printf("其他任意案件結束\n");
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
