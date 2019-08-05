// One-star problem
// Problem UVA299 Train Swapping
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

/* We use the insertion sort algorithm to solve this problem.
   When two neighboring elements are out of order, the compare and swap operation is performed
   and the swap count is incremented by one.
*/ 
int main(void) {
  int n, test, trial, count;
  int carriage[50];
  int i, j, temp;
  
  scanf("%d", &test); // Input the number of testing cases.
  
  for (trial=0; trial<test; trial++) { // Do all testing cases.
    count = 0; // Set the swap count to 0.
    scanf("%d", &n); // Input the number of elements in this testing case.
    for (i=0; i<n; i++) scanf("%d", &carriage[i]); // Input the sequence of data in this testing case.
    
    // Insertion sort algorithm
    for (i=n-1; i>0; i--) // i is the segment length.
      for (j=1; j<=i; j++) { // Compare and swap two neighboring elements in the segment from left to right.
        if (carriage[j-1]>carriage[j]) { // Is the two neighboring element out of order?
          count++; // Increment swap count by 1.
          temp = carriage[j-1]; // Perform the swap operation.
          carriage[j-1] = carriage[j];
          carriage[j] = temp;
        }
      }
    printf("Optimal train swapping takes %d swaps.\n", count); // Output the result.
  }
  return 0;
} 
