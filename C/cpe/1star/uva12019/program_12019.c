// One-star problem
// Problem 12019 Doom's Day Algorithm
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
  int ww; // Use January 1st as the reference day. 
  // Days of 12 months.
  const int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  // Names of 7 weekdays.
  const char *name_of_weekday[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                    "Thursday", "Friday", "Saturday"};
  
  int month, day; // Input month and day.
  int count; // Day count.
  int i, j; // Loop variable.
  
  // April 4th being Monday, count back 3 days in April, 31 days in March, 28 days in
  // February, and 31 days in January. The negative number modulo 7 is -6 to 9, add 7
  // to adjust it to the possitive number. The value is 6, i.e., January 1st 2011 is
  // Saturday. We use this day as the reference day.
  ww = 7 + (1 - 3 - 31 - 28 - 31) % 7;  
  
  scanf("%d", &cases); // Input number of cases.
  
  for (i=0; i<cases; i++) { // Process all testing cases.
    scanf("%d %d", &month, &day); // Input month and day.
    count = 0; // Initial day count to 0.
    // Count to a month before the input month.
    for (j=0; j<month-1; j++) count += days_of_month[j];
    // Add the input days of that month and minus 1 because we count the
    // number of days after January 1.
    count += day - 1;
    // ww is 6 for January 1, calculate the day of weekday.
    // Output the weekday.
    printf("%s\n", name_of_weekday[(count+ww) % 7]);
  }
  return 0;
}
