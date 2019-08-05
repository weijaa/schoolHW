// One-star problem
// Problem 11342 Three-Square
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
  int cases; // Number of cases.
  int n; // Input integer n.
  int a, b, c; // a^2+b^2+c^2==n, if there is any.
  int found; // 1, if a , b, c are found; 0, otherwise.
  int r, i, j, k; // Loop variable.
  
  scanf("%d", &cases); // Input number of cases.
  
  for (r=0; r<cases; r++) { // Process all cases.
    scanf("%d", &n); // Input the integer n.
    
    found = 0;
    // The maximum value of possible c is (int)sqrt(n).    
    for (i=(int)sqrt(n); i>=0 && !found; i--) { // Cotinue to try if not found.
	  // The maximum value of possible b is (int)sqrt(n-i*i). 
	  for (j=(int)sqrt(n-i*i); j>=0 && !found; j--) { // Cotinue to try if not found.
	    k = (int) sqrt(n - i * i - j *j); // Possible a.
	    if (n== i * i + j * j + k * k) { // The three squares are found.
		  a = k;
		  b = j;
		  c = i;
		  found = 1;
		}		
	  }
	}
	if (found) printf("%d %d %d\n", a, b, c); // Found, output the three squares.
	else printf("-1\n"); // Not found, ouput -1.
  }
  return 0;
}
