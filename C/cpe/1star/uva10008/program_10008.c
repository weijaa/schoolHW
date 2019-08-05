// One-star problem
// Problem UVA10008 What¡¦s Cryptanalysis?
/*
This program is written by
    Prof. Chua-Huang Huang
	Department of Information Engineering and Computer Science
	Feng Chia University
	Taichung, Taiwan
Disclaimer:
    The programming problem is downloaded from UVa Online Judge (https://uva.onlinejudge.org/).
    The program solution is provided for helping students to prepare Collegiate Programming
	Examination (CPE). The author does not guarantee the program is completely correct to pass 
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
  int line;
  char c;
  int count[26]; // Couter for all letters 'A' to 'Z'.
  char letter[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // The letter list.
  int temp; // Temporary counter for swap operation.
  char c_temp; // Temporary letter for swap operation.
  int i, j; // Loop variables.
  
  scanf("%d", &line); // Input the number of lines.
  
  for (i=0; i <26; i++) count[i] = 0; // Clear the counter.
  
  while (scanf("%c", &c)==1) { // Scan all input characters.
  	if (isalpha(c)) { // When reading an English letter, increment the counter.
  	  c = toupper(c); // Convert to the upper case letter.
  	  count[c-'A'] = count[c-'A'] + 1;  // Increment the corresponding counter.
	}
  }
  
  // Use the insertion sort alorithm to  sort the counters in descending order.
  // When swap the counters, also swap the corresponding letters.
  for (i=25; i>0; i--)
    for (j=1; j<=i; j++) {
      if (count[j-1]<count[j]) { // The sorting order is descending order.
      	temp = count[j]; // swapping counter.
      	c_temp = letter[j]; // swapping letter.
      	count[j] = count[j-1];
      	letter[j] = letter[j-1];
      	count[j-1] = temp;
      	letter[j-1] = c_temp;
	  }
	}

  // Print the sorted letter and counter when it is not 0, in the descending order.
  for (i=0; i<26; i++) {
  	if (count[i]>0) printf("%c %d\n", letter[i], count[i]);
  	else break;
  } 
  return 0;
} 
