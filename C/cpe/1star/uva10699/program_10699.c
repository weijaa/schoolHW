// One-star problem
// Problem 10699 Count the Factors
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
  int n;
  int factor;
  int last_factor;
  int sqroot;
  int count;
  
  while (1) { // Continue until input a 0.
    scanf("%d", &n); // Input an integer.
    
    if (n==0) break; // When the input is 0, stop the loop and terminate the program.
    printf("%d : ", n); // Output the integer.
      
    count = 0; // Set the number of factors to 0.
    factor = 2; // Start from the smallest prime 2.
    last_factor = 1;
    sqroot = sqrt(n); // Square root of n.
    while (n>1) {
      if (n%factor==0) { // A factor is found.
      	if (last_factor!=factor) { // A new factor is found.
		  count++; // Increment the factor count.
		  last_factor = factor; // Update the last factor.
	    }
      	n = n / factor; // Test the quotient of n/factor.
	  }
	  else if (sqroot<factor+1) {
		count++; // n is a prime number.
		n = 1; // Set n to 1, i.e., n/n.
	  }
      else factor++; // Increment the factor. If factor is not a prime, n%factor cannot be 0.
	}
	printf ("%d\n", count); // Output the number of factor.
  }
  return 0;
}
