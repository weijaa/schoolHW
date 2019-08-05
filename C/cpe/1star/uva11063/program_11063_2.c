// One-star problem
// Problem 11063 B2-Sequence
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

/*
  Sequence b[1], b[2], b[3], ..., b[n] is a B2 sequence, if and only if there do not exist any
  four elements b[i1], b[i2], b[i3], and b[i4] in the sequence, where b[i1]<=b[i2]<b[i3]<=b[i4]
  and b[i1]+b[i4]=b[i2]+b[i3].
*/
int main(void) {
  int cases = 0; // Number of cases.
  int b[100]; // Input numbers, maximum 100 elements.
  int sum[20000]; // The maximum value of the sum of two digits is 19999.
  int N; // Number of elements.
  int is_B2; // Flag to denote a B2 sequence
  int i, j; // Loop variables.
  
  while (scanf("%d", &N)==1) { // Input the number of elements in the sequence.
    for (i=0; i<N; i++) scanf("%d", &b[i]); // Input N elements.
	// Search if two difference elements are identical.
	is_B2 = 1; // Assume b is a B2 sequence
	
	for (i=1; i<N && is_B2; i++) if (b[i]<=b[i-1]) is_B2 = 0; // Check if b is in the strictly ascending order.
	
	// Use array sum to mark value of two digit sum. Value 0 means unmarked.
	for (i=0; i<20000; i++) sum[i] = 0;
	
	for (i=0; i<N-1 && is_B2; i++) // Scan all b[i] for i from 0 to N-2 and check is_B2.
	  for (j=i+1; j<N && is_B2; j++) // Scan all b[j] for j from j+1 to N-1 and check is_B2.
	    // Check whether b[i]+b[j] appears before or not.
	    if (sum[b[i]+b[j]]==0) sum[b[i]+b[j]] = 1; // If not, mark sum b[i]+b[j];
	    else is_B2 = 0; // otherwise, the input data is not a B2 sequence and stop the loop.
	  
	// Print the result.
	if (!is_B2) printf("Case #%d: It is not a B2-Sequence.\n\n", ++cases);
	else printf("Case #%d: It is a B2-Sequence.\n\n", ++cases);
  }
  return 0;
}
