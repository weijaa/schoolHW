// Two-star problem
// Problem 495 Fibonacci Freeze
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

typedef char *Number; // Data type, same as a character pointer.

// Convert a string to a number. Need this function to allocate memory space.
Number str2num(char *str) {
  Number num; // Number as string.
  
  num = (Number) malloc(strlen(str)+1); // Allocate sufficient memory.
  strcpy(num, str); // Copy the string.
  return num;
}

// Addition operation using strings.
Number add(Number op1, Number op2) {
  Number sum; // op1+op2
  int l1=strlen(op1), l2=strlen(op2), lsum, lsum1; // String lengths.
  int t1, t2, t, carry = 0; // One digit addition: t=t1+t2+carry.
  int i = 0; // Loop variable.
  
  lsum = (l1>l2) ? l1 : l2; // Maximum value of l1 and l2.  
  lsum1 = lsum; // For later reuse of the maximum length.
  sum = (Number) malloc(lsum + 1); // Allocate memory for the sum.
  
  sum[lsum] = '\0'; // End of string.
  while (lsum>0) { // add all digits from right to left.
  	t1 = (l1>0) ? op1[--l1] - '0' : 0; // Get a digit of op1, if there is any.
  	t2 = (l2>0) ? op2[--l2] - '0' : 0; // Get a digit of op2, if there is any.
  	t = t1 + t2 + carry; // Add two single digits with carry.
  	carry = t / 10; // New carry.
  	sum[--lsum] = t % 10 + '0'; // Sum of the digit, in ASCII code format.
  }
  if (carry==1) { // If carry is 1,put this carry to the leading digit of sum.
    sum = (Number) realloc(sum, lsum1 + 2); // Expand the memory of sum one more byte.
    for (i=strlen(sum); i>=0; i--) sum[i+1] = sum[i]; // Move the digits one position to left.
    sum[0] = '1'; // Plcase '1' at the leaFding digit position.
  }
  return sum; // Return the sum.
}

// We assume the input is a positive integer can be represented in the 32-bit
// unsigned integer type, i.e., the maximum value is 4,294,967,295. However, the
// Fibonacci number grows very fact, 32-bit unsigned integers are not sufficienty
// to represent the Fibonacci number. We will use digit string to represet "very"
// large integers.
int main(void) {
  unsigned n; // Input unsigned integer.
  // Two temporary number for two consecutive terms of Fibonacci number.
  Number last1, last2;
  Number fib; // Current Fibonnaci number.
  int i; // Loop variable.
  
  while (scanf("%u", &n)==1) { // Input an integer if there is any.
  
    if (n==0) printf("The Fibonacci number for 0 is 0.\n"); // Fib(0) 
	else if (n==1) printf("The Fibonacci number for 1 is 1.\n"); //Fib(1)
	else {
	  // Use iterative algortihm to compute Fib(n), for n>=2.
	  last2 = str2num("0"); // Fib(0), use string representation.
	  last1 = str2num("1"); // Fib(1), use string representation.
	  for (i=2; i<=n; i++) { // Iterate from 2 up to n.
	  	fib = add(last2, last1); // Compute the next Fibonacci number.
	  	free(last2); // Release memory not used any more. 
	  	last2 = last1; // Update last2.
	  	last1 = fib; // Update last2.
	  }
	  printf("The Fibonacci number for %d is %s.\n", n, fib); // Output the result.
	  free(last2); // Release the last two memory occupied by last2 and last1.
	  free(last1); // For the next testing case, request new memory space.
	}
  }
  return 0;
}
