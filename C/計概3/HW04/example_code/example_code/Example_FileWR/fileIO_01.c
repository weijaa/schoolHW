#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	fscanf()
	fprintf()
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
	while( fscanf(inptr, "%c", &ch) != EOF ){
		outputText[i] = ch;
		i++;
	}
	
	
	/* write file */
	for(i = 0; i < strlen(outputText); i++){
		printf("%c", outputText[i]);
		fprintf(outptr, "%c", outputText[i]);
	}
	
	/* close file pointer*/
	fclose(inptr);
	fclose(outptr);
 
	return 0;
}



