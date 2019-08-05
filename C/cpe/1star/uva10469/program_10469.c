// One-star problem
// Problem 10469 To Carry or not to Carry
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

// Mofitz's adder is exactly bitwise XOR of two unsigned 32-bit integers.
int main(void) {
  unsigned int m, n;
  
  while (scanf("%d %d", &m, &n)==2) { // Input two integers, if there is any.
  	printf("%d\n", m^n); // Output bitwise XOR of these two unsigned 32-bit integers.
  }
  return 0;
}
