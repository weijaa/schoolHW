// One-star problem
// Problem 10696 f91
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

// Recursive definition of function f91.
int f91(int N) {
  if (N<=100) return f91(f91(N + 11));
  else return N - 10;
}

int main(void) {
  int N;
  
  while (1) {
  	scanf("%d", &N); // Input an integer N.
  	if (N==0) break; // If N is 0, stop the loop and terminate the program.
  	else printf("f91(%d) = %d\n", N, f91(N)); // Output the result.
  }
  return 0;
}
