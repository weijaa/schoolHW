// Two-star problem
// Problem 10042 Smith Numbers
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

typedef struct {
  int prime; // A prime number.
  int sum; // Digit sum of the prime number.
} Prime;

// The following two function specifications are needed because of mutuall recursion.
// Function specification of generate_prime.
void generate_prime(int, Prime *, int *, int *);

// Function sepcification of is_prime.
int is_prime(int, Prime *, int *, int *);

int find_digit_sum(int n) {
  int sum = 0; // Initial digit sum to 0.
  while (n>0) { // Continue, when n is greater 0.
  	sum += n % 10; // Add the left-most digit to the digit sum
  	n = n / 10; // Remove the left-most digit of n.
  }
  return sum; // Return digit sum.
}

void next_digit_sum(int *n, int *sum) { // The two parameters are all declared using call-by-address.
  int power10 = 10; // Power of 10 start from 10^1..
  
  (*n)++; // Next number of n (with side effect).
  (*sum)++; // Next digit sum (with side effect).
  // When the value of n is a power of 10, subtract 9 from the next digit sum in each iteration.
  // For each itration, the exponent of power10 is incremented by 1. 
  while ((*n)%power10==0) {
  	power10 *= 10;
  	*sum -= 9;
  }
}

// Note that is_prime() and generarte_prime() are two mutually recursive functions.
// Starting with generarte_prime(), they call each other to generate all primes required.
// Test if n is a prime number or not. Return 1 if it is a prime number, otherwise, return 0.
// n is an odd number.
int is_prime(int n, Prime *primes, int *max_prime_index_ptr, int *max_prime_count_ptr) {
  int sqrt_n = sqrt(n); // Sqaure root of n.
  int index; // Prime number index;
  
  if (sqrt_n>primes[*max_prime_index_ptr-1].prime) // Not engough primes to test.
  	generate_prime(sqrt_n, primes, max_prime_index_ptr, max_prime_count_ptr); // Generate more primes.
  
  index = 1; // Start from prime 3.
  while (sqrt_n>=primes[index].prime) { // When more primes to test, continue.
  	if (n%primes[index].prime==0) return 0; // n is not a prime number since primes[index] is a factor of n.
  	index += 1; // Try next prime number.
  }
  return 1;	// n is a prime number since no prime less than or equal to sqrt_n is a factor of n.
}

// Generate all prime numbers upto the first prime greater than or equal to m.
// The last three parameters are delcared unsing call-by-address.
void generate_prime(int m, Prime *primes, int *max_prime_index_ptr, int *max_prime_count_ptr) {
  int prime_candidate = primes[*max_prime_index_ptr-1].prime + 2;

  if (m%2==0) m++; // Change m to the next odd number, if it is even.
  do {
  	// prime_candidate is a prime number.
  	if (is_prime(prime_candidate, primes, max_prime_index_ptr, max_prime_count_ptr)) { 
  	  // Add it to the prime list and increment max_prime_index.
  	  primes[(*max_prime_index_ptr)].prime = prime_candidate;
  	  primes[(*max_prime_index_ptr)++].sum = find_digit_sum(prime_candidate);
  	  // If the memory of the primes is full, get more memory. This reallocation statement will be
  	  // be reached because we allocate the initial prime poitners large enoght for the maximum value
	  // problem required. You are encourged to try reallocation if you use other system than Dev-C++
	  // in 64-bit Window 10.
  	  if (*max_prime_index_ptr==*max_prime_count_ptr) { 
  	  	*max_prime_count_ptr += 100; // Request memory for 100 more primes.
  	  	// Reallocate memory space.
  	  	primes = (Prime *) realloc(primes, *max_prime_count_ptr * sizeof(Prime)); 
	  }
	}
	prime_candidate += 2; // Each incremented by 2 to keep it as an odd number.
  } while (m>=prime_candidate);
}

int main(void) {
  int cases; // Number of cases;
  int n; // Input integer n;
  int n1; // Copy of n1 used in computing factors of prime factors.
  int sqrt_n; // Square root of n;
  int Smith; // 1: if the smallest Smith number is found; 0: otherwise.
  int digit_sum; // Digit sum of integer n.
  int prime_digit_sum; // Digit sum of prime factors of integer n.
  // The program will remember all prime numbers generated in each of the previous cases.
  Prime *primes; // Pointer to a collection of primes with their digit sum.
  int max_prime_index = 2; // Initially, only primes[0] and prime[1] are recorded.
  int max_prime_count = 3450; // Maximum prime number counts in the prime container primes.
  int factor_index; // Index of a prime factor.
  int c, i; // loop variables.
  
  scanf("%d", &cases); // Input the number of testing cases.
  
  // Originally, allocation 100 prime pointers. The original program encounters a problem of
  // memory reallocation. The problem disappear when the initial number of prime pointer increased
  // large enough to avoid memory reallocation. The program is logically sound. However, the
  // trouble keep on rising when reallocation is required. 
  // The program is changed to allocate 3450 prime pointers, since there are only 3401 prime 
  // numbers for integers less than 10^9.
  primes = (Prime *) malloc(max_prime_count * sizeof(Prime));
  primes[0].prime = 2; // Initial the first prime number.
  primes[0].sum = 2; // Initial the digit sum of the first prime number.
  primes[1].prime = 3; // Initial the second prime number.
  primes[1].sum = 3; // Initial the digit sum of the second prime number.
  
  for (c=0; c<cases; c++) { // Process all cases.
    scanf("%d", &n);
    sqrt_n = sqrt(n); // Compute sqaure root of n.
    // If the square root of n is greater than the maximum prime number, generat additional 
	// prime numbers up to the first prime greater than or equal to sqrt_n.
    if (sqrt_n>primes[max_prime_index-1].prime+1) 
      generate_prime(sqrt_n, primes, &max_prime_index, &max_prime_count);
  
    Smith = 0; // A Smith number if not found yet.
    n++;; // Serach begin with n+1.
    digit_sum = find_digit_sum(n); // Digit sum of n.
    
    while (!Smith) {
      // Compute digit sum of prime factors.
      prime_digit_sum = 0; // Initial prime factor of n to 0.
      n1 = n; // Copy of n.
      factor_index = 0; // Start from prime 0.
      while (sqrt_n>=primes[factor_index].prime) { // Search for factors of n.
      	if (n1%primes[factor_index].prime==0) { // A prime factor is found.
      	  prime_digit_sum += primes[factor_index].sum; // Accumulate the digit sum of prime factors.
      	  n1 = n1 / primes[factor_index].prime; // Rest of n to be tested.
      	  // Do not chage factor_index because n may have multiple terms of the same prime factor.
		}
      	else {
		  factor_index++; // Try next prime number.
		  sqrt_n = sqrt(n1); // The rest of n can not be devided by the early prime factor either.
		  }
	  }
	  // When the loop terminates, the rest n1 is a prime number itself if it is greater than 1.
	  // Add the digit sum of rest of n1 to the prime digit sum.
	  if (n1>1) prime_digit_sum += find_digit_sum(n1);
	  // If the digit sum of n equals to the digits of factors of n and n is not a prime number,
	  // then n is a Smith number. If n1==n, n is a prime number.
      if (digit_sum==prime_digit_sum && n1!=n) Smith = 1; 
      else { // If not, try the next integer.
        next_digit_sum(&n, &digit_sum); // next_digit_sum has side effect on both parameters.
      
        sqrt_n = sqrt(n); // Compute sqaure root of the new n.
        // If the square root of n is greater than the maximum prime number, generat additional prime 
	    // numbers up to the first prime greater than or equal to sqrt_n.
        if (sqrt_n>primes[max_prime_index].prime+1) 
          generate_prime(sqrt_n, primes, &max_prime_index, &max_prime_count);
	  }
    }
  	printf("%d\n", n); // Output the result.
  }
  return 0;
}
