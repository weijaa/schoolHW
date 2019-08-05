// One-star problem
// Problem 10931 Parity
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
  int I; // The input positive integer, where 1<=I<=2147483647. Hence, 32-bit integer is enough.
  int parity; // The parity count.
  int bit; // A single bit for parity checking.
  int i; // Loop index.
  
  while (1) { // Continue the loop until 0 is input.
    scanf("%d", &I); // Input the integer.
    if (I==0) break; // If the input is 0, stop the loop and program terminates.
    parity = 0; // Clear the parity count.
    printf("The parity of "); // Output the mesaage text before the bit string.
    // We will count the parity and print the bits in the following loop.
    for (i=0; i<32; i++) {
      bit = (I>>31-i) & 1; // Get the i-th bit from the most significant position. 
	  if (bit) parity++; // If the bit is 1, increment the parity count.
	  if (parity>0) printf("%d", bit); // After a 1-bit has been seen, print the bit.
    }
    printf (" is %d (mod 2).\n", parity); // Print the rest of message, including parity count.
  }
  return 0;
}
