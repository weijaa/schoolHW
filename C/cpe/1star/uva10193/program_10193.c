// One-star problem
// Problem 10193 All You Need Is Love
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
/*
   An S is made of love give L, if and only if L is a divisor of S. 
   S1 and S2 are two binary strings, if S1 and S2 has a common divisor L whose binary
   representation is a valid string, then S1 and S2 are made of love with L.
   
   To solve this problem we will read S1 and S2 as two string of binary digit, and then
   convert them to the integer value. The next step is to compute the great common divisor L
   of S1 and S2. If L is not a power of 2 than S1 and S2 are made of love with L; otherwise,
   love is not all they need.
*/

// Conver a string of binary representation to an integer.
int binary2decimal(char *str) {
  int i;
  int dec = 0;
  for (i=0; i<strlen(str); i++) {
  	dec = dec << 1; // Shift the integer value one bit to the left hand side.
  	if (str[i]=='1') dec = dec | 0X1; // For binary digit 1, place a one-bit to the integer;
  }
  return dec;
}

// Compute the greatest common divisor of integers m and n.
int gcd (int m, int n) {
  if (m%n==0) return n;
  else return gcd(n, m%n);
}

// Check power of 2, i.e., if the parameter a has more than one 1-bit.
int is_power_of_2(int a) {
  int one_bit = 0;
  while (a!=0) {
  	if (a & 0X1) one_bit++; // A one-bit is found.
  	a = a >> 1; // Shift a one bit to the right, move to check next bit.
  }
  if (one_bit==1) return 1; // Yes, a is a power of 2.
  else return 0;            // No, a is not a power of 2.
}

int main(void) {
  char S1[31], S2[31]; // Use string to represent binary number of S1 and S2.
  int cases; // Number of cases.
  int n1, n2; // Decimal values of S1 and S2, respectively.
  int g; // GCD of n1 and n2.
  int i; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  for (i=1; i<=cases; i++) { // Perform all cases.
    scanf("%s %s", &S1, &S2); // Input two binary strings.
    n1 = binary2decimal(S1); // Convert S1 to decimal integer.
    n2 = binary2decimal(S2); // Convert S2 to decimal integer.
    g = gcd(n1, n2); // Compute the greatest common divisor of n1 and n2.
    // If the two number s are not relatively prime, they have a common love. 
	if (g==1) printf("Pair #%d: Love is not all you need!\n", i);
    else printf("Pair #%d: All you need is love!\n", i);
  }
  return 0;
}
