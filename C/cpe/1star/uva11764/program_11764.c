// One-star problem
// Problem 11764 Jumping Mario
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
  int high, low; // Number of high jumps and low jumps.
  int wall; // The number of walls.
  int curr; // The height of wall Mario stays currently.
  int next; // The height of the next wall.
  int i, j; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%d", &wall); // Input the number of walls.
    scanf("%d", &curr); // Input the height of the first wall. This is the current wall.
    // Clear the number of high jumps and low jumps.
    high = 0;
    low = 0;
    
    for (j=1; j<wall; j++) { // Jump to all other walls.
      scanf("%d", &next); // The height of the next wall.
      if (next>curr) high++; // Add 1 to high jump.
	  else if (next<curr) low++; // Add 1 to low jump.
	  
	  curr = next; // The next wall becomes the current wall of the next jump.    	
	}
	
	printf("Case %d: %d %d\n", i+1, high, low); // Output the case number and high/low jumps.
  }
  return 0;
}
