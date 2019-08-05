// Two-star problem
// Problem 10200 Prime Time
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

// Determine whether n is a prime or not.
// Return 1 if n is a prime; otherwise, 0.
// In this problem n must be an odd number. 
int is_prime(int n) {
  int sqroot = (int) sqrt(n); // Square root of an integer.
  int i; // Loop variable.
  
  // If n has a factor between 3 and sqroot, return 0.
  for (i=3; i<=sqroot; i=i+2) if (n%i==0) return 0; 
  return 1; // Otherwise, return 1.
}


int main(void) {
  int a, b; // Intput integer pairs.
  int prime_count;
  int n; // Loop variable.
  
  // Continue, if there is a pair of integers in stdin.
  while (scanf("%d %d", &a, &b)==2) {
  	prime_count = 0; // Reset prime counter to 0.
  	// For n that a<=n<=b, if n^2+n+41 is a prime, increment the prime counter.
  	for (n=a; n<=b; n++) if (is_prime(n * n + n + 41)) prime_count++;
  	// Output the result percentage.
  	printf("%4.2f\n", prime_count * 100.0 / ( b - a + 1));
  }
  return 0;
}
