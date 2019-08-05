// One-star problem
// Problem 10260 Soundex
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

int main(void) {
  /* Soundex code book:
     1 represents B, F, P, or V
     2 represents C, G, J, K, Q, S, X, or Z
     3 represents D or T
     4 represents L
     5 represents M or N
     6 represents R
     The letters A, E, I, O, U, H, W, and Y are not represented in Soundex coding.
  */
                  // ABCDEFGHIJKLMNOPQRSTUVWXYZ
  char soundex[27]= " 123 12  22455 12623 1 2 2";
  char word[20]; // Input word, less than 20 letters long.
  char i;
  
  while (scanf("%s", word)==1) { // Input put a word;
    for (i=0; i<strlen(word); i++) { // Scan all letters in the word.
      if (soundex[word[i]-'A']!=' ') { // If the letters is A, E, I, O, U, H, W, or Y skip it.
      	if (i==0) { // If it is the first letter, print the encoded digit.
		  printf("%c", soundex[word[i]-'A']);
		}
      	else if (word[i]!=word[i-1]) { // If it is not the first and not repeated, print the encoded digit. 
		  printf("%c", soundex[word[i]-'A']);
		}
	  }
	}
	printf("\n"); // Output a newline.
  }
  return 0;
}
