// One-star problem
// Problem UVA272 TeX Quotes
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
  char c;
  int quote = 0; // 0: The left double quotation; 1: the right double quotation
  
  // stdin: the FILE pointer to the standard input.
  // stdout: the FILE pointer to the standard output.
  while (!feof(stdin)) { //
    c = fgetc(stdin); // Input a charcter.
    if (c=='\"') // If the character is the dobule quotation, 
      if (!quote) {fputc('`', stdout);fputc('`', stdout); quote = 1;} // if left double quotation, output "``"; invert the quote state;
      else {fputc('\'', stdout); fputc('\'', stdout); quote = 0;} // if right double quotation, output "''"; invert the quote state;
    else fputc(c, stdout); // The input character is not a dobule quotation, echo the character.  
  }
  return 0;
} 
