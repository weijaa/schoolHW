#include "QuestionDiscuss.h"
#define MAX 60 

void QuestionDiscuss(char id[]){
	system("cls");
	size_t write_num;
    FILE *fp;
    int a,Case,i,j,ques[MAX];
    a=1;
    if(access("answer.dat", 0 )==-1)
    {
        for(i=0; i<MAX; i++)
        {
            ques[i]=0;
        }
    }
    while(a!=0)
    {
        fp = fopen( "answer.dat","a+" );
        printf("1.Question\n");
        printf("0.Back to main menu\n");
        printf("Please choose function : ");
        scanf("%d",&Case);
        switch(Case)
        {
        case 1:
            for(i=0; i<100; i++)
            {
                if(ques[i]==0)
                {
                    while(1)
                    {
                        printf("ДЃАн: ");
                        scanf("%d",&ques[i]);
                        if(ques[i] < 0)
                            printf(" wrong!\n");
                        else
                            break;
                            printf("%d",&ques[i]);
                    }
                    fclose(fp);
                    break;
                }
            }
            break;
        case 0:
            fclose(fp);
            a=0;
            break;
        default :
            printf("input number wrong!\n");
            break;
        }
    }
}
