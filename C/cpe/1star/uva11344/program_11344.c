// One-star problem
// Problem 11344 The Huge One
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

// Addition operation using strings. Used of trail+trail.
void times2(char *op) {
  int value = (op[0] - '0') * 2;
  
  if (value>=10) {
  	op[0] = '1';
  	op[1] = (value - 10) +'0';
  	op[2] = '\0';
  }
  else {
    op[0] = value +'0';
  	op[1] = '\0';
  }
}

// Subtraction operation using strings.
void minus(char *op1, char *op2) {
  char diff[1002]; // op1-op2
  int l1=strlen(op1), l2=strlen(op2), ldiff, ldiff1; // String lengths.
  int t1, t2, t, borrow = 0; // One digit subtraction: t=t1-t2-borrow.
  int i = 0; // Loop variable.
  
  ldiff = l1; // Maximum length is l1.
  ldiff1 = ldiff; // For later reuse of the maximum length.
  
  diff[ldiff] = '\0'; // End of string. 
  while (ldiff>0) { // add all digits from right to left.
  	t1 = op1[--l1] - '0'; // Get a digit of op1, if there is any.
  	t2 = (l2>0) ? op2[--l2] - '0' : 0; // Get a digit of op2, if there is any.
  	t = t1 - t2 - borrow; // Add two single digits with carry.
  	if (t<0) {
	  borrow = 1; // New borrow.
  	  diff[--ldiff] = 10 + t + '0'; // Difference of the digit, in ASCII code format.
    }
    else {
      borrow = 0; // No new borrow.
  	  diff[--ldiff] = t + '0'; // Difference of the digit, in ASCII code format.
	}
  }
  while (diff[0]=='0') strcpy(diff, diff+1); // If the first digit of the difference is '0' remove it.
  strcpy(op1, diff); // Place the difference in op1. 
}

int main(void) {
  int cases; // Number of cases.
  int set[12]; // Elements in the interval.
  int count; // Number of elements in the interval.
  char M[1002]; // String representing the large integer to be tested, maximum 1001 digits.
  char trail[3]; // Trailing digit for computing multiple of 7.
  unsigned int digit_sum; // Summation of all digits.
  int sign; // Sign mark 1 or -1.
  int simple; // 0: Wonderful, 1: Simple.
  int i, j, k; // Loop varaible.
  
  scanf("%d", &cases); // Input number of cases.
  
  for (i=0; i<cases; i++) { // Test all cases.
    scanf("%s", M); // Input the possible very long integer as a string.
    scanf("%d", &count); // Input number of elements in the set.
    for (j=0; j<count; j++) scanf("%d", &set[j]);
    
    for (j=0; j<count; j++) {
      simple = 0;
      switch (set[j]) {
      	// Any integer is a multiple of 1.
      	case 1: {
		  break;
		}      	
		// If the last digit of M is a multiple of 2, M is a multiple of 2.
      	case 2: {
      	  if ((M[strlen(M)-1]-'0')%2!=0) simple = 1; // If odd, it is simple.
		  break;
		}		
		// If the sum of all digits is a multiple of 3, M is a multiple of 3.
      	case 3: {
      	  digit_sum = 0;
      	  for (k=0; k<strlen(M); k++) digit_sum += M[k] - '0'; // Sum all the digits of M.
      	  if (digit_sum%3!=0) simple = 1; // Sum of digits is not a multiple of 3.
		  break;
		}		
		// If the last two digits of M is a multiple of 4, M is a multiple of 4.
      	case 4: {
      	  // The last two digits of M is not a multiple of 4.
      	  if (strlen(M)>=2) {
      	    if (((M[strlen(M)-2]-'0')*10+M[strlen(M)-1]-'0')%4!=0) simple = 1;
		  }
		  else if (strlen(M)==1) { // Only one digit and the last digit is not a multiple of 4.
		  	if ((M[strlen(M)-1]-'0')%4!=0) simple = 1;
		  }
		  break;
		}		
		// If the last digit of M is 0 or 5, M is a multiple of 5.
      	case 5: {
      	  // The last digit of M is neither '0' nor '5'.
      	  if (M[strlen(M)-1]!='0' && M[strlen(M)-1]!='5') simple = 1;
		  break;
		}
		// M must be a multiple of 2 and a multiple of 3, to make it a multiple of 6.
      	case 6: {
      	  digit_sum = 0;
      	  for (k=0; k<strlen(M); k++) digit_sum += M[k] - '0'; // Sum all the digits of M.
      	  // The last digit is not even or the sum of digits is not a multiple of 3.
      	  if ((M[strlen(M)-1]-'0')%2!=0 || digit_sum%3!=0) simple = 1; 
		  break;
		}
		// If M is a multple of 7, then M/10-(M%10)*2 must be a multiple of 7.
      	case 7: { 
      	  trail[0] = '\0'; // Make trail the empty string.
      	  while (strlen(M)>2) { // When num has more than two digits.
			trail[0] = M[strlen(M)-1]; // Place the least significant digit at trail.
			trail[1] = '\0';
			M[strlen(M)-1] = '\0'; // Remove the least significant digit from num.
			times2(trail); // trail * 2.
			minus(M, trail); // Remainding digits of M minus trail times 2.
		  }
		  // One or two digits left, test whether it is a multiple of 7.
		  if (strlen(M)==2&&((M[0]-'0')*10+(M[1]-'0'))%7!=0) simple = 1;  
		  else if (strlen(M)==1&&(M[0]-'0')%7!=0) simple = 1;
		  break;
		}
		// The last three digits must be a multiple of 8.
      	case 8: {
      	  // The last two digits of M is not a multiple of 8.
      	  if (strlen(M)>=3) {
			if (((M[strlen(M)-3]-'0')*100+(M[strlen(M)-2]-'0')*10+M[strlen(M)-1]-'0')%8!=0)
			  simple = 1;
		  }
      	  if (strlen(M)==2) {
      	    if (((M[strlen(M)-2]-'0')*10+M[strlen(M)-1]-'0')%8!=0) simple = 1;
		  }
		  else if (strlen(M)==1){
		  	if ((M[strlen(M)-1]-'0')%8!=0) simple = 1;
		  }
		  break;
		}	// If the sum of all digits is a multiple of 9, M is a multiple of 9.
      	case 9: {
      	  digit_sum = 0;
      	  for (k=0; k<strlen(M); k++) digit_sum += M[k] - '0'; // Sum all the digits of M.
      	  if (digit_sum%9!=0) simple = 1; // Sum of digits is not a multiple of 9.
		  break;
		}
		// The last digit of M be be '0' to make M a multiple of 10. 
      	case 10: {
      	  if (M[strlen(M)-1]!='0') simple = 1;
		  break;
		}
		// The sum of the even-position digits minus the sum of the odd-position digits must be a 
		// multiple of 11 to make M a multiple of 11.
      	case 11: {
      	  digit_sum = 0;
      	  sign = 1;
      	  for (k=0; k<strlen(M); k++) {
			digit_sum += (M[k] - '0') * sign; // Sum all the digits of M.
			sign *= -1; // Change the sign from 1 to -1 or from -1 to 1.
          }
          // Difference of even digit sum and odd digit sum is not a multiple of 11.
      	  if (digit_sum%11!=0) simple = 1;
		  break;
		}
		// M must be a multiple of 4 and a multiple of 3, to make it a multiple of 12.
      	case 12: {
      	  // The last two digits of M is not a multiple of 4.
      	  if (strlen(M)>=2) {
      	    if (((M[strlen(M)-2]-'0')*10+M[strlen(M)-1]-'0')%4!=0) simple = 1;
		  }
		  else if (strlen(M)==1) { // Only one digit and the last digit is not a multiple of 4.
		  	if ((M[strlen(M)-1]-'0')%4!=0) simple = 1;
		  }
      	  digit_sum = 0;
      	  for (k=0; k<strlen(M); k++) digit_sum += M[k] - '0'; // Sum all the digits of M.
      	  if (digit_sum%3!=0) simple = 1; // Sum of digits is not a multiple of 3.  
		  break;
		}
	  }
	  if (simple) break; // If one divisor fails, stop the try. 
	}
	if (!simple) printf("%s - Wonderful.\n", M); // A wonderful number.
	else printf("%s - Simple.\n", M); // A simple number.
  }
  return 0;
}
