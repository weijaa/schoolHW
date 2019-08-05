// One-star problem
// Problem 11349 Symmetric Matrix
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
  int T; // Number of cases.
  int n; // Size of square matrix.
  // -2^32<=M[i,j]<=2^32. Mmaximum 34 bits long, i.e., one sign bit and one 1-bit following 32 0-bit.
  long long M[100][100];
  char N;
  int symmetric; // 1: symmetric, 0: not symmetric.
  int t, i, j; // Loop variables.
  
  scanf("%d", &T); // Input number of cases.
  
  for (t=0; t<T; t++) { // Process all cases.
    do {
      scanf("%c", &N); // Search for character 'N'.
	} while (N!='N');
    scanf("%c%c%c%d", &N, &N, &N, &n); // Skip " = ", and then input the size of square matrix.
    for (i=0; i<n; i++)
      for (j=0; j<n; j++) scanf("%lld", &M[i][j]); // Input matrix elements.
    
    symmetric = 1;
    // Center symmetric matrix is symmetric with relation to the center.
    // If M is a center symmetrix matrix, then M[i][j] must equal to M[n-1-i][n-1-j].
    for (i=0; i<n && symmetric; i++) // Check all row.
      for (j=0; j<n && symmetric; j++)  // Check all elements in row i.
        if (M[i][j]!=M[n-1-i][n-1-j]) symmetric = 0; // This pair of elements are not symmetric.
        
    if (symmetric) printf("Test #%d: Symmetric.\n", t+1); // Symmetric, output the result.
    else printf("Test #%d: Non-symmetric.\n", t+1); // Not symmetric, output the result.
  }
  return 0;
}
