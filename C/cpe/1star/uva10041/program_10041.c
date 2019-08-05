// One-star problem
// Problem 10041 Vito¡¦s Family
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
#include <math.h>

int main(void) {
  int relative[500];
  int cases, count, median, distance, temp;
  int i, j, c;
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (c=0; c<cases; c++) { // Process all cases.
    scanf("%d", &count); // Input the of relatives.
    
    for (i=0; i<count; i++) scanf("%d", &relative[i]); // Input the stree numbers of all relatives.
    
    // Sort the relative's stree numbers.
    for (i=count-1; i>0; i--)
      for (j=1; j<=i; j++) {
      	if (relative[j-1]>relative[j]) { // Compare and swap operation.
      	  temp = relative[j-1];
      	  relative[j-1] = relative[j];
      	  relative[j] =temp;
		}
	  }
    
    // The minimal sum is to start from the relative at the median position. 
    if (count%2==0) median = count / 2 ;
    else median = (count + 1) / 2;
    distance = 0; // Initial distance to 0.
    for (i=0; i<count; i++) distance = distance + abs(relative[i] - relative[median]); // Compute the total minimal distances.
    
    printf("%d\n", distance); // Print the total minimal distance.    
  }
  return 0;
}
