// One-star problem
// Problem 10242 Fourth Point!!
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
#define epsilon 0.001

/* The slope of (x1, y1) and (x4, y4) is the same as the slope of (x2, y2) and (x3, y3).
   Hecne, we have slope=(y4-y1)/(x4-x1)=(y3-y2)/(x3-x2), i.e., (y4-y1)=slope(x4-x1).
   
   The distance between (x1, y1) and (x4, y4) equals to the distance between (x2, y2) and (x3, y3).
   distance=(x4-x1)^2+(y4-y1)^2=(x3-x2)^2+(y3-y2)^2, i.e., (x4-x1)^2+slope^2 * (x4-x1)^2 = distance.
   Hence, (x4-x1)^2=distance/(1+slope^2). That x4=x1+sqrt(distance/(1+slope^2)) or 
   x4=x1-sqrt(distance/(1+slope^2)). We choose the solution satisfying x4-x1==x3-x2.
   
   We will use substitution to solve (x4, y4). 
*/
int main(void) {
  float x1, y1, x2, y2, x3, y3, x4, y4;
  float slope, distance;
  float y4_minus_y1;
  float x4_1, x4_2;
  
  // For each case, read coordinates of the first three points. Note that (x2, y2) repeats twice.
  while (scanf("%f %f %f %f %f %f %f %f ", &x1, &y1, &x2, &y2, &x2, &y2, &x3, &y3)==8) {
  	slope = (y3 -y2 ) / (x3 - x2); // Compute the slope of (x2, y2) and (x3, y3).
  	distance = pow(x3 - x2, 2) + pow(y3 - y2, 2);  // Compute the distance between (x2, y2) and (x3, y3).
  	x4_1 = x1 + sqrt(distance/(1 + pow(slope, 2))); // X4 has two possible cases, case 1,
  	x4_2 = x1 - sqrt(distance/(1 + pow(slope, 2))); // case 2.
  	// We consider the error allowance 0.001 caused by floating precision.
  	if (fabs((x4_1-x1)-(x3-x2))<epsilon) x4 = x4_1; // Select x4. 
  	else x4 = x4_2; 
  	y4 = slope * (x4 - x1) + y1; // Compute y4.
  	
  	printf("%5.3f %5.3f\n", x4, y4); // Output the fourth point coordinate.
  }
  return 0;
}
