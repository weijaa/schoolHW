// Two-star problem
// Problem 10340 All in All
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
#define incremental 100

// We assume the length of s and t are uncertain. Hence, it is not practical to use a fixed size
// array to store s and t. A reasonable apprach is to store s and t in the dynamic memory.
// Strings s and t are separated by a white space, 0X20, and end with a newline, 0X0A.
int main(void) {
  char *s, *t; // Pointers to string s and t.
  int size_s, size_t; // Size of arrays for s and t, initial to 100 (incremental).
  int leng_s, leng_t; // Length of string s and t.
  int is_subsequence; // 1: s is a subsequence of t; 0: otherwise.
  int i, j; // Indices of s and t.
  
  do { // Continue until reaching end of file.
  	size_s = incremental; // Initial array size of string s.
  	size_t = incremental; // Initial array size of string t.
  	s = (char *) malloc(sizeof(char) * size_s); // Allocate memory for string s.
  	t = (char *) malloc(sizeof(char) * size_t); // Allocate memory for string t.
  	
  	// Input string s until a white space, 0X20.
  	i = 0; // Initial string index of s.
  	while ((s[i++] = getchar())!=0X20) { // Input a character until ' '.
  	  if (i==size_s) // When the array is full, get more memory.
  	    size_s += incremental; // Increase the array size.
  	    s = (char *) realloc(s, sizeof(char) * size_s); // Request additional memory for s.
	}
	leng_s = i; // Length of string s.
	s[i-1] = '\0'; // Insert end-of-string.
	
  	// Input string t until a white space, 0X0A, or reaching EOF.
  	j = 0; // Initial string index of s.
  	while ((t[j++] = getchar())!=0X0A && !feof(stdin)) { // Input a character until '\n' or EOF.
  	  if (j==size_t) // When the array is full, get more memory.
  	    size_t += incremental; // Increase the array size.
  	    t = (char *) realloc(t, sizeof(char) * size_t); // Request additional memory for t.
	}
	leng_t = j; // Length of string t.
	t[j-1] = '\0'; // Insert end-of-string.
	
  	is_subsequence = 0; // Assume s is not a subsequence of t.
  	i = 0; // Start from the first character of s.
  	j = 0; // Start from the first character of t.
  	while (!is_subsequence && j<leng_t) { // Continue until find s is a subequence of t or reach the end of t.
	  if (s[i]==t[j]) {i++; j++;} // Match a character of s in t.
	  else j++; // Unmatching characters, try the next one of t.
	  if (i==leng_s) is_subsequence = 1; // Match all characters of s, it is a subseuence of t.
    }
    
    // Output the result.
    if (is_subsequence) printf("Yes\n"); // Yes, s is a subsequence of t.
    else printf("No\n"); // No, s is not a subsequence of t.
    free(s); // Release the memory of s.
    free(t); // Release the memory of t.
  } while (!feof(stdin)); // Stop, when reach end-of-file.
  return 0;
}
