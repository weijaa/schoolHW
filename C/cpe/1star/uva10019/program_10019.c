// One-star problem
// Problem 10019 Funny Encryption Method
/*
This program is written by
    Prof. Chua-Huang Huang
	Department of Information Engineering and Computer Science
	Feng Chia University
	Taichung, Taiwan
Disclaimer:
    The programming problem is downloaded from UVa Online Judge (https://uva.onlinejudge.org/).
    The program solution is provided for helping students to prepare Collegiate Programming
	Examination (CPE). The author does not guarantee the program is completely correct to pass 
	UVa Online Judge platform or CPE examination platform.
	This program is not intended for a student to copy only. He/She should practice the 
	programming problem himself/herself. Only use the program solution as a reference. 
    
	The author is not responsible if the program causes any damage of your computer or 
	personal properties.
	No commercial use of this program is allowed without the author's written permission.	
*/
#include <stdlib.h>
#include <stdio.h>

// Count the number of 1-bits in s.
int bit_count(int s) {
  int count = 0; // Initial the counter to 0.
  
  while (s!=0) { // Terminate the loop when s is 0, i.e., no 1-bits at all.
  	if (s%2==1) count++; // The least significant bit of s is 1, increment the counter.
  	s = s / 2; // Shift s one bit to the right. 
  }
  return count;	// Return the counter.
}

int main(void) {
  int N; // Number of cases.
  int M; // Input data.
  int b1, b2;
  int i;
  
  scanf("%d", &N); // Input the number of cases.
  
  for (i=0; i<N; i++) { // Perform all cases specified.
  	scanf("%d", &M); // Input number M.
    b1 = bit_count(M); // Count the number of 1-bits in M;
    b2 = 0; // Initial b2 to 0.
    while (M!=0) { // Treat M as a hexadecimal numeral, count until all hexadecimal digits are processed.
      b2 = b2 + bit_count(M % 10); // Get the right-most significant digit and count its 1-bits.
      M = M / 10; // Discard the right-most digit.
	}
	// Output the number of bits for b1 representing n as a decimal number 
	// and b2 representing n as a hexadecimal number. 
    printf("%d %d\n", b1, b2); 
  }
  return 0;
} 
