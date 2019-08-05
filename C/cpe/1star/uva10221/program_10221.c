// One-star problem
// Problem 10221 Satellites
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
#include <string.h>
#include <math.h>

// 1 pi = 180 degrees; 1 degree = 60 minutes.
// Convert degree to radian, d degree = (d/180)*pi radian.
// Convert minute to radian, m minutes = (m/(60*180))*pi radian.
// The solution: arc = r*a and chord = 2r sin(a/2),
// where r is the radius, i.e., the distance from the center of earth center, a is the angle in radian.
int main(void) {
  double distance, angle; // Distance and angle. 
  char unit[4]; // Unit: "min" for minute or "deg" for degree.
  
  while (scanf("%lf %lf %s", &distance, &angle, &unit)==3) { // Input distance from earth surface, angle, and unit.
  	distance = distance + 6440.0; // The earth radius is 6440 KM, the distance is from the earth center. 
  	if (strcmp(unit,"deg")==0)
  	  printf("%8.6lf %8.6lf\n", distance * (angle / 180.0) * 3.14159, // Arc length in degree
		     2 * distance *sin((angle / 180.0) * 3.14159 / 2.0)); // Chord length in degree
  	if (strcmp(unit,"min")==0)
  	  printf("%8.6lf %8.6lf\n", distance * (angle / (180.0 * 60)) * 3.14159, // Arc length in minute
		      2 * distance * sin((angle / (180.0 * 60)) * 3.14159 / 2.0)); // Chord length in minute
  }
  return 0;
}
