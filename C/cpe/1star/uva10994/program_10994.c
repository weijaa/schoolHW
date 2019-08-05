// One-star problem
// Problem 10994 Simple Addition
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

int F(int n) {
  if (n%10>0) return n%10;
  else if (n==0) return 0;
  else return F(n/10);
}

// This is a brutal force solution which takes almost "forver" if we sum up F(1) to
// F(2147483647). 
int main(void) {
  int p, q; // Input pair of integers.
  long long S; // Sum S(p,q).
  int i; // Loop variable.

  while (1) { // Continue until two negative integers are input.
    scanf("%d %d", &p, &q);
    if (p<0 && q<0) break; // When two negative integers are input, stop the loop.
    S = 0; // Set sum to 0.
    for (i=p; i<=q; i++) S += (long long) F(i); // Accumulate the sum of F(i) from p to q.
    printf("%d\n", S);
  }
  return 0;
}
