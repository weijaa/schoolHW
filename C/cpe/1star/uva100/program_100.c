// One-star problem
// Problem UVA100 The 3n+1 Problem
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

  int i, j, low, high;
  int n, elem, cycle_length, max_length;
  
  while (scanf("%d %d", &i, &j)==2) { // Input two integers i and j.
    if (i>j) {low = j; high = i;} else {low = i; high = j;} // Set low and high boundaries..
    max_length= 0; // Set the maximum cycle length to zero.
    for (elem=low; elem<=high; elem++) { // for all elements betwen low and high find the cycle length. 
      n = elem; // Initial value is n.
      cycle_length = 1; // The cycle_length is intialized to 1.
      while (n!=1) { // When the element is 1, stop.
        if (n%2==1) {n = 3 * n + 1; cycle_length++;} // When n is odd, set it to 3n+1; increment cycle_length.
        else {n = n / 2; cycle_length++;} // When n is even, divided n by 2; increment cycle_length.
      }
      if (cycle_length>max_length) max_length = cycle_length; // Update max_length, if this cycle length is greater than max_length.
    }
    printf("%d %d %d\n", i, j, max_length); // Output i, j, and the maximum cycle length.
  }
  return 0;
} 
