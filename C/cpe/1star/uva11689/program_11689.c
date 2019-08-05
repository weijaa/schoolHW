// One-star problem
// Problem 11689 Soda Surpler
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
  int e; // The number of empty soda bottles in Tim¡¦s possession at the start of the day.
  int f; // The number of empty soda bottles found during the day.
  int c; // The number of empty bottles required to buy a new soda.
  int empty; // Number of empty bottles.
  int drinks; // Number of drinks Tim take.
  int new_drinks; // Number of new drinks.
  int i; // Loop variable.
  
  scanf("%d", &cases); // Input number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%d %d %d", &e, &f, &c); // Input data, as described in variable declaration.
    
    empty = e + f; // Total number of bottles in that day.
    drinks = 0; // Initail Tim drinks no soda at all.
    
    while (empty>=c) { // If not enough empty bottles to buy a new soda, stop the loop.
      new_drinks = empty / c; // Number of new drinks Tim can buy.
	  drinks += new_drinks; // Total drinks so far.
	  empty = empty % c + new_drinks; // Number of empty bottles after finishing the new drinks. 
	}
	printf("%d\n", drinks); // Output number of drinks Tim have on that day.
  }
  return 0;
}
