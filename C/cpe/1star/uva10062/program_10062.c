// One-star problem
// Problem 10062 Tell Me the Frequencies!
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
  char letter[95]; // Total 95 printable characters, starting from ' ' (space, 0X20) to '~' (0X7E).
  int letter_count[95]; // Record the letter occurrences.
  char c; // Record the currenct input character.
  int count; // Record the number of printable letters in a line.
  char letter_temp; // Temporary letter for swapping operation.
  int letter_count_temp; // Temporary letter counter for swapping operation.
  int i, j; // Loop variables.
  
  for (i=0; i<95; i++) {
    letter[i] = i + 0X20; // Initial the printable letters, ' ' (space, 0X20) to '~' (0X7E).
    letter_count[i] = 0; // Set all letter counters to 0.
  } 
  count = 0; // Set line counter to 0. 
  while (!feof(stdin)) { // Read input data until the end of file.
    scanf("%c", &c);
    if (c!=0X0A && c!=0X0D) { // Read a printable character.
      letter_count[c-0X20] = letter_count[c-0X20] + 1; // Increment the letter count.
      count++; // Increment the line counter
	}
    else if (count==0) ; // A line has been processed and simply ignore this character.
	else { // When a line of text has been read complete, sort and print the letter frequencies.
	
	  // Double key sorting. 
	  // The first key, the letter counter, is in the ascending order, and
	  // the second key, the printable letter, is in the descending order.
	  for (i=94; i>1; i--)
	    for (j=1; j<=i; j++)
	      if (letter_count[j-1]>letter_count[j] || // Compare the first key.
		      (letter_count[j-1]==letter_count[j]) && letter[j-1]<letter[j]) { // With the same first key, compare the second keyy.
		    letter_temp = letter[j-1];
		    letter_count_temp = letter_count[j-1];
		    letter[j-1] = letter[j];
		    letter_count[j-1] = letter_count[j];
		    letter[j] = letter_temp;
		    letter_count[j] = letter_count_temp;
		  }
	
	  for (i=0; i<95; i++) // Print the letters and its number of occurrences if it is not 0.
	    if (letter_count[i]!=0) printf("%d %d\n", letter[i], letter_count[i]);
	  printf("\n");
	  for (i=0; i<95; i++) { // Reset letter counters.
        letter[i] = i + 0X20; // Initial the printable letters, ' ' (space, 0X20) to '~' (0X7E).
        letter_count[i] = 0; // Set all letter counters to 0.
      } 
      count = 0; // Set line counter to 0. 
	}
  }
  return 0;
}
