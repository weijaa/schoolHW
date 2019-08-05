// One-star problem
// Problem 10783 Odd Sum
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
  int cases; // Number of cases;
  int m, n; // Input pair of integers.
  int i; // loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%d %d", &m, &n); // Input pair of integers.
    
    if (m%2==0) m++; // Set m to be the first odd number greater than or equal to m.
    if (n%2==0) n--; // Set n to be the first odd number less than or equal to n.
    
    // This an arithmetic progression with the first term of value m, the last term of value n,
    // and (n-m)/2+1 term(s). The sum of this series is (m+n)*((n-m)/2+1)/2.
    // Note that we assum the input integers m is less than equal to n.
	// If m equals to n and both of them are even number at the beginning, the adjusted 
	// values of m and n will make (n-m)/2+1 to be 0. Hence, the sum is also 0. 
    printf("Case %d: %d\n", i+1, (m+n)*((n-m)/2+1)/2);
  }
  return 0;
}
