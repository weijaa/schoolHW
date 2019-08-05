// One-star problem
// Problem Relational Operators
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
  int cases; // Number of cases.
  int a, b; // Input integers a and b.
  int i; // Loop variable.
  
  scanf("%d", &cases); // Input number of cases.
  
  for (i=0; i<cases; i++) {
  	scanf("%d %d", &a, &b); // Input two integers a and b.
  	if (a<b) printf("<\n"); // a<b, output "<" operator.
  	else if (a>b) printf(">\n"); // a>b, output ">" operator.
  	else printf("=\n"); // a==b, output "=" operator.
  }
  return 0;
}
