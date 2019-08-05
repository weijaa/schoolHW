// One-star problem
// Problem 10082 WERTYU
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
  // Code book of all keys on the keyboard. This code book starts from the space ' ' key.
  //                0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
  char book[62] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ';', ' ', ' ', ' ', ' ', 'M', '0', ',', '.', // 2
                   '9', '`', '1', '2', '3', '4', '5', '6', '7', '8', ' ', 'L', ' ', '-', ' ', ' ', // 3
                   ' ', ' ', 'V', 'X', 'S', 'W', 'D', 'F', 'G', 'U', 'H', 'J', 'K', 'N', 'B', 'I', // 4
                   'O', ' ', 'E', 'A', 'R', 'Y', 'V', 'Q', 'Z', 'T', ' ', 'P', ']', '['};          // 5
  char c; // The input character
  
  while (!feof(stdin)) { // Continue until the end of file.
    c = fgetc(stdin); // Input a character. 
    // If the character is neither a carriage return nor a line feed, 
	// translate it according to the code book and output the resulting character.
    if (c!=0X0A && c!=0X0D) fputc(book[c-0X20], stdout); 
  }
  fputc('\n', stdout); // Output a newline.  
  return 0;
}
