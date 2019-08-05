// One-star problem
// Problem 10162 Last Digit
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

/* Let us cosider the last digit of the power of one digit, power(N), where 0<=N<10.
   We have power(0,k)=0, power(1,k)=1, power(5,k)=5, power(6,k)=6 for any positive integer k.
   Hence, N=0, 1, 5, and 6, the cycle length of single-digit power is 1. Next, consider N is 4 or 9;
   power(4, 1)=4, power(4, 2)=6, power(4, 3)=4, and power(4, 4)=6, etc; power(9, 1)=9, power(9, 2)=1,
   power(9, 3)=9, and power(9, 4)=1. For N=4 and 9, the cycle length of sigle-digit power is 2.
   Finaly, for N=2, 3, 7, and 8, power(2, 1)=2, power(2, 2)=4, power(2, 3)=8, power(2, 4)=6,
   and power(2, 5)=2; power(3, 1)=3, power(3, 2)=9, power(3, 3)=7, power(3, 4)=1,
   and power(3, 5)=3; power(7, 1)=7, power(7, 2)=9, power(7, 3)=3, power(7, 4)=1,
   and power(7, 5)=7; power(8, 1)=8, power(8, 2)=4, power(8, 3)=2, power(8, 4)=6,
   and power(8, 5)=8. N=2, 3, 7, and 8, the cycle length of sigle-digit power is 4.
   We construct a two-dimensional power[10][4] to record the sigle-digit power of 
   0, 1, ..., 8, and 9. Array element power[i][j] is the last digit of i^(k*i+j) for any k.
   That is, for any positive integer n, i is n%10 the least signifcant digit of n and j is 
   n%cycle[n%10], where cycle[10] is a one-dimensional array storing the cycle lenght of sigle-digit
   power of the least significant digit of n%10. Note that power[i][] stores the powers in the
   order of remainder n%i, e.g., i=2, power[2][] is {6, 2, 4, 8}.
   
   We explain the algorithm for computing lsd(N) which is defined as the least significant digit of
   sum 1^1+2^2+...+n^n. Function lsd(N) can be defined recursively lsd(0)=0 and lsd(i)=lsd(i-1)+i^i,
   for i>0 and operations "+" and "^" returns the last digit only. The last digit addition i+j is
   (i+j)%10. The last digit operaton i^i is exactly power[i%10][i%cycle[i%10]]. Hence,
   lsd(i)=(lsd(i-1) + power[i%10][i%cycle[i%10]]) % 10. Without proof, we use the fact that function
   lsd(N), for n>=0, forms a cyclic sequence of length 100. That, the sequence lsd(0), lsd(1), ...,
   lsd(99) is identical to sequence lsd(100*k), lsd(100*k+1), ..., lsd(100*k+99) for any positive
   integer k. Therefore, lsd(N)=lsd(N%100).
*/
int main(void) {
  // Since N is between 1 and 2*(10^100), the largest value of N has 101 digits.
  // We use a string to reprsent N, a character for a digit.  
  char N[102]; // Input number, we will treat the number as a string, maximum 101 digits.
  int length_N;

  // We declare and initial power[10][4] and cycle[10] as explained previously.
  int power[10][4]={{0}, {1}, {6, 2, 4, 8}, {1, 3, 9, 7}, {6, 4},
                    {5}, {6}, {1, 7, 9, 3}, {6, 8, 4, 2}, {1, 9}};
  int cycle[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
  
  int lsd[100]; // To store the values of lsd[N], for 0<=N<100.
  
  int two_digit; // The value of the last two digits of N, i.e., N%100. 
  int i;
  
  // Compute lsd[N], for 0<=N<100, as defined previously.
  lsd[0] = 0;
  for (i=1; i<100; i++) lsd[i] = (lsd[i-1] + power[i%10][i%cycle[i%10]]) % 10;
  
  while (scanf("%s", &N)) { // Input N as a string.
    length_N = strlen(N);
    if (length_N==1 && N[0]=='0') break; // Stop the program when 0 is input.
    
    // Convert the last two digit to decimal value.
  	if (length_N==1) two_digit = N[length_N-1] - '0'; // N is a single digit.
	else two_digit = (N[length_N-2] - '0') * 10 + N[length_N-1] - '0'; 
  	printf("%d\n", lsd[two_digit]);
  }
  return 0;
}
