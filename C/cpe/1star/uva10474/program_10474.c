// One-star problem
// Problem 10474 Where is the Marble?
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
  int marbles, queries; // No of marbles and queries. The input data.
  int *numbers; // The pointer of an array to hold the numbers marked on marbles. Use dynamic array.
  int max_marbles = 100; // Maximum number of marbles, initial value is 100. Can be extended.
  int query; // The queried number. 
  int case_index = 1; // Case index, starting from 1.
  int temp; // For swap operation.
  int low, high, mid; // Variables for performing binary search.
  int found; // Found flag for binary search.
  int i, j; // Loop variables.
  
  /* We use dynamic array to hold the number of marbles. At the beginning, the maximum
     number of marbles is set to 100 and an arry of 100 elements is allocated. As the
     program proceeds, when the number of marbles is larger than the maximum number of 
     marbles, more memory is reallocated to hole the marbles.
  */
  numbers = (int *) calloc(max_marbles, sizeof(int));
  while (1) { // This is an infinite loop. The program terminates when 0 0 are input
    scanf("%d %d", &marbles, &queries); // Input the number of marbles and the number of queries.
    if (marbles==0 && queries==0) {
	  free(numbers); // Release the dynamic memory.
	  break; // If both values are 0, break the out most loop and terminate the program.
    }
	
	printf("Case# %d:\n", case_index++); // Output case number.    
    if (marbles>max_marbles) { // If the number of marbles is greater thant the maximum value.
	  max_marbles = marbles; // Redefine the maximum number of marbles.
	  numbers = (int *) realloc(numbers, max_marbles * sizeof(int)); // Request extra memory space.
	}
    
    for (i=0; i<marbles; i++) scanf("%d", &numbers[i]); // Input the numbers of all marbles.
    
    // Use the insertion sort algorithm to sort the number on marbles.
    for (i=marbles-1; i>0; i--) 
      for (j=1; j<=i; j++) 
        if (numbers[j-1]>numbers[j]) { // Compare swap operation.
      	  temp =  numbers[j-1];
      	  numbers[j-1] =  numbers[j];
      	  numbers[j] = temp;
	    }
	
	for (i=0; i<queries; i++) { // Process all queries.
	  scanf("%d", &query); // Input a query.
	  low = 0; // Low index for all marbles.
	  high = marbles - 1; // High index for all marbles.
	  found = 0;
	  while (!found && low<=high) {
        mid = low + (high - low) / 2;
        if (numbers[mid]==query) found = 1;
        else if (numbers[mid]>query) high = mid -1;
        else low = mid + 1;
      }
      if (found) { // Search for the smallest index of matching marble.
        for (j=mid; j>0; j--) if (numbers[j-1]!=query) break;
        printf("%d found at %d\n", query, j+1); // Marble index starts from 1.
	  }
	  else printf("%d not found\n", query); // The queried marble is not found.
	}
  }
  return 0;
}
