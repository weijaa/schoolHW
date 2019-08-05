// One-star problem
// Problem UVA406 Prime Cuts
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

int main(void) {
  int primes[180]; // Prime list, the number of primes between 1 an 1000 does not exceed 180.
  int n, C;
  int i, j, upper, count;

  while (scanf("%d %d", &n , &C)==2) { // Input n and C.
    count = 2; // Set prime list count to 0.
    primes[0] = 1; // Set the first prime number.
    primes[1] = 2; // Set the second prime number.
    // Construct prime list between 1 and n.
    for (i=3; i<=n; i++) // Check all possible numbers between 1 and n.
      for (j=1; j<count; j++) // For all existing prime numbers.
      	if (i%primes[j]==0) break; // If there is a prime divides i, i is not a prime.
		else if (i<primes[j]*primes[j]) { // If i cannot be divided by all primes less than sqrt(i),
		  primes[count++] = i; // then add i to the prime list.
		  break; // Stop the prime search.
		}
    
    printf("%u %u: ", n, C); // Print n and C.
    if (count%2==0 && count>=C*2) // Even length and count>=C*2.
      for (i=0; i<C*2; i++) printf("%d ", primes[count/2-C+i]); // Left align C elements from the center.
    else if (count%2==1 && count>=C*2-1) // Odd length and count>=C*2-1
      for (i=0; i<C*2-1; i++) printf("%d ", primes[count/2-(C-1)+i]); // Left align C-1 elements from the center.
    else // The prime list is shorter less than 2C or 2C-1.
      for (i=0; i<count; i++) printf("%d ", primes[i]); // Print all elements in the prime list.
    printf("\n");   
  }
  return 0;
} 
