// Two-star problem
// Problem 256 Quirksome Squares
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

// For a 32-bit CPU, the maximum integer is 2,147,483,647, not 32,767 as mentioned in
// the problem.
int main(void) {
  int n; // Number of digits, from 2, 4, 6, or 8.
  int quirk; // Possible quirk number.
  int halfway; // Half way  of 10^n, i.e, 10^(n/2).
  int sum; // Sum of the lower half and high half of the qurik.
  int leading_0; // The number leading zeros.
  int i; // Loop variable.
  
  while (scanf("%d", &n)==1) { // Input number of digits if there is any.
    quirk = 0;
    halfway = pow(10, n / 2);
    // Continue, if number of digits of quirk is less than n.
    while (quirk<halfway*halfway) {
      // Sum of the lower half and high half of the qurik.	
	  sum = quirk % halfway + quirk / halfway; 
//printf("**** n=%d, halfway=%d, quirk=%d, sum=%d\n", n, halfway, quirk, sum);
	
	  if (quirk==sum*sum) { // If it is a quirk, output the quriksome number.
        if (quirk<=1) leading_0 = n - 1; // If qurik==0 or 1, n-1 leading zeros.
        // (int) log10(quirk) is 1 less than number of digits.
	    else  leading_0 = n - (int) log10(quirk) - 1; 
	    for (i=0; i<leading_0; i++) printf("0"); // Output leading zeros.
	    printf("%d\n", quirk); // Print the quirksome number.
      }
      quirk = pow(sqrt(quirk)+1, 2); // Get the next possible quirk.
    }
  }
  return 0;
}
