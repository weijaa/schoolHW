// One-star problem
// Problem 10300 Ecological Premium
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
  int farmers; // Number of formers.
  int farmyard, animals, environment; // Size of farmyard, number of animals, and environment-friendliness.
  float premium; // Total premium.
  int i, j; // Loop vairables
  
  scanf("%d", &cases); // Input number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%d", &farmers); // Input number of farmers.
    premium = 0;
    for (j=0; j<farmers; j++) {
      // Input size of farmyard, number of animals, and environment-friendliness.
      scanf("%d %d %d", &farmyard, &animals, &environment) ;
      // Compute and sum up the premium.
      premium += (int) (((float) farmyard / animals) * environment * animals);
	}
	printf("%d\n", (int) premium); // Print the total permium.
  }
  return 0;
}
