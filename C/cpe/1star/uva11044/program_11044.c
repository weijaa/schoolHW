// One-star problem
// Problem 11044 Searching for Nessy
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
  int cases;
  int n, m;
  
  scanf("%d", &cases); // Input the number of cases.
  
  while (cases>0) {
  	scanf("%d %d", &n, &m); // Input the size of the grid, n and m.
  	// Starting from the upper-left corner, layout the sonar as a 9-point stencil.
  	// 2.0 and 3.0 will make the program to use floating point arithmetic operations, then
  	// apply the ceiling fuction to get the smallest integer larger than each quotient and
  	// cast them as integers.
  	printf("%d\n", (int)ceil((n-2.0)/3.0) * (int)ceil((m-2.0)/3.0)); 
  	cases--;
  }
  return 0;
}
