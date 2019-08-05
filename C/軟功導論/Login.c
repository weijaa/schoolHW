#include"Login.h"

char* Login(){
	FILE *in = fopen("stuInfo.txt","r");
	int i=0,time;
	char idData[100][100] = {0};
	char pwdData[100][100] = {0};
	while(feof(in)==0){
		fscanf(in,"%s",idData[i]);
		fscanf(in,"%s",pwdData[i]);
		i++;
	}
	i--;
	fclose(in);
	printf("------------FCU++------------\n");
	printf("1.登入\n");
	printf("2.註冊\n");
	printf("3.離開\n");
	int n = 0;
	static char id[100]={0};
	char password[100] = {0};
	scanf("%d",&n);
	if(n==1){
		system("cls");
		printf("帳號:");
		scanf("%s",id);
		fflush(stdin);
		printf("密碼:");
		scanf("%s",password);
		fflush(stdin);
		for(time=0;time<i;time++){
			if(strcmp(idData[time],id) == 0 && strcmp(pwdData[time],password) == 0) return id;
		}
		if(time >= i){
			printf("帳號或密碼錯誤!\n");
			Login();
		} 
		
	}else if(n==2){
		FILE *data = fopen("stuInfo.txt","a");
		system("cls");
		printf("-----------註冊---------------\n");
		printf("輸入你的帳號:");
		scanf("%s",id);
		printf("輸入你的密碼:");
		scanf("%s",password); 
		fprintf(data,"%s %s\n",id,password);
		fclose(data);
		Login();
	}else if(n==3){
		exit(0);
	}else{
		printf("請重新選擇\n");
		Login();
	}
	
}
