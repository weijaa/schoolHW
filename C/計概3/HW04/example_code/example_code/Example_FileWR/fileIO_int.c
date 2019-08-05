#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	FILE *inptr = NULL, *outptr = NULL;
	int sum = 0, temp = 0;
	
	
	/* file pointer */
	inptr = fopen("text_int.txt", "r");
	outptr = fopen("text_int_output.txt", "w");
	
	
	if(inptr == NULL)	return 0;
	
	/* read file */
	while( ( fscanf(inptr, "%d", &temp)) != EOF){
		printf("%d", temp);
		sum += temp;
	}
	
	/* write file */
	fprintf(outptr, "sum = %d", sum);
		
	/* close file pointer*/
	fclose(inptr);
	fclose(outptr);
 
	return 0;
}



