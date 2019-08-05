// One-star problem
// Problem 10678 The Grazing Cow
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

/*
  The area is an ellipse. The major length is the rope length A=L and another major
  length is B=sqrt(L^2-D^2)/2. The area of the ellipse is A*B*PI.
*/
int main(void) {
  const double PI = 2*acos(0);
  int cases; // Number of cases.
  int D, L; // D: distance between two pillards; L: length of rope.
  int i; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) {
  	scanf("%d %d", &D, &L); // Input D: distance between two pillards; L: length of rope.
    // Output the area of the ellipse: A*B*PI.
  	printf("%5.3f\n", sqrt((double) L*L-(double) D*D) * L * PI / 4.0);
  }
  return 0;
}
