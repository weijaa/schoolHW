// One-star problem
// Problem 11332 Summing Digits
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
  int n; // Input integer n.
  int digit_sum;
  
  scanf("%d", &n); // Input an integer n.
  
  while (n>0) { // Continue when n is a positive integer.
    digit_sum = 0; // Clear the digit sum.
    
    while (n>=10) { // When there are more digits remaind.
      digit_sum += n % 10;
      n = n / 10;
      if (n<10) {
      	n = n + digit_sum; // Reset n to be sum of all digits.
      	digit_sum = 0; // Clear the digit sum.
	  };
    }
    printf("%d\n", n); // Output g(n).
    scanf("%d", &n); // Input the next integer.
  }
  return 0;
}
