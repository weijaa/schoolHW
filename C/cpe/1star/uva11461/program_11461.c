// One-star problem
// Problem 11461 Square Numbers
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
  int a, b; // Two input integers.
  int a_sqrt; // Largest square root less than or equal to a.
  int b_sqrt; // Smallest square root larger than or equal to a.
  
  while (1) {// Continue until "0 0" are input.
    scanf("%d %d", &a, &b); // Input two integers.
    
    if (a==0 && b==0) break; // If the input is "0 0", stop the loop ad terminate the program.
    
    a_sqrt = sqrt(a); // Possible largest square root less than or equal to a.
    b_sqrt = sqrt(b); // Smallest square root larger than or equal to a.
    if (a>a_sqrt*a_sqrt) a_sqrt++; // Increment a_sqrt, if it is not the square root of a.
	
	printf("%d\n", b_sqrt-a_sqrt+1); // Number of square numbers between a and b (inclusive).
  }
  return 0;
}
