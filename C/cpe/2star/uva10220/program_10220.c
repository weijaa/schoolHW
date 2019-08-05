// Two-star problem
// Problem 10220 I Love Big Numbers!
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

// Convert a string to a number. Need this function to allocate memory space.
Number str2num(Number num, char *str) {
  // Allocate sufficient memory
  if (num==NULL) num = (Number) malloc(strlen(str)+1);
  else num = (Number) realloc(num, strlen(str)+1);
  strcpy(num, str); // Copy the string.
  return num;
}

// Conver an integer to a number string.
Number int2num(Number num, int n) { 
  int temp = n;
  int length = 0; // Digit count.
  int i; // Loop variable.
  
  while (temp>0) {
    length++; // Increment the digit count of n.
    temp = temp / 10;
  }
  // Allocate memory.
  if (num==NULL) num = (Number) malloc(length+1);
  else num = (Number) realloc(num, length+1);
  for (i=length-1; i>=0; i--) { // Copy digit from right to left.
    num[i] = n % 10 + '0'; // The digit to put in the string.
    n = n / 10; // Rest of the number.
  } 
  num[length] = '\0'; // End of string.
//printf("In int2num: num=%s\n", num);
  return num;
}

// Addition operation using strings.
// Since the addition is called as x=x+y,
// the returned Number will take the same memory as x.
Number add(Number op1, Number op2) {
  Number sum; // Sum of addition.
  int l1=strlen(op1), l2=strlen(op2), lsum, lsum1; // String lengths.
  int t1, t2, t, carry = 0; // One digit addition: t=t1+t2+carry.
  int i = 0; // Loop variable.
  
  // Make sum use the memory pointed by op1.
  sum = op1; // Copy the pointer of op1 to sum.
  op1 = NULL; // Set op1 to NULL.
  op1 = str2num(op1, sum); // Copy the content of sum to op1. op1 will get a new memory.
  if (l1>=l2) lsum = l1; // Set length of the sum.
  else lsum = l2; // The updated length is the maximum of l1 and l2.
  lsum1 = lsum; // Keep the original length.
  sum = (Number) realloc(sum, lsum+1); // Reallocate memory for sum, if lsum is larger.
  
  while (lsum>0) { // add all digits from right to left.
  	t1 = (l1>0) ? op1[--l1] - '0' : 0; // Get a digit of op1, if there is any.
  	t2 = (l2>0) ? op2[--l2] - '0' : 0; // Get a digit of op2, if there is any.
  	t = t1 + t2 + carry; // Add two single digits with carry.
  	carry = t / 10; // New carry.
  	sum[--lsum] = t % 10 + '0'; // Put the sum of two digits to sum[].
  }
  sum[lsum1] = '\0'; // Add end-of-string to the sum.
  if (carry==1) { // If carry is 1,put this carry to the leading digit of sum.
    sum = (Number) realloc(sum, lsum1 + 2); // Expand the memory of sum one more byte.
    for (i=strlen(sum); i>=0; i--) sum[i+1] = sum[i]; // Move the digits one position to left.
    sum[0] = '1'; // Plcase '1' at the leading digit position.
  }
  free(op1);
  return sum; // Return the sum.
}

// Compute n*(10^p).
Number time_power10 (Number num, int p) {
  int length = strlen(num);
  int i; // Loop variable.
  
  // Expand memory space of num.
  if (num==NULL) num = (Number) malloc(length+p+1);
  else num = (Number) realloc(num, length+p+1);
  for (i=0; i<p; i++) num[length + i] = '0'; // Insert 0 to the end of num, i.e., n=n*10.
  num[length + i] = '\0'; // Add end of string of num.
  return num; // Return number num.
}

// Single digit multiplication. n is a number, d is a digit.
Number time_digit(Number num, Number d) {
  Number product=NULL; // Product.
  Number digit_product=NULL; // Product of two digits, also shift to the position of digit in n.
  int int_prod; // Integer product of two digits.
  int length = strlen(num);
  int i;
  
  product = str2num(product, "0"); // Initial product to zero.
  digit_product = str2num(digit_product, "0"); // Initial product to zero.
  
  for (i=length-1; i>=0; i--) {
  	int_prod = (num[i] - '0') * (d[0] - '0'); // Integer product of two digits.
  	digit_product = int2num(digit_product, int_prod); // Convert the integer value of number string.
  	digit_product = time_power10(digit_product, length - i - 1); // Move the digit product to the position.
  	product = add(product, digit_product); // Accumulate the digit product.
  }
  
  free(digit_product);
  return product; // Return the product.
}

// Multiplication operation using strings.
// Since the multiplication is called as x=x*y, 
// the returned Number will take the same memory as x.
Number times(Number op1, Number op2) {
  Number product; // Product of op1 and op2.
  Number digit=NULL; // A single digit.
  Number temp_ptr=NULL; // Temporary pointer.
  int l1=strlen(op1), l2=strlen(op2); // Number of digits in op1 and op2.
  int temp; // Temporary integer.
  int i; // loop variable.
  
  // Make product use the memory pointed by op1.
  product = op1; // Copy the pointer of op1 to product.
  op1 = NULL; // Set op1 to NULL.
  op1 = str2num(op1, product); // Copy the content of product to op1. op1 will get a new memory.
  product = str2num(product, "0"); // Initial the value of product to 0.
  for (i=l2-1; i>=0; i--) { // Start from the least significant digit to op2.
  	digit = int2num(digit, op2[i] - '0'); // Convert the digit to a number.
    temp_ptr = time_digit(op1, digit); // multiply op1 with a digit of op2.
    temp_ptr = time_power10(temp_ptr, l2-i-1); // Move the partial product to its position.
    product = add(product, temp_ptr); // Accumulate the product.
    free(temp_ptr);
  }
  
  free(digit);
  free(op1);
  return product; // Return the result.
}

int main(void) {
  int n; // Input integer.
  Number factorial; // Factorial of n in string representation.
  Number num=NULL; // A number in string representation.
  unsigned int digit_sum; // Digit sum.
  int i; // Loop variable.
  
  while (scanf("%d", &n)==1) { // Input an integer n, if there is any.
    factorial = NULL;
    factorial = str2num(factorial, "1"); // Initial factorial to 1.
    for (i=2; i<=n; i++) {
      num = int2num(num, i); // Convert number i to string.
      factorial = times(factorial, num); // Compute the next factorial.
	}
	
	digit_sum = 0; // Initial digit sum to 0.
	for (i=0; i<strlen(factorial); i++)
	  digit_sum += factorial[i] - '0'; // Accumulate the digit sum.
	
	free(factorial); // Release the memory of factorial because it could be very large.
	printf("%u\n", digit_sum); // Output the digit sum.
  }
  return 0;
}
