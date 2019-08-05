// Two-star problem
// Problem 10167 Birthday Cake
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
#define pi 3.14159

// A new type for a cherry on the point of coordinate (x, y). Also, we record the angle of the
// polar coordinate which is atan(y/x) (arc tangent) for cherries in the first and second quadrants
// and pi+atan(y/x) for the cherries in the third and fourth quadrants.
typedef struct {
  int x; // x coordinate.
  int y; // y coordinate.
  double a; // Angle of polar coordinate, in degrees.
} Cherry;

// Euclidean algorithm to compute the great common divisor of m and n.
int gcd(int m, int n) {
  if (m%n==0) return n;
  else gcd(n, m%n);
}

int main(void) {
  int n; // Input integer, 2n is the number of cherries, i.e., the number of points.
  Cherry cherry[100]; // Maximum 100 cherries.
  int x_temp, y_temp; // Temporary cherry coordinate for swap operation.
  double a_temp; // Temporary angle for swap operation.
  int s; // The cherry selected to draw the beeline.
  int A, B; // Coefficients of the linear equation, Ax+By=0.
  double a; // Angle atan(B/A) for searching A and B.
  int found; // The beeline is found.
  int g; // GCD of A and B.
  int i, j; // Loop variable.
  
  while (1) { // Continue until input n is 0.
    scanf("%d", &n); // Number of cherries is 2n.
    
    if (n==0) break; // If n is 0, stop the loop and terminate the program.
    
    // Input the cherries and calculate the degrees of the points.
    for (i=0; i<2*n; i++) {
      scanf("%d %d", &cherry[i].x, &cherry[i].y);
      if (cherry[i].x==0) { // The cherry is on the y axis.
        if (cherry[i].y>0) cherry[i].a = 90.0; // The cherry is on the positive Y axis, a==90 degrees.
		else if (cherry[i].y<0) cherry[i].a = 270.0; // The cherry is on the negative Y axis, a==270 degrees.
      }
	  else if (cherry[i].y==0) { // The cherry is on the X axis.
        if (cherry[i].x>0) cherry[i].a = 0.0; // The cherry is on the positive X axis, a==0 degrees.
		else if (cherry[i].x<0) cherry[i].a = 180.0; // The cherry is on the negative X axis, a==180 degrees.
      }
      // For a cherry is neither on the x axis nor on the y axis, compute arc tan(y/x) and adjust its
      // quadrant to obtain the angle a in degrees.
	  else if (cherry[i].x>0 && cherry[i].y>0) // The cherry is on the first quadrant.
	          cherry[i].a = atan(((double) cherry[i].y) / ((double) cherry[i].x)) * 180.0 / pi;
	  else if (cherry[i].x<0 && cherry[i].y>0) // The cherry is on the second quadrant.
	          cherry[i].a = (pi + atan(((double) cherry[i].y) / ((double) cherry[i].x))) * 180.0 / pi; 
	  else if (cherry[i].x<0 && cherry[i].y<0) // The cherry is on the third quadrant.
	          cherry[i].a = (pi + atan(((double) cherry[i].y) / ((double) cherry[i].x))) * 180.0 / pi; 
	  else if (cherry[i].x>0 && cherry[i].y<0) // The cherry is on the fourth quadrant.
	          cherry[i].a = (2 * pi + atan(((double) cherry[i].y) / ((double) cherry[i].x))) * 180.0 / pi; 
	}
	  
	// Sort the points in the ascending order of the angles.
	// No two cherries are on the beeline. That is, no two cheeries have the same angle.
	for (i=2*n-1; i>0; i--)
	  for (j=1; j<=i; j++)
	  	if (cherry[j-1].a>cherry[j].a) { // If the angles of two neighboring cherries are out of order,
	  	  x_temp = cherry[j-1].x; // swap the two cherries.
	  	  y_temp = cherry[j-1].y;
	  	  a_temp = cherry[j-1].a;
	  	  cherry[j-1].x = cherry[j].x;
	  	  cherry[j-1].y = cherry[j].y;
	  	  cherry[j-1].a = cherry[j].a;
	  	  cherry[j].x = x_temp;
	  	  cherry[j].y = y_temp;
	  	  cherry[j].a = a_temp;
		}

    // Select the first cherry (i) such that the next n cherries starting from (including i) are 
    // within 180 degrees. Also, if there are cherries on the positive X axis, start from the next
    // cherry not on the X axis.
	s = -1;
	for (i=0; i<n && s==-1; i++) {
	  while (cherry[i].a==0) i++; // Move to the next cherry, if cherry i is on the X axis,
	  if ((cherry[i+n-1].a-cherry[i].a<180) &&  // N cheeries starting from i are within 180 degrees.
	      // The other n cherries must be also within 180 degrees.
	      ((i==0 && cherry[2*n-1].a-cherry[n].a<180) || // The other cherries are n to 2n-1.
		   (i>0 && 2*pi-cherry[i+n].a+cherry[i-1].a<180))) // Some of other cherries are 0 to -1.
	  	s = i; // Selected point i. 
	}
    A = -501; B = -501; // Initialize A and B to the excluded value.
	// First, coisder two trival cases the X axis and the Y axis. All cherries
	// from 0 to n-1 are in the 1st and 2nd quadrants and all cherries n to 2n-1
	// are in the 3rd and 4th quadrants, the X axis is the solution.
	if (cherry[0].y>0.0 && cherry[n-1].y>0.0 && cherry[n].y<0.0 && cherry[2*n-1].y<0.0) {
	  A = 0; B = 1;} // Line y=0, the X axis.
	// All cherries from s to s+n-1 are in the 2nd and 3rd quadrants and all cherries s-1 to 
	// s+n are in the 1st and 4th quadrants, the Y axis is the solution.
	else if (cherry[s].x<0.0 && cherry[s+n-1].x<0.0 && cherry[s-1].x>0.0 && cherry[s+n].x>0.0) {
	  A = 1; B = 0;} // Line x=0, the Y axis.
	// For the other cases, the beeline must lie between cherries s and s-1 (mod 2n)
	// and cherries s+n-1 and s+n.
	// The beeline is the line Ax+BY=0, where (A, B) is defined as (1) (500, i),
	// i from 1 to 500, (2) (i, 500), i from 499 to 1, (3) (i, 500), i from -1
	// down to -500, and (4) (-500, i) i from 499 down to 1. The test is to
	// check if atan(B/A) is "between" angles of cherry s and s-1 (mod 2n) and 
	// angles of cherry s+n-1 and s+n. Angles in "between" are analyzed in the
	// following cases.
	else {
	  found = 0; // The beeline is not found.
	  // Case 1: 0<a<=45 degrees.
	  for (i=1; i<=500 && !found; i++) {
	  	a = atan(i / 500.0) * 180.0 / pi; // Calculate the angle of the beeline.
	  	// Selected cherry is the first cherry.
		// The beeline is between cherry 0 and 2*n-1 and between n-1 and n.
		if (s==0) {
		  if (cherry[n-1].a<180.0) {
		    if (cherry[n-1].a<a && a<cherry[n].a && cherry[2*n-1].a<a+180.0) {
		      A = 500; // Find values of A and B; set found to 1.
		      B = i;
			  found = 1;
			}
		  }
		  else {
		    if (a<cherry[0].a && cherry[n-1].a<a+180.0 && a+180.0<cherry[n].a) {
		      A = 500; // Find values of A and B; set found to 1.
		      B = i;
			  found = 1;
			}
		  }
		}
	  	// Selected cherry is not the first cherry.
		// The beeline is between cherry s-1 and s and between s+n-1 and s+n.
		else if (s>0 && 
		         cherry[s-1].a<a && a<cherry[s].a && 
				 cherry[s+n-1].a<a+180.0 && a+180.0<cherry[s+n].a) {
		  A = 500; // Find values of A and B; set found to 1.
		  B = i;
		  found = 1;
		}
	  }

	  // Case 2: 45<a<90 degrees.
	  for (i=499; i>=1 && !found; i--) { //
	  	a = atan(500.0/i) * 180.0 / pi; // Calculate the angle of the beeline.
	  	// Selected cherry is the first cherry.
		// The beeline is between cherry 0 and 2*n-1 and between n-1 and n.
		if (s==0) {
		  if (cherry[n-1].a<180.0) {
		    if (cherry[n-1].a<a && a<cherry[n].a && cherry[2*n-1].a<a+180.0) {
		      A = i; // Find values of A and B; set found to 1.
		      B = 500;
			  found = 1;
			}
		  }
		  else {
		    if (a<cherry[0].a && cherry[n-1].a<a+180.0 && a+180.0<cherry[n].a) {
		      A = i; // Find values of A and B; set found to 1.
		      B = 500;
			  found = 1;
			}
		  }
		}
	  	// Selected cherry is not the first cherry.
		// The beeline is between cherry s-1 and s and between s+n-1 and s+n.
		else if (s>0 && 
		         cherry[s-1].a<a && a<cherry[s].a && 
				 cherry[s+n-1].a<a+180.0 && a+180.0<cherry[s+n].a) {
		  A = i; // Find values of A and B; set found to 1.
		  B = 500;
		  found = 1;
		}
 	  }

	  // Case 3: 180<a<=135 degrees.
	  for (i=-1; i>=-500 && !found; i--) { //
	  	a = (atan(500.0/i) * 180.0) / pi + 180.0; // Calculate the angle of the beeline.
	  	// Selected cherry is the first cherry.
		// The beeline is between cherry 0 and 2*n-1 and between n-1 and n.
		if (s==0) {
		  if (cherry[n-1].a<180.0) {
		    if (cherry[n-1].a<a && a<cherry[n].a && cherry[2*n-1].a<a+180.0) {
		      A = -500; // Find values of A and B; set found to 1.
		      B = -i;
			  found = 1;
			}
		  }
		  else {
		    if (a<cherry[0].a && cherry[n-1].a<a+180.0 && a+180.0<cherry[n].a) {
		      A = -500; // Find values of A and B; set found to 1.
		      B = -i;
			  found = 1;
			}
		  }
		}
	  	// Selected cherry is not the first cherry.
		// The beeline is between cherry s-1 and s and between s+n-1 and s+n.
		else if (s>0 && 
		         cherry[s-1].a<a && a<cherry[s].a && 
				 cherry[s+n-1].a<a+180.0 && a+180.0<cherry[s+n].a) {
		  A = -500; // Find values of A and B; set found to 1.
		  B = -i;
		  found = 1;
		}
 	  }
	  // Case 4:  135<a<180 degrees.
	  for (i=499; i>=1 && !found; i--) { //
	  	a = (atan(i/-500.0) * 180.0) / pi + 180.0; // Calculate the angle of the beeline.
	  	// Selected cherry is the first cherry.
		// The beeline is between cherry 0 and 2*n-1 and between n-1 and n.
		if (s==0) {
		  if (cherry[n-1].a<180.0) {
		    if (cherry[n-1].a<a && a<cherry[n].a && cherry[2*n-1].a<a+180.0) {
		      A = -i; // Find values of A and B; set found to 1.
		      B = 500;
			  found = 1;
			}
		  }
		  else {
		    if (a<cherry[0].a && cherry[n-1].a<a+180.0 && a+180.0<cherry[n].a) {
		      A = -i; // Find values of A and B; set found to 1.
		      B = 500;
			  found = 1;
			}
		  }
		}
	  	// Selected cherry is not the first cherry.
		// The beeline is between cherry s-1 and s and between s+n-1 and s+n.
		else if (s>0 && 
		         cherry[s-1].a<a && a<cherry[s].a && 
				 cherry[s+n-1].a<a+180.0 && a+180.0<cherry[s+n].a) {
		  A = -i; // Find values of A and B; set found to 1.
		  B = 500;
		  found = 1;
		}
 	  }
	}
	
	// Simplify A and B, i.e., make A and B relatively prime.
	if (A!=0 && B!=0) {
	  g = gcd(abs(A), abs(B));
	  A = A / g;
	  B = B / g;
	}
	printf("%d %d\n", A, B);
  }
  return 0;
}
