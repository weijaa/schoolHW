#include "Commit.h"

//寫評論 
void write_com(){					 
	char com[999];
	int num;
	printf("輸入課程代碼:");
	scanf("%d",&num); 
	printf("請輸入你對此課程的評價 :\n");
	scanf("%s",com);
	FILE *data = fopen("com.txt","a");
	fprintf(data,"%d %s\n",num,com);
	fclose(data);
} 
//顯示評論 
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
		printf("1.評價\n");
		printf("2.查看評價紀錄\n");
		printf("其他任意案件返回\n");
		scanf("%d",&num);
		if(num==1){
			write_com();
		}else if(num==2){
			show_com();
		} else break;
	}
}
