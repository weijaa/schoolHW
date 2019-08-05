// One-star problem
// Problem 10573 Geometry Paradox
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
#define pi 3.14159

/*
  If r1 and r2 are given, then the radius of the outer circle is r1+r2. Therefore, the area
  of the gray color is ((r1+r2)^2-r1^2-r2^2)*pi=2*r1*r2*pi.
  
  If the length of the tangent line t is given, the area of the gray color is (t^2*pi)/8.
*/
int main(void) {
  int cases; // Number of cases.
  int r1, r2; // Radius of two inner circles.
  int t;  // Length of the tangent line.
  char c; // A character to test space or newline.
  int i; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%d", &t); // Input an integer and store it in t.
    
    scanf("%c", &c); // Input a character. Assume no extra spaces are allowed in the input data.
    if (c==' ') { // A space is detected. This line has two integers.
      r1 = t;
      scanf("%d", &r2);
      printf("%6.4f\n", (float) 2.0*r1*r2*pi); // Area of the shaded gray color.
    }
    else { // This line has one integer only.
      printf("%6.4f\n", (float) t*t*pi/8); // Area of the shaded gray color.
	}
  }
  return 0;
}
