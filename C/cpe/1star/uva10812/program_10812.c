// One-star problem
// Problem 10812 Beat the Spread!
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
  int cases; // Number of cases.
  int sum, diff; // Sum and difference of the two scores.
  int i; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
  	scanf("%d %d", &sum, &diff); // Input sum and difference of the two scores.
  	
  	if (sum<diff || (sum+diff)%2==1) // Sum must be greater than or equal to diff and sum_diff must be even.
  	  printf("impossible\n");
  	else printf("%d %d\n", (sum+diff)/2, (sum-diff)/2); // high=(sum+diff)/2, low=(sum-diff)/2.
  }
  return 0;
}
