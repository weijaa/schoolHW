// Two-star problem
// Problem 10176 Ocean Deep! - Make It Shallow!!
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

// The binary value of 131071 is 1 1111 1111 1111 1111 (17 ones).
// Since the large number may have as many as 100 digits, it is better to represent
// it as a string n.
int main(void) {
  char n[102]; // Input binary number, up to 100 digits ending with '#'.
  int length; // Length of the input string.
  unsigned prefix; // Prefix bits of n.
  int bit_count; // Number of bits of prefix of n.
  int has_zero; // 0: prefix of n has no zeros; 1: prefix has at least one zeros.
  unsigned one; // Variable for search bit 1, only a single bit is 1.
  int i, j; // Loop variables.
  
  
  while (scanf("%s", &n)==1) { // Input a binary number if there is any.
    length = strlen(n); // Length of the binary number, including '#'.
    n[length-1] = '\0'; // Replace '#' by end of string.
    length--; // Substract length by 1.
    
    prefix = 0;  // Reset the prefix of n to 0.
    bit_count = 0; // Initial bit count to 0.
    has_zero = 0; // No zero in the prefix yet.
    i = 0; // Initial i to 0.
    while (i<length) { // When there are more bits in the rest of n,
      if (bit_count==0) { // When prefix is 0,
        while (i<length) {
	      if (n[i]=='0') i++; // Skip all leading zeros.
	      else break; // The first '0' is found, stop the loop.
	    }
	    if (i==length) break; // If no bits in n left, stop the loop.
	  }
      // Add the 1st bit in the reset of n to the prefix.
      prefix = (prefix<<1) | (n[i]-'0');
      if (n[i]=='0') has_zero = 1; // If there is a zero, set has_zero to 1.
      bit_count++; // Increment the bit count of the prefix.
	  // When the prefix is greater than or equal to 0X1FFFF, subtract 0X1FFFF from 
	  // the prefix. 
	  if (bit_count==17+has_zero) {
	    prefix = prefix - 0X1FFFF; // Minus operation in the long division operation.
	    has_zero = 0; // Reset has_zero to 0.
	    bit_count = 17; // Set bit count to the length of 0X1FFFF.
	    one = 0X10000; // Search start from the position of the first 1 in 0X1FFFF.
	    while (bit_count>0 && (prefix&one)==0) { // The bit under inspection is not 1.
	      bit_count--; // One bit less in prefix.
	      one = one >> 1; // Compare the next bit on the left.
	    }
	    j = 0; // Start from the least significant bit in the rest of prefix.
	    one = 1; // Initial the check bit to 1.
	    while (j<bit_count && !has_zero) {
	      if ((prefix&one)==0) {
		    has_zero = 1; // A zero is found.
		    break; // Stop the search loop.
		  }
		  else {
		    j++; // Check the next bit.
		    one = one << 1; // Move the check bit one position to the left.
		  }
	    }
	  }
	  i++; // Check the next bit in n.
	}
	// If no remainder left, n is divisible by 131071.
	if (prefix==0)  printf("Yes\n"); 
	else printf("No\n"); 
  }
  return 0;
}
