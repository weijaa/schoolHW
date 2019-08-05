#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *inptr = NULL, *outptr = NULL;
	unsigned char inputText[256];
	unsigned char outputText[256]; 
	int i = 0;
	char ch;
	
	memset(inputText, 0, sizeof(inputText));
	memset(outputText, 0, sizeof(outputText));
	
	/* file pointer */
	inptr = fopen("text\\text.txt", "r");
	outptr = fopen("text_output.txt", "w");
	
	if(inptr == NULL) {
		puts("No input file");
		return 0;
	}
	
	/* read file */
	while( feof(inptr) == 0 ){ //尚未讀到檔案結束 feof() 回傳 0 
		fscanf(inptr, "%c", &ch);
		outputText[i] = ch;
		i++;
	}
	
	/* write file */
	for(i = 0; i < strlen(outputText) - 1; i++){
		printf("%c", outputText[i]);
		fprintf(outptr, "%c", outputText[i]);
	}
	
	/* close file pointer*/
	fclose(inptr);
	fclose(outptr);
 
	return 0;
}



