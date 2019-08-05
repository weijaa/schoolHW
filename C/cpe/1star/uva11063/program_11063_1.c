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
  four elements b[i1], b[i2], b[i3], and b[i4] in the sequence, where b[i1]<b[i2]<=b[i3]<b[i4]
  and b[i1]+b[i4]=b[i2]+b[i3].
*/
int main(void) {
  int cases = 0; // Number of cases.
  int b[100]; // Input numbers, maximum 100 elements.
  int N; // Number of elements.
  int i1, i2, i3, i4; // Pickup four elements from the sequence, b[i1]<b[i2]<=b[i3]<b[i4].
  int is_B2; // Flag to denote a B2 sequence
  int i; // Loop variable.
  
  while (scanf("%d", &N)==1) { // Input the number of elements in the sequence.
    for (i=0; i<N; i++) scanf("%d", &b[i]); // Input N elements.
	// Search if two difference elements are identical.
	is_B2 = 1; // Assume b is a B2 sequence
	
	for (i=1; i<N && is_B2; i++) if (b[i]<=b[i-1]) is_B2 = 0; // Check if b is in the strictly ascending order.
	
	for (i1=0; i1<N-2 && is_B2; i1++)
	  for (i2=i1+1; i2<N-1 && is_B2; i2++)
	    for (i3=i2; i3<N-1 && is_B2; i3++)
	      for (i4=i3+1; i4<N && is_B2; i4++)
			if (b[i1]+b[i4]==b[i2]+b[i3]) is_B2 = 0;
	  
	// Print the result.
	if (!is_B2) printf("Case #%d: It is not a B2-Sequence.\n\n", ++cases);
	else printf("Case #%d: It is a B2-Sequence.\n\n", ++cases);
  }
  return 0;
}
