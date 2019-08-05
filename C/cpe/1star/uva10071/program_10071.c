// One-star problem
// Problem 10071 Back to High School Physics
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

// Notation, a: acceleration, t: time, v(t): velocity at time t, d(t): displacement at time t.
// Assume the initial velocity v(0) is 0.
// We have v(t) = a * t and d(t) = (1/2) * a * (t**2).
// Hence, a = v(t) / t and d(2t) = 2 * v(t) * t.
int main(void) {
  int v, t; // Variable v is v(t) the velocity at time t.
  
  while (scanf("%d %d", &v, &t)==2) { // Input velocity v(t) and time t until the end of file.
  	printf("%d\n", 2 * v * t); // Output displacement d(2t) at time 2t.
  }
  return 0;
}
