// One-star problem
// Problem 10268 498-bis
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

/* The problem does not mention the maximum degree of a polynomial. We use dynamic array
   to store the coefficients. Initially assume the degree is less than 100. When the degree
   is going to exceeds the preset value, reallocate the coefficient list by 100 more elements.
*/
int main(void) {

  int x; // A value to evaluate the polynomial.
  int *coefficient; // List of coefficients.
  int degree; // Degree of polynomial.
  int max_degree; // Maximum degree.
  int result; // Result of evaluating the polynomial directive.
  char c; // Character to be checked for space.
  int i; // Loop variable.
  
  
  while (scanf("%d", &x)==1) { // Input the value of x if there is any.
    max_degree = 100; // Initial degree count in a malloc/realloc session.
    coefficient = (int *) malloc(max_degree * sizeof(int)); // Get memory space for storing coefficients. 
    degree = 0; // Initially, set the degree to 0.
    scanf("%d", &coefficient[degree]); // There must be at least one coefficient.
    while (scanf("%c", &c)==1) { // Input a character to check a space.
      if (c==' ') { // If the character is a space, continue to read the next coefficient.
        scanf("%d", &coefficient[++degree]); // Input the next coefficient.
        if (degree==max_degree-1)  { // The memory space of coefficient is full.
          max_degree += 100; // Increase the maximum degree limit.
          coefficient = (int *) realloc(coefficient, max_degree*sizeof(int)); // Extend the memory space for coefficients.
		}
	  }
	  else break; // No space is detected, all coefficients have been input.      
	}
  	result = 0;
  	// Evaluate the derivate of the polynomial, 
	// the constant term of the polynomical is not evaluated.
  	for (i=0; i<degree; i++)
  	  result += coefficient[i] * (degree - i) * pow(x, degree -i - 1); // a_i*(n-i)* x^(n-i-1).
  	  
  	printf("%d\n", result); // Output the result.
    free(coefficient); // Release the memory space for coefficients.
  }
  return 0;
}
