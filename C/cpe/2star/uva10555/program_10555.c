// Two-star problem
// Problem 10555 Dead Fraction
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

// Euclidean algorithm for computing gcd of m and n.
unsigned long long gcd (unsigned long long m, unsigned long long n) {
  if (m%n==0) return n;
  else return gcd(n, m % n);
}

int main(void) {
  char s[101]; // Input of the fractional number is treated as string. Assume maximum 100 characters.
  unsigned long long numerator, denominator; //  Expression of the rational number.
  unsigned long long factional; // Factional part of the number before the repeated digit.
  unsigned long long g; // Greatest common divisor.
  int repeat; // The repeated digit.
  int power; // Number of digits after the decimal point prior to the repeated digit.
  int leng; // Length of string s.
  int i; // Loop variable.
  
  while (1) { // Continue, until the input is "0".
    scanf("%s", s);    
    if (strcmp(s, "0")==0) break; // If the input is "0", stop the loop and terminate the program.
    
    leng = strlen(s); // Length of string s.
    
    // Convert the factional part of the number to integer and count the number of digits.
    // The syntax is "0.dddddr...". The number six counts "0." and "r...".
    power = leng - 6; // The number of digits in the fractional part except the repeated one.
    factional = 0; // Initial factional to 0.
    for (i=2; i<leng-4; i++) { // Convert the fractional part to integer.
      factional = factional * 10 + s[i] - '0';
	}
	numerator = factional * 9 + s[leng-4] - '0'; // The numerator is factional*9 plus the repeated digit.
	denominator = pow(10, power) * 9; // The denominator is 10^power*9.
	g = gcd(numerator, denominator); // Compute the gcd of numerator and denominator.
	printf("%llu/%llu\n", numerator / g, denominator / g); // Output the result.
  }
  return 0;
}
