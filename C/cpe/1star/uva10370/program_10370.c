// One-star problem
// Problem 10370 Above Average
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
  int students; // Number of students.
  int score[1000]; // No more than 1000 students in a test.
  int total; // Total score in a test;
  float average; // Average score of a test.
  int over_average; // Number of students over the average.
  int i, j; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  for (i=0; i<cases; i++) { // Process all cases.
  	total = 0; // Reset the total score to 0.
  	over_average = 0; // Reset the number of students over the average to 0.
  	scanf("%d", &students); // Input the number of students.
  	for (j=0; j<students; j++) {
  	  scanf("%d", &score[j]); // Input test score of student j.
  	  total += score[j]; // Sum up the total score.
	}
	average  = (float) total / students; // Compute the average score, floating point value.
	// Count the number of students over the average.
	for (j=0; j<students; j++) if (score[j]>average) over_average++;
	// Output the percentage of students over the average.
	printf("%5.3f%%\n", (float) over_average / students * 100.0); 
  }
  return 0;
}
