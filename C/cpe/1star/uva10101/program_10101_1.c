// One-star problem
// Problem 10101 Bangla Numbers
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

/* Observe that a Bangla number has a cycle of seven digits from the right-hand-side. We break the
   digit string of a Bangla into a number of segments with seven digits each segment from the
   right-hand-side. If the length of the digit string is not a multiple of seven, the remainding 
   digits is expanded on the left-hand-side of the Bangla number.
   When expand the Bangla number according to the number of digits in a segment from 1 to 7. We use
   a swithc-case statment without "break" inside each case. Hence, in each case, it will continue to 
   process the rest of cases.
*/

int main(void) {
  // The maximum value 9 99 99 9 99 99 99 9 99 will cause unsigned long overflow.
  // We use string to represent the input Bangla numbers. Hence, it is not limited to the
  // maximum of value  9 99 99 9 99 99 99 9 99.
  char number[101]; // Input number, we will treat the number as a string, maximum 100 digits.
  int line_index = 1; // Line index starting from 1.
  int total_digit; // Total number of digits of the input number.
  int curr_index = 0; // Current digit index starting from the left hand side, initial value 0.
  int segment_length; // Number of digits in a segement.
  int Bangla; // Numeral value of Bangla number is a segement.
  int i; // Loop variable.
  
  while (scanf("%s", number)==1) { // Input the number as a string of digits, if there is any.
  	total_digit = strlen(number); // Total number of digits of the input number.
	printf("%4d. ", line_index++); // Print the line number and increment by 1.
	
  	while (curr_index<total_digit) { // If there are more digits to be expanded.
  	  // If the length of the digit string is not a multiple of seven, the remainding 
      // digits is expanded on the left-hand-side of the Bangla number. 
  	  segment_length = (total_digit - curr_index) % 7; // Get the number of digits in a segment.
  	  
  	  if (segment_length==0) segment_length = 7; // A full segment of seven  digits.
	  Bangla = 0; // Numeral value of in a literal of Bangla index.
  	  switch (segment_length) { // Seven cases from 7 to 1 without "break" so it will continue to
  	                            // Process the rest of cases.
  	  	case 7: {
		  Bangla = number[curr_index++] - '0'; // Convert the value of the first of two digits.
		}
  	  	case 6: {
		  Bangla = Bangla * 10 + (number[curr_index++] - '0'); // Convert the value of the second digit.
		  if (Bangla!=0) printf("%d lakh ", Bangla); // Print the two-digit value and "lakh"; skip, if 0.
		}
  	  	case 5: {
		  Bangla = number[curr_index++] - '0'; // Convert the value of the first of two digits.
		}
  	  	case 4: {
		  Bangla = Bangla * 10 + (number[curr_index++] - '0'); // Convert the value of the second digit.
		  if (Bangla!=0) printf("%d hajar ", Bangla); // Print the two-digit value and "haraj"; skip, if 0.
		}
  	  	case 3: {
		  Bangla = number[curr_index++] - '0'; // Convert the value of the single digit.
		  if (Bangla!=0) printf("%d shata ", Bangla); // Print the single-digit value and "shata"; skip, if 0.
		}
  	  	case 2: {
		  Bangla = number[curr_index++] - '0'; // Convert the value of the first of two digits.
		}
  	  	case 1: {
		  Bangla = Bangla * 10 + (number[curr_index++] - '0'); // Convert the value of the second digit.
		  if (Bangla!=0) printf("%d ", Bangla); // Print "the two digit value; skip, if 0.
		  else if (total_digit==1) printf("%d", 0);
		  if (curr_index<total_digit) printf("kuti "); // Print "kuti" if there are more digits to be processed.
		}  	  	
	  }
	}
	printf("\n");
	curr_index = 0; // Reset current to 0. Test the next input.
  }
  return 0;
}
