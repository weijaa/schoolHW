// Two-star problem
// Problem 10104 Euclid Problem
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

/* 
  If A, B, and D are known values, AX+BY=D is a two-variable linear Diophantine equation.
  A linear Diophantine equation has a solution if and only if gcd(A, B) divides D. Hence,
  in order to find the solution X and Y such |X|+|Y| has the smallest value, D must equal to
  gcd(A, B). They msut exist a pair of integers X and Y such that AX+BY=D, where D=gcd(A,B).
  
  The following code is an iterative version of Euclidean Algorithm to compute gcd (A, B), where
  Q denotes quotient, R denotes remainder, and Q[0] is intialized to 0.
  
  	R[0] = A;
	R[1] = B; 
	Q[0] = 0;
  	i = 1;
  	while (R[i-1]%R[i]!=0) {
  	  Q[i] = R[i-1] / R[i];
	  R[i+1] = R[i-1] % R[i];
	  i++;
	}
	gcd = R[i];
	
  The following code will expand gcd to the linear form of A and B (i==4):
    X= 1;
	Y = -1 * Q[i-1];
	i--;
	for (j=i; j>0; j--) {
	  temp  = X;
	  X = Y;
	  Y = -1 * (Y * Q[j-1] - temp);
	}
	swap(X, Y);
	
	X=1, Y=-1  (initial value)
	X=-1, Y=3  (j==3)
	X=3,  Y=-7 (j==2)
	X=-7, Y=3  (j==1)
	X=3,  Y=-7 (swap)
	
  For example, if A=990 and B=420, we have
                               Q[0]=0
	dividend=990, divisor=420, Q[1]=2;  990 / 420 = 2 ... 150    150 = 900 + (420 * -2)
	dividend=420, divisor=150, Q[2]=2;  420 / 150 = 2 ... 120    120 = 420 + (150 * -2)
	dividend=150, divisor=120, Q[3]=1;  150 / 120 = 1 ... 30     30  = 150 + (120 * -1)
	dividend=120, divisor=30,           120 / 30  = 4 ... 0
	
  Hence,
    30 = (1 * 150) + (-1 * 120) = (1 * 150) + (-1 * (420 + (150 * -2)))
	   = (-1 * 420) + (3 * 150) = (-1 * 420) + (3 * (900 + (420 * -2)))
	   = (3 * 990) + (-7 * 420)
*/
int main(void) {
  int A, B; // Input integer pair.
  int D; // gcd of A and B.
  int X, Y; // Coefficient of the linear Diophantine equation. 
  int dividend, divisor; //  Dividend and divsor to perform division operation. 
  int *Q; // Quotients for processing Euclidean Algorithm.
  int size = 10; // Size of Q and R.
  int temp; // Temporary variable.
  int i, j; // Loop vairables.
  
  // Allocate memory space for Q.
  Q = (int *) malloc(size * sizeof(int));
  
  while (scanf("%d %d", &A, &B)==2) { // Continue, if there two input integers.
  	dividend = A; // Initial dividend.
  	divisor = B; // Initial divsor.
  	Q[0] = 0;
  	i = 1; // Loop variable.
  	while (dividend%divisor!=0) {
  	  Q[i] = dividend / divisor; // Find quotient.
  	  temp = divisor; // Keep the copy of divisor.
  	  divisor = dividend % divisor; // The remainder becomes the next divisor.
  	  dividend  = temp; // The divisor becomes the next dividend.
  	  i++;
  	  // Allocate additional memory space for Q.
  	  if (i==size) {
        size = size + 10;
        Q = (int *) realloc(Q, size * sizeof(int));
      }
	} 
	
	D = divisor; // The divisor is gcd(A, B). D is set to be GCD of A and B.	

	// Expand gcd in the linear combination of A and B, computing the coefficients X and Y.
	i--;
	X= 1;
	Y = -1 * Q[i];
	for (j=i-1; j>=0; j--) {
	  temp  = X;
	  X = Y;
	  Y = -1 * (Y * Q[j] - temp);
	}
	// Swap x and y;
	temp  = X;
	X = Y;
	Y = temp;
	
    printf("%d %d %d\n", X, Y, D); // Output the result.
  }
  return 0;
}
