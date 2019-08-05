// One-star problem
// Problem 11483 Code Creator
/*
This program is written by
    Prof. Chua-Huang Huang
	Department of Information Engineering and Computer Science
	Feng Chia University
	Taichung, Taiwan
Disclaimer:
    The programming problem is downloaded from UVa Online Judge (https://uva.onlinejudge.org/).
    The program solution is provided for helping students to prepare Collegiate Programming
	Examination	(CPE). The author does not guarantee the program is completely correct to pass 
	UVa Online Judge platform or CPE examination platform.
	This program is not intended for a student to copy only. He/She should practice the 
	programming problem himself/herself. Only use the program solution as a reference. 
    
	The author is not responsible if the program causes any damage of your computer or 
	personal properties.
	No commercial use of this program is allowed without the author's written permission.	
*/
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int line; // Input number of lines.
  int case_index = 1; // Case index.
  char c;
  
  while (1) { // Continue if the input number of lines is not 0.
    scanf("%d", &line); // Input the number of lines.
    
    if (line==0) break; // If the number of line is 0, stop the program and terminate the program.
    
    printf("Case %d:\n", case_index++); // Output the case number.
    
    scanf("%c", &c); // Input a character.
    while (c!=0X0A) scanf("%c", &c); // Move the stream pointer after newline.
    // Output the program preamble text.
    printf("#include<string.h>\n");
    printf("#include<stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    
    while (line>0) {
      printf("printf(\""); // Output the preamble of the <case specific lines>.
      
      scanf("%c", &c); // Input a character.
      while (c!=0X0A) { // Continue if c is not a newline.
        // Escape sequence character.
        if (c=='\'' || c=='\"' || c=='\?' || c=='\\') printf("\\"); 
        printf("%c", c); // Echo the character.
        scanf("%c", &c); // Input another character.
	  }
	  printf("\\n\");\n"); // Output the finale of the <case specific lines>.
	  line--;
    }
    
    // Output the program finale text.
    printf("printf(\"\\n\");\n");
    printf("return 0;\n");
    printf("}\n");
  }
  return 0;
}
