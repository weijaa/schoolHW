// One-star problem
// Problem 10925 Krakovia
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

// Allcate a one-byte memory and set to the empty string.
Number empty_string(void) {
  Number n;
  
  n = (Number) malloc(1); // Request 1-byte memory.
  n[0] ='\0'; // End of string.
  return n;
}

// Convert a string to a number. Need this function to allocate memory space.
Number str2num(char *str) {
  Number num; // Number as string.
  
  num = (Number) malloc(strlen(str)+1); // Allocate sufficient memory.
  strcpy(num, str); // Copy the string.
  return num;
}

// Conver an integer to a number string.
Number num2str(int n) { 
  Number num; // Number as string.
  int temp = n;
  int length = 0; // Digit count.
  int i; // Loop variable.
  
  while (temp>0) {
    length++; // Increment the digit count of n.
    temp = temp / 10;
  }
  num = (Number) malloc(length+1); // Allocate memory.
  for (i=length-1; i>=0; i--) { // Copy digit from right to left.
    num[i] = n % 10 + '0'; // The digit to put in the string.
    n = n / 10; // Rest of the number.
  } 
  num[length] = '\0'; // End of string.
  return num;
}

Number my_strncat(Number n1, Number n2, int leng) {
  int l1, l2; 
  int i; // Loop variable.
  if (n1==NULL) { // If N1 is NULL, make n1 as the empty string.
    n1 = (Number) malloc(1); 
    n1[0] = '\0';
    l1 =0;
  }
  else l1 = strlen(n1);
  
  l2 = strlen(n2);
  
  if (l2<leng) leng = l2; // If the length of n2 is less than leng, concatnate all n2.
  n1 = (Number) realloc(n1, l1+leng+1); // Extend the memory of n1. 
  for (i=0; i<leng; i++) n1[l1+i] = n2[i]; // Put string n2 after n1.
  n1[l1+leng] = '\0'; // Add end of string.
  return n1;
}

Number my_strncpy(Number n1, Number n2, int cnt) {
  int i; // Loop variable.
  
  if (strlen(n2)<cnt) cnt = strlen(n2); // If the lenght of n2 is less than cnt, copy all n2.
  if (n1==NULL) n1 = (Number) malloc(cnt+1); // Request memory for n1.
  else n1 = (Number) realloc(n1, cnt+1); // Locate enough memory for the new string.
  for (i=0; i<cnt; i++) n1[i] = n2[i]; // Copy characters.
  n1[cnt] = '\0'; // End of string.
  return n1;
}

Number remove_leading_zero(Number n) {
  while (n[0]=='0') strcpy(n, n+1); // If the first letter is '0' remove it.
  return n; // The result could be the empty string.
}

// Less than comparison using strings.
int leqp(Number op1, Number op2) {
  int i; // Loop vairable.
  
  if (strlen(op2)>strlen(op1)) return 1; // op2 has more digits, op1<op2.
  if (strlen(op2)<strlen(op1)) return 0; // op1 has more digits, op1>op2.
  for (i=0; i<strlen(op1); i++) // Same length; compare digit from left to right.
    if (op2[i]>op1[i]) return 1; // op2>op1.
    else if (op2[i]<op1[i]) return 0; // op2<op1.
  return 1; // op1==op2.  
}

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
    sum[0] = '1'; // Plcase '1' at the leading digit position.
  }
  return sum; // Return the sum.
}

// Subtraction operation using strings. Assume op1>op2.
Number minus(Number op1, Number op2) {
  Number diff; // op1-op2
  int l1=strlen(op1), l2=strlen(op2), ldiff, ldiff1; // String lengths.
  int t1, t2, t, borrow = 0; // One digit subtraction: t=t1-t2-borrow.
  int i = 0; // Loop variable.
  
  ldiff = l1; // Maximum length is l1.
  ldiff1 = ldiff; // For later reuse of the maximum length.
  diff = (Number) malloc(ldiff + 1); // Allocate memory for the difference.
  
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
  diff = remove_leading_zero(diff); // Remove the leading 0's from the difference.
  return diff; // Return the difference.
}

// Division operation using strings. Assume op1>op2.
Number divide(Number op1, Number op2) {
  Number my_op1=empty_string(); // Keep the original op1 and op2.
  Number my_op2=empty_string(); // we use an extra copy so op1 and op2 wont be affect.
  Number partial_quotient;
  Number dividend=empty_string();
  Number quotient=empty_string(); // The final quotient.
  int l1=strlen(op1), l2=strlen(op2); // Lengthes of op1 and op2.
  int ld; // Length of dividend for partial division.
  
  my_op1 = my_strncpy(my_op1, op1, l1); // Copy operand 1.
  my_op2 = my_strncpy(my_op2, op2, l2); // Copy operand 2.
  
  ld = l2+1; // Make the dividend four characters longer than op2.
  if (ld>l1) ld = l1; // The length of dividend can not be greater than the length of op1.
  dividend = my_strncpy(dividend, my_op1, ld); // Get the first ld character from op1.
  my_op1 = strcpy(my_op1, my_op1+ld); // Remove the first ld character out of op1.
  partial_quotient = num2str(0); // Initial the partial quotient to 0.
  while (leqp(my_op2, dividend)) { // When the divisor is less than the dividend.
	partial_quotient = add(partial_quotient, "1"); // Euclidean division.
	dividend = minus(dividend, my_op2); // Subtract op2 out of the dividend.
  }
  dividend = remove_leading_zero(dividend); // Remove the leading 0's from the dividend.
  // Put the partial quotient to the final quotient.
  quotient = my_strncat(quotient, partial_quotient, strlen(partial_quotient)); 
  
  while (strlen(my_op1)>0) { // There more digits in operand op1.
  	dividend = my_strncat(dividend, my_op1, 1); // Move one digit to the dividend.
  	my_op1 = strcpy(my_op1, my_op1+1); // Remove one digit from op1.
    partial_quotient = num2str(0); // Set partial quotient to 0.
    if (leqp(my_op2, dividend)) { // When the divisor is less than the dividend.
      while (leqp(my_op2, dividend)) { // Perform Euclidean division.
	    partial_quotient = add(partial_quotient, "1");
	    dividend = minus(dividend, my_op2); // The partial quotient has one digit only.
      }
	}
	else partial_quotient = str2num("0"); // The partial quotient is 0.
    quotient = my_strncat(quotient, partial_quotient, 1); // Extend final quotient.
    dividend = remove_leading_zero(dividend); // Remove leading zero from divident.
  } // Repeat one-digit division.
  free(dividend);
  free(partial_quotient);
  return quotient; // Return quotient.
}

int main(void) {
  Number total=NULL; // Total bills.
  Number bill=NULL; // A bill.
  Number friends=NULL; // Number of friends.
  Number pay=NULL; // Pay for each person.
  char V[22]; // Input value of bills. The input value is up to 10^20, i.e., 21 digits.
  int N, F; // Number of bills and number of friends.
  int count = 1; // Case index.
  int i; // Loop Variable

  while (1) { // Continue until the input is "0 0".
    scanf("%d %d", &N, &F);
    
    if (N==0 && F==0) break; // Stop the loop and terminate.
    
    total = str2num("0"); // Initial sum to 0.
    for (i=0; i<N; i++) {
      scanf("%s", V); // Input a bill.
      bill = str2num(V); // Covert string to number.
      total = add(total, bill); // total = total + bill.
	}
	friends = num2str(F); // Convert integer to number.
	pay = divide(total, friends); // pay = total / friends.
	if (strlen(pay)==0) pay = str2num("0"); // The empty string means 0.
	printf("Bill #%d costs %s: each friend should pay %s\n\n", count++, total, pay); // Output the result.
  }
  return 0;
}
