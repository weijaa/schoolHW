#include "Commit.h"

//�g���� 
void write_com(){					 
	char com[999];
	int num;
	printf("��J�ҵ{�N�X:");
	scanf("%d",&num); 
	printf("�п�J�A�惡�ҵ{������ :\n");
	scanf("%s",com);
	FILE *data = fopen("com.txt","a");
	fprintf(data,"%d %s\n",num,com);
	fclose(data);
} 
//��ܵ��� 
void show_com(){
	char comment[100];
	FILE *data = fopen("com.txt","r");
	while(feof(data)==0){
		memset(comment,0,sizeof(comment));
		fgets(comment,100,data);
		puts(comment);
	}
	fclose(data);
}
void Commit(){
	system("cls");
	int num;
	while(1){
		printf("1.����\n");
		printf("2.�d�ݵ�������\n");
		printf("��L���N�ץ��^\n");
		scanf("%d",&num);
		if(num==1){
			write_com();
		}else if(num==2){
			show_com();
		} else break;
	}
}
