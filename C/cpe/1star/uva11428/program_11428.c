// One-star problem
// Problem 11428 Cubes
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
  int N; // Input integer.  
  int x, y; // The possible solution pair.
  unsigned x_cube, y_cube, difference; // x cube, y cube, and their difference.
  int found, stop; // Indicator whether the solution is found or the search is to stop.
  
  while (1) { // Continue until the input integer is 0.
  
    scanf("%d", &N); // Input an integer N.
    if (N==0) break; // If N is 0, stop the loop and terminate the program.
  
    found = 0; // Not found yet.
    stop = 0; // Continue to search.
  
    // Initial value of x and y.
    y = 1; // Start from the smallest possible value of y.
    x = (int) pow(N+1, 1.0/3.0); // Start from the smallest possible value of x.
    x_cube = x * x * x; // Calculate x cube.
    y_cube = 1; // y cube.
    do { // Repeat until a pair of integers are found or no solution is possible.
      difference = x_cube - y_cube; // Difference of x^3 to y^3.
      if (N==difference) found = 1; // If N equals to the differnece, the solution is found.
      else if (N<difference) { // When N is smaller than the difference.
      	if (x==y+1) stop = 1; // When x and y are two consecutive integers, no solution exists.
      	else { // otherwise,
		  y++; // Increment y.
		  y_cube = y * y * y; // Re-calculate y cube.
		}
	  }
	  else { // The x is not large enough.
	    y = 1; // Start from the smallest possible value of y.
	    x++; // Increment x.
        x_cube = x * x * x; // Re-calculate x cube.
        y_cube = 1; // y cube.
	  }      
    } while (!found && !stop); // Continue if neither found nor stopped.
    
    if (found) printf("%d %d\n", x, y); // Output the solution x and y.
    else printf("No solution\n"); // Output no solution message.
  }
  return 0;
}
