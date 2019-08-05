// One-star problem
// Problem 10310 Dog and Gopher
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

typedef struct {
  float x;
  float y;
} Point; // X and Y coordinate of a location for gopher, dog, or hole.

int main(void) {

  Point gopher, dog, hole; // coordinates of gopher, dog, and hole.
  int count; // Number of holes.
  int safe_hole; // Indicate a safe home is found.
  int i; // Loop variable.
  
  while (scanf("%d", &count)==1) { // Input number of holes for the next case, if any.
    scanf("%f %f %f %f", &gopher.x, &gopher.y, &dog.x, &dog.y); // Input gopher's and dog's position.
    
    safe_hole = 0; // No safe hole has been found.
    for (i=0; i<count; i++) {
      scanf("%f %f", &hole.x, &hole.y); // Input coordinate of a hole.
      if (!safe_hole) // If no safe hole is found.
        if (sqrt(pow(gopher.x-hole.x, 2)+pow(gopher.y-hole.y, 2))< // Distance between gopher and hole.
	        sqrt(pow(dog.x-hole.x, 2)+pow(dog.y-hole.y, 2))/2) { // Half distance between dog and hole.
	      printf("The gopher can escape through the hole at (%4.2f, %4.2f).\n",
		        hole.x, hole.y); // The gopher escapes.
		  safe_hole = 1; // A safe hole is found. (Don't break the loop. Need to drain rest of holes.)
	    }
    }
    if (!safe_hole) // If no safe hole has been found.
      printf("The gopher cannot escape.\n"); // The gopher is caught.
  }
  return 0;
}
