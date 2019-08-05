// One-star problem
// Problem 10550 Combination Lock
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
  int d0, d1, d2, d3; // The orginal dial and the three dials of the combination.
  int dials;
  
  while (1) {
  	scanf("%d %d %d %d", &d0, &d1, &d2, &d3);
  	
  	if (d0==0 && d1==0 && d2==0 && d3==0) break; // Stop the loop and terminate, if all 0's are input.
  	
  	dials = 40 * 2; // Start with two full turns. Each turn is of 40 dials.
  	
  	if (d0>d1) dials += d0 - d1; // Clockwise from d0 to d1.
  	else dials += d0 + 40 - d1; // Clockwise from d0 to 0, and then to d1.
  	
  	dials += 40; // Turn the dial a full turn.
	
	if (d1<d2) dials += d2 - d1; // Counter-clockwise from d1 to d2.
	else dials += d2 + 40 - d1; // Counter-clockwise from d1 to 0, and then to d2.
	
	if (d2>d3) dials += d2 - d3; // Clockwise from d2 to d3;
	else dials += d2 + 40 -d3; // Clockwise from d2 to 0, and then to d3.
	
	printf("%d\n", dials * 9); // A turn has 40 dials and it is 360 degrees. Hence, a dial is of 9 degrees. 
  }
  return 0;
}
