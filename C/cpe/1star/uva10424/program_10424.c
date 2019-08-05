// One-star problem
// Problem 10424 Love Calculator
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
#include <ctype.h>

int main(void) {
  int person1, person2; // Final single digit value of two persons.
  int value; // Intermediate value.
  int cont; // Continue flag.
  int pair; // Indicate whether a pair of names are processed.
  char c; // To hole an input character.
  int i; // 
  
  do {
  	pair = 0;
  	// Calculate the value of person1.
  	value = 0; // Initial value to 0.
    do {
  	  scanf("%c", &c); // Get the next character.
  	  if (c!=0X0A && !feof(stdin) && isalpha(c)) {
  	  	value += toupper(c) - 'A' + 1; // Add the value of this character.
  	  	pair = 1; // The first name is detected.
      }
    } while (c!=0X0A && !feof(stdin)); // when not a newline nor end of file.
    person1 = 0; // Initially, person 1 is 0.
    cont = 1;
    do {
	  person1 += value % 10; // Add a digit of person1.
	  value = value / 10; // Delete the least significant digit.
	  if (value==0) { // All digits are processed.
	    if (person1<10) cont = 0; // Only one digit left and the calculation is done.
	    else {
		  value = person1; // Reset value.
		  person1 = 0; // No digits accumulated.
		}
	  } // Reset value, and repeat the calculation step.
    } while (cont); // If the value of person1 has more than one digit.
    
  	// Calculate the value of person2.
  	value = 0; // Initial value to 0.
    do {
  	  scanf("%c", &c); // Get the next character.
  	  if (c!=0X0A && !feof(stdin) && isalpha(c)) {
  	  	value += toupper(c) - 'A' + 1; // Add the value of this character.
  	  	pair = 2; // The second name is detected.
      }
    } while (c!=0X0A && !feof(stdin)); // when not a newline nor end of file.
    person2 = 0; // Initially, person 1 is 0.
    cont = 1;
    do {
	  person2 += value % 10; // Add a digit of person1.
	  value = value / 10; // Delete the least significant digit.
	  if (value==0) { // All digits are processed.
	    if (person2<10) cont = 0; // Only one digit left and the calculation is done.
	    else {
		  value = person2; // Reset value.
		  person2 = 0; // No digits accumulated.
		}
	  } // Reset value, and repeat the calculation step.
    } while (cont); // If the value of person2 has more than one digit.
    
    if (pair==2) // If a pair of names are detected, output the love ratio.
      if (person1>=person2) // The ratio can not be over 100%.
        printf("%4.2f %%\n", (float) person2 / person1 * 100.0);
      else 
        printf("%4.2f %%\n", (float) person1 / person2 * 100.0);
  	
  } while (!feof(stdin)); // Terminate the program if reaches the end of file.
  return 0;
}
