// Two-star problem
// Problem 10295 Hay Points
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
  char job[17]; // Term of a job, maximum 16 lower case letters.
  float value; // Value of the job.
} Hay;

// Use binary search to find the value of a description word.
float in_dictionary(Hay *dictionary, int m, char *word) {
  int low=0, high=m-1; // Low index and high index in the segment of dictionary to search.
  int mid; // Middle element index.
  int relation; // String comparison relation. 
  
  while (low<=high) { // the segment is not empty.
    mid = low + (high - low) / 2; // Middle element index.
    relation = strcmp(dictionary[mid].job, word); // Relation of string comparison.
    if (relation==0) return dictionary[mid].value; // The word has found, return the value.
    else if (relation<0) low =  mid + 1; // Search the right half 
    else high = mid - 1; // Search the left half.
  }
  return 0; // Search fails, return value 0.
}

int main(void) {
  Hay dictionary[1000]; // Maximum 1000 job description words in the dictionary.
  int m; // Number of entries in the dictionary;
  int n; // Number of job descriptions in the testing case.
  char word[18]; // A single word of the input job description; one letter more than job.
  float salary; // Salary of a job description.
  char temp_job[17]; // Temporary job name for swap operation.
  float temp_value; // Temporary job value for swap operation.
  int i, j; // Loop variable.
  
  scanf("%d %d", &m, &n); // Input two integers m and n.
  
  for (i=0; i<m; i++) // Input the job and value of the Hay Point dictionary.
    scanf("%s %f", &dictionary[i].job, &dictionary[i].value);
    
    // Sort the dictionary entry according to the alphabetical order of the job names.  
    for (i=m-1; i>1; i--)
      for (j=1; j<=i; j++)
        if (strcmp(dictionary[j-1].job, dictionary[j].job)>0) { // Two job names out of order.
          strcpy(temp_job, dictionary[j-1].job); // Perform the swap operation.
          temp_value = dictionary[j-1].value; // Copy the Hay structure.
          strcpy(dictionary[j-1].job, dictionary[j].job);
          dictionary[j-1].value = dictionary[j].value;
          strcpy(dictionary[j].job, temp_job);
          dictionary[j].value = temp_value;
	    }
	  
    for (i=0; i<n; i++) { // Prcess all job description in the testing case.
      salary = 0;
      scanf("%s", word); // Input a word of the job description.
      while (strcmp(word, ".")!=0) { // Continue, until a period is read.
        // If the description word is in the dictionary, add its value to salary;
		// otherwise, the value is 0.
        salary += in_dictionary(dictionary, m, word);
        scanf("%s", word); // Input the next word of the job description.
      }
      printf("%d\n", (int) salary); // Output the salary of the job description.
    }
  return 0;
}
