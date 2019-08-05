// One-star problem
// Problem 10908 Largest Square
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
  int M, N; // Size of the rectangle.
  char **Rectangle; // The array of the rectangle.
  int Q; // Number of queries.
  int r, c; // The coordinate of the selected point.
  int stencil; // Result of stencil test.  
  int i, j, k, u, v; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%d %d %d", &M, &N, &Q); // Input the size of rectangle and number of queries.
    // Allocate memory for the two dimenional array for the rectangle.
    Rectangle = (char **) malloc(M * sizeof(char *)); // Memory for array pointer.
    for (j=0; j<M; j++) {
      Rectangle[j] = (char *) malloc((N + 1) * sizeof(char)); // Memory for characters.
      scanf("%s", Rectangle[j]); // Input the contents of i-th row of the rectangle.
	}
	
	printf("%d %d %d\n", M, N, Q); // Echo the size of rectangle and number of queries.
	for (j=0; j<Q; j++) { // Processo all queries.
	  scanf("%d %d", &r, &c); // Input the query.
	  k = 1; // Stencil extension from center (r, c).
	  while (r-k>=0 && c-k>=0 && r+k<M && c+k<N) { // The stencil cannot pass the rectangle boarder.
	    stencil = 1; // Initially, set the stencil extension pass.
	    for (u=r-k; u<=r+k && stencil; u++) // Stencil range for extension k, row dirction.
	      for (v=c-k; v<=c+k && stencil; v++) // Stencil range for extension k, column dirction.
	        if (Rectangle[u][v]!=Rectangle[r][c]) stencil = 0; // Stencil point does not match.
	    if (stencil) k++; // The stencil extension pass, extend the area.
	    else break; // Stencil extension fail. Stop the loop. 
	  }
	  printf("%d\n", 2*(k-1)+1); // Output the stencil side. Vaule k is the extension fails.
	}
  }
  return 0;
}
