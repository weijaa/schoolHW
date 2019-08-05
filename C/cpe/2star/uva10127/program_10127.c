// Two-star problem
// Problem 10127 Ones
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

// This problem is sovled using congruence theorem. 
// For an integer a, if a%n=r, then (a+b)%n=(r+b)%n and (a*b)%n=(r*b)%n.
// Hence, if a%n=r, then (a*b+c)%n=(r*b+c)%n.
// Initially, set a=1, b=10 and c=1.
// In the following program, at the end of every iteration a is an integer of all 1's. Also,
// initialize ones to 1 and increment ones in every iteration, then,
// after the end of the j-th iteration, ones is j+1 and a has j+1 1's.
int main(void) {
  int n; // Input integer.
  int r; // All ones, with the congurence value.
  int ones; //Number of ones.
  
  while (scanf("%d", &n)==1) { // Input an integer if there is any.
  
    r =  1 % n; // Initial congruent number, a is 1.
    ones = 1; // Count one 1's.
    while (r!=0) { // When r==0, 111.1 is divided by n.
      r = r * 10 + 1; // Add one more 1 to a; b==10 and c==1.
      ones++; // Increment number of 1's
      r = r % n; // Congruent number of 111...1, the number of 1 is the value of ones.
	}
	
	printf("%d\n", ones); // Ouput the number of 1's.
  }  
  return 0;
}
