// One-star problem
// Problem UVA948 Fibonaccimal Base
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

// Maximum 40 Fibonacci numbers because fib(39)>100000000.
// The first stores the fibonacci number and the second is 1 or 0, 
// denoting whether that number is selected.
int fib[2][40];

// Genenrate Finbonacci sequence less than 100000000.
void generate_fib_sequence(void) {
  int i, count;
  
  fib[0][0] = 1;
  fib[0][1] = 1;
  for (i=2; ; i++) {
    fib[0][i] = fib[0][i-2] + fib[0][i-1];
    if (fib[0][i] > 100000000) break;
  }
}

// Find the largest Fibonacci number less than or equal to k.
int find_fib_index(int k) {
  int i;
  for (i=1; ; i++) {
    if (fib[0][i]<=k) fib[1][i] = 0; // Mark the base i as 0.
    else {
      fib[1][i-1] = 1; // Mark the base of the largest Fibonacci number less than or equal to k as 1.
      return i-1; // Return the index of the largest Fibonacci number less than or equal to k.
    }
  }
}

int main(void) {
  int cases, n;
  int fib_index_n, fib_index_current, remainder;
  int i, j;
  
  generate_fib_sequence(); // Generate Fibonacci number sequencee less than 100000000.
  
  scanf("%d", &cases); // Input the number of testing cases.
  for (i=0; i<cases; i++) { // Test all cases.
    scanf("%d", &n); // Input the testing integer.
    
    fib_index_n = find_fib_index(n); // Find the greatest Fibonacci number less than or equal to n. 
    remainder = n - fib[0][fib_index_n]; // Remainder to be converted to Fibonacci base digits.
    
    while (remainder>0) { // When remainder is not 0, continue to mark the digits.
      fib_index_current = find_fib_index(remainder); // Find the greatest Fibonacci number less than or equal to remainer. 
      remainder = remainder - fib[0][fib_index_current]; // Updata remainder.
    }
    
    printf("%d = ", n); // Print n.
    for (j=fib_index_n; j>0; j--) printf("%d", fib[1][j]); // Print the Finbonacci base digits.
    printf(" (fib)\n"); // Print "(fib)".
  }
  return 0;
} 
