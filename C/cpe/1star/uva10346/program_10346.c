// One-star problem
// Problem 10346 Peter's Smokes
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
  int n, k; // The input data.
  int smoke; // The number of cigarettes Peter smokes.
  
  while (scanf("%d %d", &n, &k)==2) { // Input n and k, if there is any.
    // At the beginning there is not cigarette butt and Peter smokes no cigarette.
    smoke = 0; 
    while (n>=k) { // When n+butt<k, the total butt is not enough to roll a cigarette.
      // At each round, Peter smokes n-n%k so the new butts are just enough
	  // to roll a number of cigarettes.
      smoke = smoke + n - n % k; 
      // After Peter finish smoking at this round, n%k cigarettes are left;
      // and the number butts is the number of cigarettes he smokes, just enough to
      // roll (n-n%k)/k new cigarettes.
      n = (n % k) + (n - n % k) / k; // The number of cigarettes at the end of this round.      
    }
    // Peter smokes the rest of cigarettes, but the butts are not enough to roll a
    // new cigarette. Hence, Peter has finished all the cigarettes, the original ones and
    // the re-rolled ones. 
    smoke =  smoke + n; 
    printf("%d\n", smoke); // Output the result.
  }
  return 0;
}
