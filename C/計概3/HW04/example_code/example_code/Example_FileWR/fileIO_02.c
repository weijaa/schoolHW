#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	getc()
	putc()
*/

int main(){
	FILE *inptr = NULL, *outptr = NULL;
	unsigned char inputText[256] = {'\0'};
	unsigned char outputText[256] = {'\0'}; 
	int i = 0, ctr = 0;
	char ch;
	
	
	/* file pointer */
	inptr = fopen("text.txt", "r");
	outptr = fopen("text_output.txt", "w");
	
	if(inptr == NULL)	return 0;
	
	/* read file */
	while( (ch = getc(inptr)) != EOF ){
		outputText[i] = ch;
		i++;
	}
	
	
	/* write file */
	for(i = 0; i < strlen(outputText); i++){
		printf("%c", outputText[i]);
		putc(outputText[i], outptr);
	}
	
	/* close file pointer*/
	fclose(inptr);
	fclose(outptr);
 
	return 0;
}



