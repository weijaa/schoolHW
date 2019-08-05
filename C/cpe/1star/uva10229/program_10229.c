// One-star problem
// Problem 10229 Modular Fibonacci
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

// We use the property a%c+b%c=(a+b)%c to solve this problem. 
int main(void) {
  unsigned n, m; // Input data.
  unsigned power_of_2; // The power of 2, 2^m.
  unsigned fib, curr, last; //fib(n), fib(n-1), fib(n-2), respectively.
  int i; // loop variable.

  while (scanf("%d %d", &n, &m)==2) { // Input two integers.
  	power_of_2 = pow(2, m); // Compute 2^m.
	
	if (n==0) printf("0\n"); // fib(0).
	else if (n==1) printf("1\n"); // fib(1).
	else { // Compute fib(n), for n>0.
	  last = 0;
	  curr = 1;
	  for (i=2; i<=n; i++) {
	  	fib = (last + curr) % power_of_2; // Use the property a%c+b%c=(a+b)%c.
	  	last = curr;
	  	curr = fib;	  	
	  }
	  printf("%d\n", fib); // Output fib(n) % (2^m).
	}
  }
  return 0;
}
