// One-star problem
// Problem 11313 Gourmet Games
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
  int n, m; // Input integers n and m.
  int total_show; // Total number of shows.
  int show; // Number of shows in this run.
  
  scanf("%d", &cases); // Input number of cases.
  
  do {
    scanf("%d %d", &n, &m); // Input integers n and m.
    
    total_show = 0; // Clear the number of total show.
    
    while (n>=m) { // Number of candidates is more than m, continue the show.
      show = n / m; // Number of shows in this run.
      total_show += show; // Total number of shows.
      n = show + n % m; // Persons remainded after this run.
	}
    if (n==1) printf("%d\n", total_show); // One winner is produced.
    else printf("cannot do this\n"); // Not enough persons to make a team.
  } while (--cases>0); // Do all the cases.
  return 0;
}
