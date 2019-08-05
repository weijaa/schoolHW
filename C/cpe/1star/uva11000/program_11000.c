// One-star problem
// Problem 11000 Bee
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
  unsigned long long female, male; // Number of female and male bees.
  unsigned long long curr; // Number of female bees this year before birth.
  int years; // Number of years.
  int i; // Loop variable.
  
  while (1) { // Continue until -1 is input.
    scanf("%d", &years);
    
    if (years==-1) break; // When the input is -1, stop the loop and the program terminates.
    female = 1; // Initial number of female bee(s).
    male = 0; // Intial no male bee.
    i = 1; // Start from year 1.
    
    while (i<=years) {
      curr = female;
      female = male + 1;
      male = curr + male;
      i++;
	}
	printf("%llu %llu\n", male, male+female);
  }
  return 0;
}
