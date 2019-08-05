// One-star problem
// Problem 10035 Primary Arithmetic
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

int main(void) {
  long long int m, n;
  int carry, sum, count;
  
  scanf("%lld %lld", &m, &n); // Input two integers
  
  while (m!=0 || n!=0) { // Continue until both m and n are 0.
  	carry = 0; // Initially, there is no carry.
  	count = 0; // Initial count to 0.
  	while (m!=0 || n!=0) { // Continue until all digits of m and n are processed.
  	  sum = m % 10 + n % 10 + carry; // Sum of the two least significant digits and carry. 
  	  carry = sum / 10; // New carry.
  	  count = count + carry; // Increment count if carry occurs.
  	  m = m / 10; // Shift one digit of m to the right-hand-side. 
  	  n = n / 10; // Shift one digit of n to the right-hand-side.
	}
	if (count==0) printf("No carry operation.\n"); // No carry occurs.
	else if (count==1) printf("1 carry operation.\n"); // Only one carry occurs.
	else printf("%d carry operations.\n", count); // More than one carry occur.
	
	scanf("%lld %lld", &m, &n); // Input the next two integers
  }
  return 0;
} 
