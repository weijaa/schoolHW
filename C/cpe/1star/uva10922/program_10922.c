// One-star problem
// Problem 10922 2 the 9s
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

// Computing digit sum. A number is represented as a string.
// The return result if the sum of digits represented in a string.
char *digit_sum(char *str) {
  int sum = 0; // Digit sum.
  int length = strlen(str); // String length
  int i; // Loop variable.
  
  for (i=0; i<length; i++) sum = sum + str[i] - '0'; // Compute the sum of all digits.
  length = 0; // Convert the digit sum to string.
  while (sum>0) {
  	str[length++] = sum % 10 + '0'; // Turn a single decimal value to a character. 
  	sum = sum / 10;
  }
  str[length] = '\0'; // End of string. 
  return str;
}

// Recursive function of 2_the_9s.
// Retrun -1 if n is not a multiple of 9.
// Retrun degree of 2_the_9s, if n is a multiple of 9.
int degree_2_the_9s(char str[]) {
  int degree;
  
  if (strlen(str)==1) // One-digit left, base case.
    if (str[0]=='9') degree = 0; // str is a multiple of 9.
    else degree = -1; // str is not a multiple of 9.
  else degree = degree_2_the_9s(digit_sum(str)); // Recursive case.
  if (degree<0) return degree; // Not a multiple of 9.
  else return degree + 1; // Retrun the 9-degree.  
}

// Since the number could be up to 1000 digits, a string is used to represent number N.
// If N>9 and is a multiple of 9, the degree counts only the number of recursive calls.
// To be consistent, the 9-degree of number 9 should be 0.
int main(void) {
  char N[1001]; // Input integer.
  int degree; // 9-degree.
  
  while (scanf("%s", &N)==1) {
  	if (strcmp(N, "0")==0) break; // The input is 0, stop the loop and terminate the program.
  	printf("%s ", N); // Outupt the number.
  	degree = degree_2_the_9s(N); // Compute the 9-degree of N.
  	if (degree<0) printf("is not a multiple of 9.\n"); // N is not a multiple of 9.
  	else if (degree==1) printf("is a multiple of 9 and has degree 1\n"); // N is 9, non-recursive call.
  	else printf("is a multiple of 9 and has 9-degree %d\n", degree-1); // N>9, only count the number of recursive calls.
  }
  return 0;
}
