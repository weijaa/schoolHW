// One-star problem
// Problem 11005 Cheapest Base
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
#include <string.h>

int main(void) {
  int cases; // Number of cases.
  int weight[36]; // Weight of numeral digits and alphabets.
  int cheapest[36]; // The bases with the cheapest cost.
  int cost; // The cheapeast cost. 
  int base; // Base under cost evalution.
  int queries; // Number of queries.
  int N; // The querying number. 
  int cost_N; // Cost of N using a base.
  int rest_N; // Resting value of N during evaluation.
  int i, j, k; // Loop variables.
  
  scanf("%d", &cases); // Input number of cases.
  
  for (i=0; i<cases; i++) { // Perform all cases.
    for (j=0; j<36; j++) scanf("%d", &weight[j]); // Input the weights of the 36 digits;
    scanf("%d", &queries); // Input the number of queries.
    printf("Case %d:\n", i+1); // Output the case index.
    for (j=0; j<queries; j++) { // Process all queries.
      scanf("%d", &N); // Input a querying number.
      for (base=2; base<=36; base++) {
      	cost_N = 0; // Initial cost of the representation of n under the "base".
      	rest_N = N; // Resting value of n during evluation of the cost.
      	while (rest_N>0) {
		  cost_N += weight[rest_N % base]; // Evaluate the cost of a digit for n.
		  rest_N = rest_N / base; // Move to the next digit of n.
	    }
      	if (base==2) { // The first base.
      	  cost = cost_N; // Set the first cost as the cheapest cost.
      	  for (k=0; k<36; k++) cheapest[k] = 0; // Clear mark the cheapest cost.
      	  cheapest[base-1] = 1; // Mark 2 as the cheapest cost.
		  }
		else {
		  if (cost_N<cost) { // A new cheapest cost is found.
      	    cost = cost_N; // Set the this cost as the cheapest cost.
      	    for (k=0; k<36; k++) cheapest[k] = 0; // Clear mark the cheapest cost.
      	    cheapest[base-1] = 1; // Mark this base as the cheapest cost.
		  }
		  else if (cost_N==cost) cheapest[base-1] = 1; // Mark this base as the cheapest cost.
		}      	
	  }
	  printf("Cheapest base(s) for number %d:", N); // Output the cheapest base text.
	  for (base=2; base<=36; base++)
	    if (cheapest[base-1]==1) printf(" %d", base); // Print the bheapest base. 
	  printf("\n");	// Print a new line at the end of each query.
 	}
	printf("\n"); // Print a new line at the end of each case.
  }
  return 0;
}
