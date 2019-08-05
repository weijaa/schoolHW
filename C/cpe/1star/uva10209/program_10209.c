// One-star problem
// Problem 10209 Is This Integration?
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
#define epsilon 0.001 // Allowed error
#define pi 3.14159 
/*
  The solution is referenced to the proof proof_10209.pdf. We use Riemann Sum to compute the 
  integral of function f(x)=(a^2-x^2)1/2-a/2 which is the quarter area of region R1. 
*/

// a: the square side
// The fuction is f(x)=(a^2-x^2)1/2-a/2, lower bound is a/2, upper bound is sqrt(3)a/2.
float Riemann_sum(float a) {
  int T = 1;
  float lower=a/2, upper=sqrt(3)*a/2; // Initial lower bound and upper bound.
  float x, f, area=0, last, interval;
  int i;
  
  do {
    interval = (upper - lower) / T; // Compute the interval, dx.
    x = lower + interval / 2; // Compute mid-Riemann sum. The middle point of the first interval.
    last = area; 
    area = 0;
    for (i=0; i<T; i++) { // For T intervals, compute each area.
      f = sqrt(a * a - x * x)- a / 2; // Function value.
      area = area + fabs(f) * interval; // Sum up the area.
      x = x + interval; // The middle point of the next interval.
	}
	T = T * 2; // Expand the interval number to twice.
  } while (fabs(area-last)>=epsilon); // The area differnce of two consecutive runs is not small enough.
  return area; // This the area obtained.
}

int main(void) {
  float a; // Side of the square.
  float R1, R2, R3; // Area of the three regions.
  
  while (scanf("%f", &a)==1) { // Input the side of square, if there is any.
    R1 = Riemann_sum(a) * 4; // Area of R1.
    R2 = (pi - 2.0) * a * a - 2.0 * R1; // Area of R2.
    R3 = a * a - R1 - R2; // Area of R3.
    printf("%5.3f %5.3f %5.3f\n", R1, R2, R3); // Output area of the three regions.
  }
  return 0;
}
