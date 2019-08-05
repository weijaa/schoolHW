// One-star problem
// Problem 11150 Cola
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
  int cola; // The number of bottles of cola to pay.
  int drink; // The number of bottles of cola to drink.
  int empty; // The number of empty bottles remained.
  int borrow; // The number of empty bottles borrowed.
  int cola1, drink1, borrow1; // Original cola, drinks and borrows for later comparison.
  int temp; // Temporary variable for computing drinks.
  
  // We simulate cola drinking without borrowing any bottle to get the number of drinks.
  while (scanf("%d", &cola)==1) { // Input the number of bottles of cola paid.
	// We simulate cola drinking with borrowing 0 bottle to get the number of drinks.
	// The number of bottles is incremented by one in every trail until it is greater
	// than the number of empty bottles at the end of a run. That is, no enough empty
	// bottles to cover the borrowed bottles.
	cola1 = cola; // Remember the original input of cola.
	drink1 = 0; // Initial the maximum drinks to 0.
	for (borrow1=0; ; borrow1++) {
	  cola = cola1; // Original input data.
	  borrow = borrow1;  // Initail borrowed bottles in the simulation.
	  drink = 0; // No drink yet.
	  empty = 0; // No empty bottle yet.
      do { // Simulate the cola drinking.
        drink += cola; // Finish all cola.
        temp = cola; // The number of cola in this run.
        cola = (temp + empty + borrow) / 3; // The number of cola in the next run.
        empty = (temp + empty + borrow) % 3; // The number of empty bottles.
        borrow = 0; // No borrow after the first run.
	  } while (cola>0); // If any cola left, continue.
	  if (borrow1>empty) break; // Stop the trial loop when no enough empty bottles to cover the borrowed ones.
	  if (drink1<drink) drink1 = drink; // If this run get more drinks, set it as the maximum drinks.
	}
	
	printf("%d\n", drink1); // Output the maximum drinks.
  }
  return 0;
}
