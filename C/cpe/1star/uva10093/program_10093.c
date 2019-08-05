// One-star problem
// Problem 10093 An Easy Problem!
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
#include <math.h>

// The input number contains characters in 0-9, A-Z, and a-Z. Hence, it must be a string.
int main(void) {
  char R[11]; // Assume the input number is no more than 10 digits because the input is an integer.
  char N; // The character with the largest ASCII code value.
  int base, length, exponent, digit_in_decimal;
  unsigned long long value;
  int i, j;
  
  
  while (scanf("%s", &R)==1) {
  	N = '\0';
  	// Search the character with the greatest ASCII code value in R. 
  	for (i=0; i<strlen(R); i++) if (R[i]>N) N = R[i];
	// Convert the initial base digit to integer value. 
	// The initial base is the order of the initial base digit plus 1.
	if (isdigit(N)) base = N - '0' + 1; // The base digit is a digit.
	else if (isupper(N)) base = N - 'A' + 11; // The base is an upper case letter.
	else if (islower(N)) base = N - 'a' + 37; // The base is a lower case letter.
	
	// Check all bases greater than or equal to the initial base.
	// The loop has no initial condition which is determined in the previous lines of code.
	// The maximum base is 62.
	for (; base<=62; base++) { 
	  exponent = 0; // Initial the exponent to 0.
	  value = 0; // Initial the value to 0
	  for (i=strlen(R)-1; i>=0; i--) { // Convert all "digits" in R from left to right.
	    if (isdigit(R[i])) digit_in_decimal = R[i] - '0'; // The "digit" is a digit.
	    else if (isupper(R[i])) digit_in_decimal = R[i] - 'A' + 10; // The "digit" is an upper case letter.
	    else if (islower(R[i])) digit_in_decimal = R[i] - 'a' + 36; // The "digit" is a lower case letter.
	  	value = value + digit_in_decimal * pow(base, exponent); // Accumulate the value.
	  	exponent++; // Increment the exponent.
	  }
	  if (value%(base-1)==0) break; // Find N such that R is divisible by N-1. Stop the loop.
    }
    if (base<=62) printf("%d\n", base); // A base is found.
    else printf("such number is impossible!\n"); // No base is found.
  }
  return 0;
}
