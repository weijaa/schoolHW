// One-star problem
// Problem 10215 The Largest/Smallest Box ...
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
  float length, width;
  float x;
  float min, max, volume;
  float x_min, x_max;
  
  while (scanf("%f %f", &length, &width)==2) { // Input the length and width of the card.
    x = 0.0001; // Set the initial value of x to be 0.0001.
    min = x * (length - 2 * x) * (width - 2 * x); // Compute the intial volume and set it to minimum
    max = min; // and maximum value.
    while (length-2*x>0.0 && width-2*x>0.0) { // While the length and the width can be cut 2x, continue.
      volume = x * (length - 2 * x) * (width - 2 * x); // Compute the current volume.
      if (min>volume) {min = volume; x_min = x;} // Update minimum volume and x make the volume minimum.
      if (max<volume) {max = volume; x_max = x;} // Update maximum volume and x make the volume maximum.
      x = x + 0.0001; // The incremental is 0.0001. Increment x.
	}
	printf("%5.3f 0.000 %5.3f\n", x_max, x_min); // Output the result. "0.000" is here as the given solution.
  }
  return 0;
}
