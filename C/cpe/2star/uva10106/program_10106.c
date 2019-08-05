// Two-star problem
// Problem 10106 Product
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
Number str2num(char *str) {
  Number num; // Number as string.
  
  num = (Number) malloc(strlen(str)+1); // Allocate sufficient memory.
  strcpy(num, str); // Copy the string.
  return num;
}

// Conver an integer to a number string.
Number int2num(int n) { 
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

// Compute n*(10^p).
Number time_power10 (Number n, int p) {
  int length = strlen(n);
  int i; // Loop variable.
  
  n = (Number) realloc(n, length+p+1); // Expand memory space of n.
  for (i=0; i<p; i++) n[length + i] = '0'; // Insert 0 to the end of n, i.e., n=n*10.
  n[length + i] = '\0'; // Add end of string of n.
  return n; // Return number n.
}

// Single digit multiplication. n is a number, d is a digit.
Number time_digit(Number n, Number d) {
  Number product; // Product.
  Number digit_product; // Product of two digits, also shift to the position of digit in n.
  int int_prod; // Integer product of two digits.
  int length = strlen(n);
  int i;
  
  product = str2num("0"); // Initial product to zero.
  digit_product = str2num("0"); // Initial product to zero.
  
  for (i=length-1; i>=0; i--) {
  	int_prod = (n[i] - '0') * (d[0] - '0'); // Integer product of two digits.
  	digit_product = int2num(int_prod); // Convert the integer value of number string.
  	digit_product = time_power10(digit_product, length - i - 1); // Move the digit product to the position.
  	product = add(product, digit_product); // Accumulate the digit product.
  }
  return product;   
}

Number times(Number op1, Number op2) {
  Number product; // Product of op1 and op2.
  Number digit;
  Number temp_ptr; // Temporary pointer.
  int l1=strlen(op1), l2=strlen(op2); 
  int temp; // Temporary integer.
  int i; // loop variable.
  
  if (l1<l2) { // Swap the two operands to make the second one with less number of digits.
    temp_ptr = op1;
	temp = l1;
	op1 = op2;
	l1 = l2;
	op2 = temp_ptr;
	l2 = temp;
  }
  
  product = str2num("0"); // Initial the product to 0.
  for (i=l2-1; i>=0; i--) { // Start from the least significant digit to op2.
  	digit = int2num(op2[i] - '0'); // Convert the digit to a number.
    temp_ptr = time_digit(op1, digit); // multiply op1 with a digit of op2.
    temp_ptr = time_power10(temp_ptr, l2-i-1); // Move the partial product to its position.
    product = add(product, temp_ptr); // Accumulate the product.
  }
  return product; // Return the result.
}

int main(void) {
  char n[251], m[251]; // Input numbers as strings. Maximum 250 digits.
  Number num1, num2; // Operands for multiplication.
  Number product; // Product of the two input numbers.

  while (scanf("%s %s", n, m)==2) { // Input two numbers as strings, if there are any.
  	num1 = str2num(n); // Convert the strings to numbers.
  	num2 = str2num(m);
  	product = times(num1, num2); // product=num1*num2
  	
  	printf("%s\n", product); // Output the result.
  }
  return 0;
}
