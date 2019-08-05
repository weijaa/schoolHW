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
#include <string.h>

// Create the code book row by row.
void make_book(char *keyboard, char book[]) {
  int i;
  
  for (i=1; i<strlen(keyboard); i++) book[keyboard[i]] = keyboard[i-1];	
}

int main(void) {
  char book[128] ; // Code book.
  char *keyboard_row1 = "`1234567890-=";
  char *keyboard_row2 = "QWERTYUIOP[]\\";
  char *keyboard_row3 = "ASDFGHJKL;'";
  char *keyboard_row4 = "ZXCVBNM,./";
  char c; // The input character
  int i;
  
  // Making the code book.
  for (i=0; i<128; i++) book[i] = 0X20; // Clear the code book.
  make_book(keyboard_row1, book);
  make_book(keyboard_row2, book);
  make_book(keyboard_row3, book);
  make_book(keyboard_row4, book);
  
  while (!feof(stdin)) { // Continue until the end of file.
    c = fgetc(stdin); // Input a character. 
    // If the character is neither a carriage return nor a line feed, 
	// translate it according to the code book and output the resulting character.
    if (c!=0X0A && c!=0X0D) fputc(book[c], stdout); 
  }
  fputc('\n', stdout); // Output a newline.
  return 0;
}
