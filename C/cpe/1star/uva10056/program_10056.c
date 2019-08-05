// One-star problem
// Problem 10056 What is the Probability?
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

/*
  If the probability of a successful event to happen is p, then the the probability of a 
  successful event not to happen is 1-p. If play i wins in round 1, the successful event
  must not happen for the i-1 players before him/her and he/she must draw the suffessful
  event. This phenomenon has the probability ((1-p)^(i-1))*p. If play i wins in round k, the
  probability is ((1-p)^(n*(k-1)+i-1))*p. Hence the probability of play i to win in round 1, 2,
  3, and so on, forms a geometric progression with the initial term being a=((1-p)^(i-1))*p 
  and the common ratio r=(1-p)^n. The probability of play i to win is the summation of the
  geometric series a+a*r+a*r^2+a*r^3+...=a/(1-r).
*/
int main(void) {
  int cases, n, i;
  float p, a, r;
  int c;
  
  scanf("%d", &cases); // Input the number of cases.
  for (c=0; c<cases; c++) { // Perform all cases.
    // n: the number of player, p: probability of the successful event, i: the specified play to win.
    scanf("%d %f %d", &n, &p, &i);
    a = pow(1 - p, i - 1) * p; // The initial term.
    r = pow(1 - p, n); // The commor ratio.
    printf("%6.4f\n", a / (1 - r)); // Summation of the geometric series a+a*r+a*r^2+a*r^3+...=a/(1-r).
  }
  return 0;
}
