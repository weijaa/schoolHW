// Two-star problem
// Problem 10137 The Trip
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
  int n; // Input n, number of students
  float amount[1000]; // No more than 1000 students.
  float total; // Total amount.
  float average; // Average amount.
  int average_int; // Integer of average*100.
  float low_exchange, high_exchange; // The amount of money to be exchanged below and above average..
  int i; // Loop variable.
  
  while (1) { // Continue, the input number of students is 0.
    scanf("%d", &n); // Input number of students.    
    if (n==0) break; // If the number of students is 0, stop the loop and terminate the program.
    
    total = 0; // Reset total to 0.
    for (i=0; i<n; i++) {
	  scanf("%f", &amount[i]); // Input the amount of money of all students.
	  total += amount[i]; // Accumulate the amount.
    }
    average = total / n; // Average amount.
    average_int = (int) (average * 100.00); // Count to cents, consider 2 digits after the decimal point.
    if (average-average_int>0.0) average_int++; // Round the digit after cent.
    average = average_int / 100.00; // Convert average back to fixed-point number to cents only.
    
    // Reset both exchanges to 0.
    low_exchange = 0.0;
    high_exchange = 0.0;
    for (i=0; i<n; i++)
	  if (amount[i]<average) low_exchange += average - amount[i];
	  else if (amount[i]>average) high_exchange += amount[i] - average;
    
    if (low_exchange<high_exchange) // Output the smaller amount of exchange.
      printf("$%4.2f\n", low_exchange);
    else 
      printf("$%4.2f\n", high_exchange);
   }   
  return 0;
}
