// One-star problem
// Problem 10222 Decode the Mad Man
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
#include <string.h>

// Since the problem does not mention the character set to decode.
// We will deal with lower case letters only.
int main(void) {
  char row_1[13]="qwertyuiop[]"; // The first row letters.
  char row_2[12]="asdfghjkl;'"; // The second row letters.
  char row_3[11]="zxcvbnm,./"; // The third row letters.
  char book[128]; // The code book.
  char c; // Input character.
  int i; // Loop variable.
   
  for (i=1; i<128; i++) book[i] =' '; // Initial the code book to all spaces.
  for (i=0; i<strlen(row_1)-2; i++) book[row_1[i+2]] = row_1[i]; // Create code book for row 1.
  for (i=0; i<strlen(row_2)-2; i++) book[row_2[i+2]] = row_2[i]; // Create code book for row 2.
  for (i=0; i<strlen(row_3)-2; i++) book[row_3[i+2]] = row_3[i]; // Create code book for row 3.
  
  while (scanf("%c", &c)==1) { // Continue, if not reach the end of file.
    // If not linefeed, return, or space, encode the letter and output it.
    if (c!=0X0A && c!=0X0D) printf("%c", book[tolower(c)]);
    else printf("\n");
  }
  return 0;
}
