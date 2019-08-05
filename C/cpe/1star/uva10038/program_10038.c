// One-star problem
// Problem 10038 Jolly Jumpers
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
  int data[3000], difference[3000];
  int length, temp;
  int i, j;
  
  while (scanf("%d", &length)==1) { // Input the length of the number sequence, if there is any.
  	for (i=0; i<length; i++) scanf("%d", &data[i]); // Input the sequence elements.
  	for (i=1; i<length; i++) difference[i] = abs(data[i-1] - data[i]); // Compute the difference of two neighboring sequence elements.
  	
  	// Sort the difference sequence, not including difference[0], in ascending order.
  	for (i=length-1; i>1; i--)
  	  for (j=2; j<=i; j++) {
  	    if (difference[j-1]>difference[j]) {
  	      temp = difference[j-1];
  	      difference[j-1] = difference[j];
  	      difference[j] = temp;
		}
	  }
	
	for (i=1; i<length; i++) if (difference[i]!=i) break; // Check if the sorted difference is 1, 2, 3, ....
	if (i==length) printf("Jolly\n"); // If the check passes through all difference elements, it is a jolly seqence,
	else printf("Not jolly\n");  // otherwise, it is not.
  }
  return 0;
}
