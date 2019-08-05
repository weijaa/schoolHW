// One-star problem
// Problem 10324 Zeros and Ones
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
#include <math.h>

/*
  We will use a bit string to repsent the 0-1 character string. That, a character is
  stored using a bit. Eight bits are place in an unsigned character. The bit string
  representation is in the same order from left to right. That is, character i is in the
  (i/8)-th character of the bit string at the (i%8)-th bit starting from the most
  significant bit. Therefore, for the 0-1 string up to 1,000,000 characters, we need
  most 125,000 bytes of bit string to represent them.
*/
int main(void) {
  // Bit string. This array can hold up to 1,000,000 characters.	
  unsigned char string[125000]; 
  char c; // 0-1 character read from the input.
  int cases = 0; // Number of cases, initial to 0.
  int queries; // Number of queries in a case.
  int m, n; // The pair of integers in each query.
  int count; // Counter for input characters, starting from 0.
  int temp;  // For swapping m and n if necessary.
  unsigned char bit; // The bit value of m-th character.
  int i, j; // Loop variables.
  
  while (scanf("%c", &c)==1) { // Read a character each time, if there is any.
    cases++; // Increase case counter.
    count = 0; // Set character counter to 0.
    // Convert c to bit and add to string. Character C is 0 or 1.
	// The shift operation will move the previous bits to the right position.
    string[count/8] = (string[count/8] << 1) | (c - '0');  
    scanf("%c", &c); // Get next character.
    while (c=='0' || c=='1') { // Read of 0/1 character until newline.
      count++; // Increase character counter.
      // Convert c to bit and add to string. 
      string[count/8] = (string[count/8] << 1) | (c - '0'); 
      scanf("%c", &c); // Get next character.
	}
	// Adjust position of the last bit string byte. For example,
	// if count%8==0, the bit is at the msb position and shift 7 bits to left;
	// if count%8==7, the bit is at the lsb position and it is not shifted.
	string[count/8] = string[count/8] << (7 - count % 8); 

	printf("Case %d:\n", cases); // Print the case number.
	scanf("%d", &queries); // Input the number of queries.
	for (i=0; i<queries; i++) { // Process all queries.
	  scanf("%d %d", &m, &n); // Input the query.
	  if (m>n) { // Swap m, n if they are out of order to make m=min(m, n) and n=max(m, n).
	  	temp = m;
	  	m = n;
	  	n = temp;
	  }
	  // The value of the m-th bit, at the least significant bit.
	  // The m-th bit is in the (m/8)-th byte of the bit string at the 7-m%8 position
	  // from themsb position, the shift operation move this bit to the lsb position 
	  // and then AND &01 toclear the other sevent bits to 0's.
	  bit = (string[m / 8] >> (7 - m % 8)) & 0X01; 
	  for (j=m+1; j<=n; j++) {// Check all the bits from m+1 to n.
	    // (string[j/8]>>(7-j%8))&0X01) fetches the j-th bit; 
		// the XOR operation is 1 if the bits are not the same.
	    if (((string[j/8]>>(7-j%8))&0X01)^bit) { // If the bits not matched, output "No".
	      printf("No\n");
	      break; // Stop the j loop. 
        }
      }
	  if (j>n) printf("Yes\n"); // If j>n, it means all bits matched and output "Yes".
	}
	do { // Move to the beginning of the next case.
	  scanf("%c", &c);
	} while (c!=0X0A);
  }
  return 0;
}
