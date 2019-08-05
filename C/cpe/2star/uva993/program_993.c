// Two-star problem
// Problem 993 Product of Digits
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
#include <math.h>

int main(void) {
  int cases; // Number of cases;
  unsigned int N; // Input integer N.
  long long int Q; // The integer its product of digits is N, if there is one; otherwise, -1.
  int factor;
  int position; // digit position from left to right.
  int i; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%u", &N); // Input integer N.
    
    if (N<10) Q = N; // For a single digit integer, Q is N itself.
    // For the other integers, it must contain only 2, 3, 4, 5, 6, 7, 8, and 9 as
    // its factors. To get the minimum Q, we test the factors in the order of 9, 8,
    // 7, 6, 5, 4, 3, and 2, and place the factors in the digits of Q from right
    // to left. Since Q may be greater than the maximum element of 32-bit unsigned
	// integer, we declare Q as the type of long long int.
    else {
      factor = 9;
      position = 0;
      Q = 0;
      while (factor>1) { // When the factor is 9, 8, 7, 6, 5, 4, 3, or 2, continue.
        if (N%factor==0) { // N has a factor of 9, 8, 7, 6, 5, 4, 3, or 2.
          Q += factor * pow(10, position++); // Add a digit to Q.
          N = N / factor; // Test N after take the factor out.
		}
		else factor--; // Test the next factor.      	
	  }
	  if (N!=1) Q = -1; // N cannot be the product of a set of digits.
	}
	printf("%lld\n", Q); // Output the result, Q.
  }
  return 0;
}
