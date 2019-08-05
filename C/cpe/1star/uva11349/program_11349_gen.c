// One-star problem
// Problem 11349_gen Generating Center Symmetric Matrix
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
#include <time.h>

// This program generates center symmetric matrix. 
int main(void) {
  int n; // Size of square matrix.
  // -2^32<=M[i,j]<=2^32. Mmaximum 34 bits long, i.e., one sign bit and one 1-bit following 32 0-bit.
  long long M[100][100];
  char N;
  int symmetric; // 1: symmetric, 0: not symmetric.
  int t, i, j; // Loop variables.
  
  printf("Enter the size of square matrix: ");
  scanf("%d", &n); // Input the size of square matrix.
  
  srand(time(NULL)); // Seed of random number generator.
  
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) M[i][j] = 0; // Initial all matrix elements to 0.

  // Generate elements of symmetrix matrix, each time generate a pair of data.
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) if (M[i][j]==0) {M[i][j] = rand(); M[n-1-i][n-1-j] = M[i][j];}
    
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%lld ", M[i][j]); // Output matrix elements.
    printf("\n");
  }
  return 0;
}
