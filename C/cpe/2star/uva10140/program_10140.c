// Two-star problem
// Problem 10140 Prime Distance
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

// Find the next prime greater than or equal to n.
int find_next_prime(int n) {
  int sqroot; // Square root of an integer.
  int i, j; // Loop variable.
  
  i = n;
  while (1) {
  	sqroot = sqrt(i); // Square root of i.
  	for (j=2; j<=sqroot; j++) // Check all integers less than or equal to square root.
  	  if (i%j==0) break; // i has a factor; it i not a prime.
  	if (j>sqroot) return i; // i has no factors less than or equal to square root. It is a prime. 
  	else {
  	  i++; // i is a composed number, try next i.
	  sqroot = sqrt(i); // Square root of the new i.
	}
  }
}

int main(void) {
  int L, U; // Input pair of integers.
  int min_distance, max_distance; // Minimum and maximum distances between two adjacent primes.
  int min_index, max_index; // Index of the frirst prime with the minimum and maximum distances.
  int min_prime1, min_prime2, max_prime1, max_prime2; //
  int prime1, prime2; // Two consecutive primes.
  int i; // Loop variable.
  
  while (scanf("%d %d", &L, &U)==2) { // Continue, if there two integers in the input stream.
    prime1 = find_next_prime(L);
    prime2 = find_next_prime(prime1+1);
    // Initialize minimum and maximum distance to 1000000 and 0, respectively.
    min_distance = 1000000;
    max_distance = 0;
    for (i=prime1; i<=U && prime2<=U; i++) { // Try all primes between L and U.
      if ((prime2-prime1)<min_distance) {
      	min_distance = prime2-prime1; // Update minimum distance.
      	min_index = i; // Set i be the first prime with the minimum distance.
      	min_prime1 = prime1; // Update the two primes form minimum distance.
		min_prime2 = prime2;
	  }
      if ((prime2-prime1)>max_distance) {
      	max_distance = prime2-prime1; // Update maximum distance.
      	max_index = i; // Set i be the first prime with the maximum distance.
      	max_prime1 = prime1; // Update the two primes form maximum distance.
		max_prime2 = prime2;
	  }
      prime1  = prime2; // Try next pair of primes.
      prime2 = find_next_prime(prime2 + 1);
	}
	
	if (min_distance<1000000 && max_distance>0) // The pair of primes are found.
	  printf("%d,%d are closest, %d,%d are most distant.\n", // Print the primes make minimum and maximum 
	          min_prime1, min_prime2, max_prime1, max_prime2); // distance.
	else printf("There are no adjacent primes.\n"); // No pair of primes exist.
  }
  return 0;
}
