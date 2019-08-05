// One-star problem
// Problem UVA401 Palindromes
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
#include <ctype.h>

int is_palindrome, is_mirrored; // global to show palindrome and mirrored states.
// Dictionaries for reversed letters and digits.
char reverse_letter[26] = {'A', ' ', ' ', ' ', '3', ' ', ' ', 'H', 'I', 'L', ' ', 'J', 'M',
                           ' ', 'O', ' ', ' ', ' ', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'};
char reverse_digit[9] = {'1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' '};

// Check palindrome and mirrored string at the same time.
void check_palindrome_mirrored(char *str) {
  int low = 0, high = strlen(str) - 1; // Initial low and high index.
  is_palindrome = 1; // At the beginning, assume the string is a palindrome and a mirrored string.
  is_mirrored = 1;
  // Continue until string is all scanned and it is neither a palindrome nor a mirrored string.
  while (low<=high & (is_palindrome || is_mirrored)) {  
    if (str[low]!=str[high]) is_palindrome = 0; // Check palindrome.
    if (isalpha(str[low]) && str[high]!=reverse_letter[str[low]-0X41]) is_mirrored = 0; // Check mirrored for letters.
    if (isdigit(str[low]) && str[high]!=reverse_digit[str[low]-0X31]) is_mirrored = 0; // Check mirrored for digits.
    low++; // Next character from the left-hand-side.
    high--; // Next character from the right-hand-side.
  }
} 

int main(void) {
  char string[21]; // Maximum string length is 20.
  
  while (scanf("%s", &string)==1){ // If any more string, continue.
    check_palindrome_mirrored(string); // Check palindrome and mirrored string.
    // Output the result for each of the four cases.
    if (is_palindrome)
      if (is_mirrored) printf("%s -- is a mirrored palindrome.\n", string);
      else printf("%s -- is a regular palindrome.\n", string);
    else 
      if (is_mirrored) printf("%s -- is a mirrored string.\n", string);
      else printf("%s -- is a not palindrome.\n", string);
  }
  return 0;
} 
