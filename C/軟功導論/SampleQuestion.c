#include "SampleQuestion.h"

void SampleQuestion(){
	int n;
	while(1){
		system("cls");
		printf("1.�������D\n");
		printf("2.��������\n");
		printf("3.�զX�y��\n");
		printf("��L�����^\n");
		scanf("%d",&n);
		char word[100]={0};
		if(n==1){
			system("cls");
			FILE *in = fopen("net.txt","r");
			while(feof(in)==0){
				fgets(word,100,in);
				puts(word);
			}
			fclose(in);
			system("pause");
		}else if(n==2){
			system("cls");
			FILE *dis = fopen("math.txt","r");
			while(feof(dis)==0){
				fgets(word,100,dis);
				puts(word);
			}
			fclose(dis);
			system("pause");
			
			
		}
		else if(n==3){
			system("cls");
			FILE *dis = fopen("asm.txt","r");
			while(feof(dis)==0){
				fgets(word,100,dis);
				puts(word);
			}
			fclose(dis);
			system("pause");
		}else{
			break;
		}
	} 
}
