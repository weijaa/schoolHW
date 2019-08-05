// One-star problem
// Problem 10235 Simply Emirp
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

// Return 1 if n is a prime number; otherwise, return 0.
int is_prime(int n) {
  int sqroot; // Square root of n.
  int i; // Loop variable.
  
  sqroot = sqrt(n); // Square root of n.
  for (i=2; i<=sqroot; i++) if (n%i==0) return 0; // We test prime only up to the square root of n.
  return 1; // If the loop is completed, n is a prime number.
}

// Reverse decimal number, e.g., convert d1d2d3 to d3d2d1.
int reverse_base_10(int n) {
  int result = 0;
  
  while (n!=0) { 
  	result = result * 10 + n % 10; // Put the least significant digit of n to result.
  	n = n / 10; // Shift the least digit of n to the right.
  }
  return result; // Return the result.
}

int main(void) {
  int n; // Testing integer.
  
  while (scanf("%d", &n)==1) // Input an integer, if there is any.
    if (!is_prime(n)) printf("%d is not prime.\n", n); // Input n is not a prime. 
    else if (!is_prime(reverse_base_10(n))) printf("%d is prime.\n", n); // Input n is a prime.
    else printf("%d is emirp.\n", n); // Input n is not an emirp.
    
  return 0;
}
