#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	fgets()
	fputs()
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
	while( (fgets(outputText, 256, inptr)) != NULL){
		printf("%s", outputText);
		/* write file */
		fputs(outputText, outptr);
	}
	
	/* close file pointer*/
	fclose(inptr);
	fclose(outptr);
 
	return 0;
}



