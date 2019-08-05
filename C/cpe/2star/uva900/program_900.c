// Two-star problem
// Problem 900 Brick Wall Patterns
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

/* Let us name 1 brick placing the longer side in the vertical direction pattern V,
   and name 2 bricks placing the longer side in the horizontal dirction pattern H.
   1 unit: one wall pattern, i.e., V. Let the number of pattern be P(1)=1.
   2 units: two wall patterns, i.e., VV and H. Let the number of pattern be P(2)=2.
   For n units, we construct the wall patterns in two steps.
   Step 1: Place a brick in pattern V on the left-hand-side of all other n-1 bricks.
           The n-1 bricks have pattern number P(n-1).
   Step 2: Place two bricks in pattern H on the left-hand-side of all other n-2 bricks.
           The n-2 bricks have pattern number P(n-2).
   Since the patterns in Step 1 start from pattern V and the patterns in Step 2 start
   from pattern H, any two patterns, one from Step 1 and another one from Step 2 are
   not identical. Also, any two patterns from Step 1 or any two patterns from Step 2
   are not identical either. As a result, the number of patterns for n bricks P(n) is
   exactly P(n-2)+P(n-1). In fact, the sequence P(1), P(2), P(3), ..., P(n), ... is
   the Fibonacci sequence.
   
   The maximum value for the wall is length 50. Fibonacci P(50) is 20,365,011,074
   which is too large for 32-bit integers. We will use unsign long long to compute
   the Fibonacci numbers.
*/ 
int main(void) {
	
  int n; // Input number of bricks.
  // the last two terms and the term pattern for computing Fibonacci numbers.
  unsigned long long last1, last2, pattern ;
  int i; // Loop variable.
  
  while (1) { // Continue untial the input number is 0.
    scanf("%d", &n); // Input the number of bricks.
    
    if (n==0) break; // The number of bricks is 0, stop the loop and terminate the program.
    
    if (n==1) pattern = 1; // Fib(1).
    else if (n==2) pattern = 2; // Fib(2).
    else { // Computer Fibonacci number f(n) = f(n-2)+f(n-1). 
      last2 = 1; // Fib(1).
      last1 = 2; // Fib(2).
      for (i=3; i<=n; i++) {
      	pattern = last2 + last1;
      	last2 = last1;
      	last1 = pattern;
	  }
	}
	printf("%llu\n", pattern); // Output the number of patterns.
  }
  return 0;
}
