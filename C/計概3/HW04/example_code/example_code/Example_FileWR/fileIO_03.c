#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	fread()
	fwrite()
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
	while( feof(inptr) == 0 ){
		fread(outputText, sizeof(char), 256, inptr);
	}
	
	printf("%s", outputText);
	/* write file */
	fwrite(outputText, sizeof(char), 256, outptr);
	
	/* close file pointer*/
	fclose(inptr);
	fclose(outptr);
 
	return 0;
}



