// Two-star problem
// Problem 10013 Super Long Sums
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

typedef char *Number; // Data type, same as a character pointer.

// Addition operation using strings.
Number add(Number op1, Number op2) {
  Number sum; // op1+op2
  int l1=strlen(op1), l2=strlen(op2), lsum, lsum1; // String lengths.
  int t1, t2, t, carry = 0; // One digit addition: t=t1+t2+carry.
  int i = 0; // Loop variable.
  
  lsum = (l1>l2) ? l1 : l2; // Maximum value of l1 and l2.  
  lsum1 = lsum; // For later reuse of the maximum length.
  sum = (Number) malloc(lsum + 1); // Allocate memory for the sum.
  
  sum[lsum] = '\0'; // End of string.
  while (lsum>0) { // add all digits from right to left.
  	t1 = (l1>0) ? op1[--l1] - '0' : 0; // Get a digit of op1, if there is any.
  	t2 = (l2>0) ? op2[--l2] - '0' : 0; // Get a digit of op2, if there is any.
  	t = t1 + t2 + carry; // Add two single digits with carry.
  	carry = t / 10; // New carry.
  	sum[--lsum] = t % 10 + '0'; // Sum of the digit, in ASCII code format.
  }
  if (carry==1) { // If carry is 1,put this carry to the leading digit of sum.
    sum = (Number) realloc(sum, lsum1 + 2); // Expand the memory of sum one more byte.
    for (i=strlen(sum); i>=0; i--) sum[i+1] = sum[i]; // Move the digits one position to left.
    sum[0] = '1'; // Plcase '1' at the leaFding digit position.
  }
  return sum; // Return the sum.
}

Number remove_leading_zero(Number n) {
  while (n[0]=='0') strcpy(n, n+1); // If the first letter is '0' remove it.
  return n; // The result could be the empty string.
}

int main(void) {
  int cases; // Number of cases;
  int length; // Length of digits of the input numbers.
  int digit1, digit2;
  Number n1, n2; // Two input numbers.
  Number answer; // The answer: sum of two numbers, i.e., answer=n1+n2.
  int c, i; // Loop variables.
  
  scanf("%d", &cases); // Input number of cases.
  
  // Initial both n1 and n2 to the NULL pointer.
  n1 = NULL;
  n2 = NULL;
  
  for (c=0; c<cases; c++) { // Process all cases.
    scanf("%d", &length); // Input length of the digits.
    
    // Allocate memory for numbers n1 and n2.
    n1 = (char *) realloc(n1, sizeof(char) * (length + 1));
    n2 = (char *) realloc(n2, sizeof(char) * (length + 1));
    // Input the digits of n1 and n2.
    for (i=0; i<length; i++) {
      scanf("%d %d", &digit1, &digit2);
      n1[i] = digit1 + '0';
      n2[i] = digit2 + '0';
	}
    n1[i] = '\0'; // Insert end of string.
    n2[i] = '\0'; // Insert end of string.
    
    // Remove leading zeros from n1 and n2.
    remove_leading_zero(n1);
    remove_leading_zero(n2);
    
    answer = add(n1, n2); // answer=n1+n2;
    printf("%s\n\n", answer); // Output the answer.
    free(answer); // Release memory of answer.
  }
  // Release memory of n1 and n2.
  free(n1);
  free(n2);
  return 0;
}
