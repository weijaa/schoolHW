// One-star problem
// Problem 11470 Square Sums
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
  int n; // Input integer, side of the square.
  int square[10][10]; // Elements of the square, maximum size 10 by 10.
  int sum[5]; // The sum of concentric squares, maximum 5 squares.
  int low, high; // low index and high index.
  int c = 1; // Case index.
  int i, j; // Loop variables.
  
  while (1) { // Continue until the input side of the square is 0.
    scanf("%d", &n); // Input the side of the square.
    
    if (n==0) break; // The side of the square is 0, stop the loop and terminate the program.
    
    for (i=0; i<n; i++)
      for (j=0; j<n; j++) scanf("%d", &square[i][j]); // Input the square elements.
      
    low = 0; // Starting index of the first row and the first column.
    high = n - 1; // Finishing index of the last row and the last column.
    
    while (low<=high) { // The square is not empty.
      sum[low] = 0; // Initial squre sum to 0.
      // Sum up the elements of the two horizontal sides.
      for (i=low; i<=high; i++)
      	sum[low] += square[low][i] + square[high][i];
      // Sum up the elements of the two vertical sides.
      for (i=low+1; i<=high-1; i++)
      	sum[low] += square[i][low] + square[i][high];

      // If the side of the square is 1, it is counted twice. The sum should be halfed.
      if (low==high) sum[low] = sum[low] / 2;
      low++; // Update the low index.
      high--; // Update the high index.
	}
	printf("Case %d:", c++); // Output the case number.
	for (i=0; i<n/2+n%2; i++) printf(" %d", sum[i]); // Output the square sums.
	printf("\n"); // Output a newline.
  }
  return 0;
}
