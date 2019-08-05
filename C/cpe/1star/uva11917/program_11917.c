// One-star problem
// Problem 11917 Do Your Own Homework!
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

typedef struct {
  char name[21]; // Name of a course Sparrow is comfortable.
  int day; // Days of the course Sparrow needs to complete the homework.
} Course;

int main(void) {
  int cases; // Number of cases.
  
  int course; // Number of courses Sparrow is comfortable with.
  Course *sparrow; // The courses Sparrow is comfortable with.
  char subject[21]; // Subject of the assignment.
  int due_day; // The number of days the assignment is due. 
  const int late=5; // The number of days for late assignment.
  int result; // -1: do your own homework, 1: late, 2: yesss. 
  int i, j; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  sparrow = NULL; // Initial sparrow to the NULL pointer.
  for (i=0; i<cases; i++) { // Process all testing cases.
    scanf("%d", &course); // Input the number of courses Sparrow is comfortable with.
    // Request memory for the courses that sparrow is comfortable with.
    sparrow = (Course *) realloc(sparrow, course * sizeof(Course));
    
    // Input the course name and day Sparrow is comfortable with.
	// We assume no space between course name, such as "operating system". This course
	// is name "os". If there spaces between course name, do not input string, 
	// in stead, scan the string character by character. Then, parse the string.
    for (j=0; j<course; j++) scanf("%s %d", sparrow[j].name, &sparrow[j].day);
    scanf("%d", &due_day); // Input the number of due days.
	scanf("%s", subject); // Input the name of the assignment subject..
	
	result = 0; // Initially, the result is not known yet..
	for (j=0; j<course && result==0; j++) { // When more courses to check and not found.
	  if (strcmp(subject, sparrow[j].name)==0) { // Sparrow is comfortable with this course.
	  	if (due_day>=sparrow[j].day) result = 2; // Sparrow can finish the assignment.
	  	else if (due_day+late>=sparrow[j].day) result = 1; // Sparrow can finish the assignment but late.
	  	else result = -1; // Sparrow cannot finish the assignment.
	  }
	}
	printf("Case %d: ", i+1 ); // Print case index.
	if (result==-1 || result==0) printf("Do your own homework!\n");
	else if (result==1) printf("Late\n");
	else if (result==2) printf("Yesss\n");
  }
  free(sparrow); // Release the dynamic memory.
  return 0;
}
