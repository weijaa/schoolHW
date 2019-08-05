// One-star problem
// Problem 11728 Alternate Task
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

int main(void) {
  int S; // Input integer.
  int sum; // Sum of factors.
  int found; // 1: exists a number its factor sum equal to S; 0: otherwise.
  int c = 1; // Case index.
  int i, j; // Loop variable.
  
  while (1) { // Continue until the input integer is 0.
    scanf("%d", &S); // Input an integer.
    
    if (S==0) break; // If the input integer is 0, stop the loop and terminate the program.
    
    found = 0; // Not found yet.
  	for (i=S; i>=1 && !found; i--) { // Search start from S backward to 1.
  	  sum = 0; // Initial the factor sum to 0.
	  for (j=1; j<=i; j++) if (i%j==0) sum += j; // Sum up all factors of i.
  	  if (S==sum) { // Find an i whose factor sum equal to S.
        printf("Case %d: %d\n", c++, i); // Output the result.
    	found = 1; // An answer is found.
	  }
	}
	if (!found) printf("Case %d: -1\n", c++); // Output not found.
  }
  return 0;
}
