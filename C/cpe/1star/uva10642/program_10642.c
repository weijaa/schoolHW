// One-star problem
// Problem 10642 Can You Solve It?
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

/* This problem is similar to UVA264 Count on Cantor.
   Observe that we count the position of the circles along the ant-diagonal. The coordinate
   (x, y) is on the (x+y)-th anti-diagonal and at the y-th element from the lower-right corner
   of this diagonal. The first anti-diagonal has one element, the second anti-diagonal has 
   two elements, the third anti-diagonal has three elements, etc. These anti-diagonals form 
   an arithmetic progression sequence, 1, 2, 3, 4, .... That is, the k-th anti-diagonal 
   has k elements. The total number of circles in the first n anti-diagonals is n(n+1)/2.
   
   Hence, to find the position of point (x, y), let n=x+y, there are n(n+1)/2 points on 
   the first n anti-diagonals. Since the circles travel from the lower-left corner,
   the position of (x, y) is at the y-th element starting from the lower-right 
   corner of the (n+1)-st anti-diagonal.
   
   Note that the output solution given in the problem is the result for circles traveling
   from the upper-left corner downward. In this case point (x, y) is at the x-th element
   from the upper-right corner.  
   
   For two circles (x1, y1) and (x2, y2), we calculate their positions starting from the
   origin (0, 0), say, p1 and p2. Then the step(s) from (x1, y1) to (x2, y2) is |p1-p2|.
   
*/
int main(void) {
  int cases;
  int x1, y1, x2, y2;
  int p1, p2;
  int i;
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) { // Calculate all cases.
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2); // Input the points of two circles.
    
    // Calcualte the positions of p1 and p2.
    /* Note that the output solution given in the problem is the result for circles travel 
       from the upper-left corner downward. In this case point (x, y) is at the x-th element
       from the upper-right corner. However, the figure travels from lower-right upward. 
    */
    p1 = (x1 + y1) * (x1 + y1 + 1) / 2 + x1; // P1's position.
    p2 = (x2 + y2) * (x2 + y2 + 1) / 2 + x2; // P2's position.
    
    // Output the steps between circles (x1, y1) and (x2, y2).
    printf("Case %d: %d\n", i+1, abs(p1-p2)); 
  }
  return 0;
}
