// Two-star problem
// Problem 11286 Conformity
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
  int students; // Number of students;
  int enrollment[10000][5]; // Maximum 10000 students, each student takes five courses.
  int selected[10000]; // Indicate the student's course has been selected in a combination.
  int most_popular; // The combination has the most combination so far.
  int popular_count; // The count of the most popular combination.
  int combination; // Number of students with the the current combination.
  int same; // The same combination.
  int temp; // Temporary varialbe for swapping course numbers.
  int i, j, k; // Loop vairables.
  
  while (1) { // Continue, when the input student number is not zero.
    scanf("%d", &students); // Input the number of students.
    if (students==0) break; // If the input number is 0, stop the loop and terminate the program.
    for (i=0; i<students; i++) { // Input student's courses and sort the courses.
      for (j=0; j<5; j++) scanf("%d", &enrollment[i][j]); // Input five course numbers.
      // Sort the courses in the ascending order of the course numbers.
      for (j=4; j>=1; j--) 
        for (k=1; k<=j; k++) {
          if (enrollment[i][k-1]>enrollment[i][k]) { // Swapping operation.
            temp = enrollment[i][k-1];
            enrollment[i][k-1] = enrollment[i][k];
            enrollment[i][k] = temp;
		  }
		}
	}
	
	for (i=0; i<students; i++) selected[i] = 0; // Mark all students as unselected in any combination.
    most_popular = 0; // The combination has the most combination so far.
    popular_count = 0; // The count of the most popular combination.
	
	for (i=0; i<students; i++) { // Check combinations by all sutdents.
	  if (selected[i]==0) { // If the students cousrses is not selected, check this combination.
	    selected[i] = 1; // Mark this student's combination as selected.
	    combination = 1; // Count one student in this combination.
	    for (j=i+1; j<students; j++) { // Check all students after this one.
	      if (selected[j]==0) { // If this student's courses are not selected in previous combination.
	        same = 1;
	        for (k=0; k<5 && same; k++) if (enrollment[i][k]!=enrollment[j][k]) same = 0; // Not the same combination.
	        if (same) {
	          combination++; // Increment the student count of the current combination.
			  selected[j] = 1; // Student j is selected in this combination.
			}
	      }
	    }
        if (combination>most_popular) { // The current combination is the most popular one.
          most_popular = combination; // Update the most popular combination.
          popular_count = 1; // One combination is the most popular. 
		}
		else if (combination==most_popular) // Same as the most popular combination.
		  popular_count++; // Add one more combination to the popular count.
	  }
    }
    printf("%d\n", most_popular * popular_count); // Output the number of students taking most-popular combinations.
  }
  return 0;
}
