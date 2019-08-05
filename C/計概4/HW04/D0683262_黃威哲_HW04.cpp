#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *inptr,*outptr;
	int i,j,k;
	char word;
	char x[400],ans[1000];
	inptr = fopen("input.txt","r");
	outptr = fopen("output.txt","w");
	
	while(feof(inptr) ==0){
		fscanf(inptr,"%s",x);
		printf("%s\n",x);
	//	printf("%c %c",x[0],x[1]);
		for(i=0;i<strlen(x);i++){
		//	printf("%d ",i);
			if(x[i] == x[i+1]){
				printf("r");
				word = x[i];
				j=0;
				while(x[i] == word){
					j++;
					i++;
				}
				i--;
				printf("%d%c",j,word);
			}
			else{
				printf("n");
				j=0;
				while(x[i] != x[i+1]){
					ans[j] = x[i];
					i++;
					j++;
				}
				i--;
				printf("%d%s",strlen(ans),ans);
				memset(ans , 0 , strlen(ans));
			}
		}
	}
	fclose(inptr);
	fclose(outptr);
	return 0;
} 
