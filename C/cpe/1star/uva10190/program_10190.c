// One-star problem
// Problem 10190 Divide, But Not Quite Conquer!
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
  int m, n; // Maximum value of m and n is 2,147,483,647 which is greater than 2000000000.
  int term; // The term for consecutive division.
    
  while (scanf("%d %d", &n, &m)==2) { // Read in m and n if there are more input data.
    term = n; // Initail the first element of the sequence a1=n.
    while (term!=1) { // When the element of the sequence reaches 1, succeed and stop.
      if (term%m==0) { // If a[i] is divisible by m,
      	term = term / m; // Set the next term a[i+1] to be term / m.
	  }
      else break; // If a[i] is not 1 and not divided by m, fail and stop.
	}
	if (term==1) { // This means the sequence exists.
	  term = n; // Initial a[1].
	  printf("%d ", term); // Print a[1].
	  while (term!=1) { // a[i]!=1, continue.
	    term = term / m; // Compute a[i+1].
	    printf("%d ", term); // Print a[i+1].
	  }
	  printf("\n"); // Print a new line.
	}
	else printf("Boring!\n"); // The process fails, print "Boring!".
  }
  return 0;
}
