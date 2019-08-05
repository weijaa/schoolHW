// One-star problem
// Problem 10050 Hartals
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
  int cases; // Number of testing cases
  int days; // Number of days to be simulated.
  int parties; // Number of parties to be simulated
  int hartal[100]; // Average hartals of all parties.
  int lost_working_day; // Number of lost working days.
  int lost; // A hartal day or not. 
  int c, i, j; // Loop variables.
  
  scanf("%d", &cases); // Input the number of testing cases.
  
  for (c=0; c<cases; c++) {
  	scanf("%d", &days); // Input the number of days to be simulated.
  	scanf("%d", &parties); // Input the number of parties to be simulated.
  	
  	for (i=0; i<parties; i++) scanf("%d", &hartal[i]); // Input the average hartals of all parties.
  	
  	lost_working_day = 0; // Initial the lost working days to 0.
  	for (i=1; i<=days; i++) { // Check all days to be simulated.
  	  if (i%7!=6 && i%7!=0) { // Don't check Friday and Saturday.
  	    lost = 0; // Assume this day is not lost.
  	    // If this day is a hartal for any party, it is lost.
  	    for (j=0; j<parties && !lost; j++) lost = lost || (i%hartal[j]==0); 
  	    lost_working_day = lost_working_day + lost; // Update the lost working days.
	  }	
	}	
	printf("%d\n", lost_working_day); // Output the number of lost working days.
  }
  return 0;
}
