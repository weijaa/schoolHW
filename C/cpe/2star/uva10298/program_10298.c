// Two-star problem
// Problem 10298 Power Strings
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

int main(void) {
  char s[1000001]; // The input string, not exceed 1 million characters.
  char letter[2]; // A string of single character for searching next substring.
  int length; // Length of string s.
  int sublength; // Length of a substring.
  char **subs; // A collection of substrings of s, each of length sublength.
  int subcount; // The number of substings in subs[].
  int max_subcount; // The maximum number of substings in subs[].
  int incremental = 10;
  int n; // Maximum power.
  int power; // Power of the current substring.
  int inx; // The character index of the current substring.
  int next; // The character index of the next substring in searching.
  int duplicate; // 0: no duplicate substring; 1: otherwise.
  int i; // Loop variable.
  
  while (1) { // Continue until the input string is a period.
    scanf("%s", s); // Input a testing string.
    if (strcmp(s, ".")==0) break; // If the string is a period, stop the loop.
    
    length = strlen(s); // Number of characters in string s.
    sublength = 1; // Start subsrtings with length 1.
    subcount = 0; // No substring yet.
    max_subcount = incremental; // Initially, "incremental" (10) substrings.
    // Allocate memory for comparing substrings.
    subs = (char **) malloc(sizeof(char *) * max_subcount);
    for (i=0; i<max_subcount; i++)
	  subs[i] = (char *) malloc(sizeof(char) * (sublength + 1));
    n = 1; // Initialize maximum power to 1.
    inx = 0; // Start from the first character of the string.
    next = 1; // Next character to be checked.
    power = 0; // Initial power to 0.
    
    // Continue, if the maximum power of substring can be larger than the current maximum power.
    while ((length-inx)/sublength>n) {
      strncpy(subs[subcount], s+inx, sublength); // Copy a substring to compare.
      subs[subcount++][sublength] = '\0'; // Add end-of-string.
      
	  // If the memory of the substring is full, request more memory.
      if (subcount==max_subcount) {
      	max_subcount += incremental; // Increase the maximum substring count.
      	subs = (char **) realloc(subs, sizeof(char *) * max_subcount); // Ask for more entries.
      	// Request memory for the  newly created pointers.
        for (i=max_subcount-incremental; i<max_subcount; i++)
		  subs[i] = (char *) malloc(sizeof(char) * (sublength + 1)); // The string space may change.
	  }
      
      duplicate = 0; // Check duplication.
      // If the current substring is identical to one of the previous sbustrings, 
	  // it is duplicated.
      for (i=0; i<subcount-1 && !duplicate; i++)
	    if (strcmp(subs[i], subs[subcount-1])==0) duplicate = 1;
       
	  if (!duplicate) { // The substring is not a duplication. Start search the power.
	    power = 1; // Reset power to 1.
	    next = inx + sublength; // The search begins after the substring cosidered.
	    // If the remainding string is longer than the length, search continue. 
	    while (next+sublength<=length) {
	      // If there is a matching of characters in s and the substring,	
	      if (strncmp(subs[subcount-1], s+next, sublength)==0) { 
	      	power++; // Increment the power.
	      	next += sublength; // Move to the next character postition.
		  }
		  // If the substring does not match,
		  else {
		  	// If the previous power is larger than the maximum power, update the maximum powers.
		  	if (n<power) n = power;
		  	power = 0; // Reset power to 0.
		  	// Do not back track to the substring in the power, because it covered by
			// a substring of subs[subcount] in the previous checks.
		  	next++; 
		  }
		}
		// When approaching the end s, check it the current power is the maximum power.
		if (n<power) n = power; // If yes, update the maximum power.
		power = 0; // Reset power to 0.
	  }
	  else {
	  	subcount--;
	    inx++; // Move to the index of the next substring candidate.
	    // Check the substring start from the next character.
	    // If the number remainding charactrs is not long enough to be a power n with
	    // substrings sublength. 
	    // Increase the length of substring by 1 and start over from the beginning of
	    // the entire string.
	    if ((length-inx)/sublength<=n) {  
	  	  sublength++; // Increment the substring length by 1.
	  	  inx = 0; // Start over from the beginning of s.
	    }
      }
	}
	printf("%d\n", n); // Output the maximum power.
  }
  return 0;
}
