// One-star problem
// Problem 11417 GCD
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

// GCD: greatest common divisor
int GCD(int m, int n) {
  if (m%n==0) return n;
  else return GCD(n, m % n);
}

int main(void) {
  int N; // Input integer
  int G; // Summation of GCD.
  int i, j; // Loop variables.
  
  while (1) { // Continue until the input integer is 0.
    scanf ("%d", &N); // Input an integer n.
  
    if (N==0) break; // If n is 0, stop the loop and terminate the program.
    
    G = 0; // Clear the summation of GCD.
    for (i=1; i<N; i++)
      for(j=i+1; j<=N; j++) G += GCD(j, i); // Accumulate the sum of GCD.
      
    printf("%d\n", G); // Output the result.
  }
  return 0;
}
