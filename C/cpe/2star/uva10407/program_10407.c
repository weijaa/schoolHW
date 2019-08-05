// Two-star problem
// Problem 10407 Simple Division
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

/*
  If the elements of a sequence a1, a2, ..., and an have the same remainder, r, when divided by d,
  we must have a1=d*q1+r, a2=d*q2+r, ..., and an=d*qn+r. Hence, a1-a2=d*(q1-q2), a1-a3=*(q1-q3),
  ..., and a1-an=d*(a1-an). The divisor d is a common divisor of a1-a2, a1-a2, ..., a1-an. The
  solution is to compute the greatest common divisor of a1-a2, a1-a2, ..., a1-an.
*/

// Euclidean algorithm of computing greatest common divisor of two integer m and n.
int gcd(int m, int n) {
  if (m%n==0) return n; // Base case.
  else return gcd(n, m%n); // Recursive case.
}

int main(void) {
  int a1; // First element of the sequence.
  int next; // Next element in the sequence.
  int g; // The greatest common divisor of the input elements so fat.

  while (1) { // Continue if the first input integer is not zero.
    scanf("%d", &a1); // Input the first element of the sequence.
    if (a1==0) break; // If a1 is 0, stop the loop and terminate the program.
    
    g = 0; // Initial gcd to 0.
    
    while (1) { // Continue, if the next element is not zero.
      scanf("%d", &next); // Input the next element in the sequence.
      if (next==0) break; // If next is 0, this sequence is done, stop the inner loop.
      g = gcd(g, abs(a1 - next)); // Compute the gcd of a1-next and the gcd from the last element.
    }
    printf("%d\n", g); // Output the result.
  }  
  return 0;
}
