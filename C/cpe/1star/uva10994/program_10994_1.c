// One-star problem
// Problem 10994 Simple Addition
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
/*
     F(n) =
       n%10,    if n%10>0
       0,       if n==0
       F(n/10), otherwis
     }

  In fact, fucntion F(n) returns the first non-zero digit from the left-hand-side of n. For
  example, F(89)=9, F(10003857)=7, F(300)=3, and F(3650000)=5. We define function lsd_sum(p, q)
  if the summation of the least sigfifcant digits if n for n from p to q:
      lsd_sum(p, q) = (q/10-p/10)*45 - (sum(1,(p%10))-p%10) + sum(1,(q%10)),
  where 45 is sum(1,9).
  
  However, lsd_sum(p,q) does not count F(n), for n such that p<=n<=q and n has trailing 0's.
  Hence, we compute lsd_sum(p/10, q/10) to get the sum of F(n) for those n with one trailing
  0, lsd_sum(p/100, q/100) to get the sum of F(n) for those n with two trailing 0's, etc.
  lsd_sum(p/(10^k), q/(10^k)) for those n between p and q and with k trailing 0's. Therefore,
  we compute lsd_sum(p/(10^k), q/(10^k)) for k from 0, 1, ..., until both p/(10^k)==0 and
  0/(10^k)==0. We the sum up all lsd_sum(p/(10^k), q/(10^k)) to get the value of S(p,q).
  
  In the function call lsd_sum(p/(10^k), q/(10^k)), term p/(10^k),q/(10^k) are the value of p and q
  shifting k digits to the right. Since p is the lower bound, if p is a single digit, p/(10^k)
  becomes 0 after shifting one digit; if p>10 and p is a multiple of 10, p/(10^k) becomes p/10 after
  shifting one digit; if p>10 and p is not a multiple of 10, p/(10^k) becomes p/10+1 after shifting 
  one digit. Since q is the upper bound, q/(10^k) is simply q/10.
  
  When p==q==0, all the digits are counted. The algorithm stops.
*/

// Sum of 1+2+3+...k=(1+k)k/2.
int sum(int k) {
  return (1 + k) * k / 2;
}

// Compute the lsd sum from p to q, but not including those intermediate F(n) where n has
// trailing zeros.
// The result is casted in long long type to avoid integer overflow.
long long lsd_sum(int p, int q) {

  return (long long) (q/10-p/10)*45-(sum(p%10)-p%10)+sum(q%10);
}

// Compute sum of F(p) to F(q). 
long long S_of_F(int p, int q) {
  long long sum=0;
  
  // Every iteration counts the sum of F(n) as given in the previous explantion.
  // p is lower bound and q is the upper bound.
  while (p<q || (p==q && p>0) ) { // When p>q or p==q==0, the loop stops.
  	sum += lsd_sum(p, q);
  	if (p<10) p = 0; // p after one digit shift, if p is a single digit number originally.
    else if (p>=10 && p%10==0) p = p / 10; // p after one digit shift, if p is a multiple of 10.
    else p = p / 10 + 1; // p after one digit shift, if p>10 and and a multiple of 10.
  	q = q / 10;
  }
  return sum;
}

int main(void) {
  int p, q; // Input pair of integers.
  int i; // Loop variable.

  while (1) { // Continue until two negative integers are input.
    scanf("%d %d", &p, &q);
    if (p<0 && q<0) break; // When two negative integers are input, stop the loop.
    printf("%lld\n", S_of_F(p, q)); // Compute and print the sum of F(p) to F(q).
  }
  return 0;
}
