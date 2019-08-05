#include<stdio.h>
#include<unistd.h> 

int main(int argc, const char* argv[]){
	FILE *meow;
	char a;
	if(access(argv[1],0) != -1){
		printf("failed to open file: File exists\n");
		return 0;
	}
	meow = fopen(argv[1],"w");
	printf("writing \"");
	int i=0;
	while(1){
		if(argv[1][i] == '.'){
			break;
		}
		else{
			printf("%c",argv[1][i]);
			i++;
		}
	}
	printf("\" (use ctrl + d to send EOF)\n");
	printf("-------------------------------------------------\n");
	while((a = getchar()) != EOF ){
		fprintf(meow,"%c",a);
	}
	fclose(meow);
	
	
	return 0;
} 
