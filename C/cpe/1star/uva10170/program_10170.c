// One-star problem
// Problem 10170 The Hotel with Infinite Rooms
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

/* Initially, we have, group 0, S guests staying in the hotel for S days, G(0)=S. 
   For the group n we have G(n)=S+n guests staying in the hotel for S+n days. 
   Counting from day 1, group n will check out on day Sum(k=0, n)G(k) = Sum(k=0, n)(S+k) =
   (n+1)S+n(n+1)/2. Hence the problem is, given S and D, find the smallest n such that
   (n+1)S+n(n+1)/2>=D. Expand the inequality, we have n^2+(2S+1)n-2(D-S)>=0. Solving 
   the quadratic equation, let the positive root be n1=(-2*S-1+sqrt((2*S+1)^2+8*(D-S))/2.
   The solution is G(n1)=S+n, when n the ceiling of the positive root n1, ceil(n1).
*/
int main(void) {
  // Since the value of D is greater than 1 and less than 10^15, it could be larger than the 
  // maximum value of 32-bit unsigned long and we need to solve qudratic equation, we declar 
  // both N and D as the floating point number.
  
  float S, D; 
  while (scanf("%f %f", &S, &D)==2) { // Input N and D.
    printf("%d\n", (int) (S + ceil((-2 * S - 1 + sqrt(pow(2 *S + 1, 2) + 8 * (D - S))) / 2)));
  }
  return;
}
