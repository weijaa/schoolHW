// One-star problem
// Problem 10929 You Can Say 11
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

// If the difference betewwn the sum of the odd position digits and the sum of the even
// position digits is a multiple of 11. The number is a multiple of 11.
int main(void) {
  char number[1001]; // The input number up to 1000 digits.
  int sum; // Sum of digits, even index add to the sum, odd index minus from the sum.
  int sign; // The sign indicator, 1 for even index and -1 for odd index.
  int i; // Loop index.
  
  while (1) { // Continue the loop until 0 is input.
    scanf("%s", &number);
    if (strcmp(number,"0")==0) break; // If the input is 0, stop the loop and program terminates.
    sum = 0;
    sign = 1;
    for (i=0; i<strlen(number); i++) {
      sum += sign * (number[i] - '0'); // Add the digit to or minus the digit from the sum.
      sign *= -1; // Change the sign from 1 to -1 or from -1 to 1.
	}
	if (sum%11==0) printf("%s is a multiple of 11.\n", number);
	else  printf("%s is not a multiple of 11.\n", number);    
  }
  return 0;
}
