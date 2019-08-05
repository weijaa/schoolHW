// One-star problem
// Problem 11059 Maximum Product
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

// Product of sequence elements with indices from low to high.
long long product(int low, int high, int *sequence) {
  long long result = 1; // Result of the product.
  int i;  // Loop index.
  
  // Compute the product of the subsequence.
  for (i=low; i<=high; i++) result = result * sequence[i];
  return result; // Return the result.
}

int sign_count(int low, int high, int *sequence) {
  int count = 0; // Sign counter.
  int i;  // Loop variable.
  
  // Increment the sign count if sequence[i] is a negative element.
  for (i=low; i<=high; i++) if (sequence[i]<0) count++; 
  return count; 
}

// Compute the maximum product of a subsequence with no zero elements.
long long product_in_subsequence(int low, int high, int *sequence) {
  // Index of the first element with negative number.
  // sign_low is high+1 if no negative element in this subsequence.
  int sign_low; 
  // Index of the last element with negative number.
  int sign_high;
  int i; // Loop variable.
  
  // If the subsequence is the empty sequence the product is 0.
  if (low>high) return 0;
  
  // If the subsequence has one element and the element is a negative number, the product is 0.
  if (low==high && sequence[low]<0) return 0;
  
  // If the sequence has even number of negative elements, 
  // return product of the entire sequence.
  if (sign_count(low, high, sequence)%2==0)
    return product(low, high, sequence);
    
  // Sign count is odd, there is at least one negative element.
  // If there is at least one negative element, sign_low is the index of the first negative element  
  // from the left hand side.
  for (i=low; i<=high; i++) 
    if (sequence[i]<0) {sign_low = i; break;}
   
  // Sign count is odd, there is at least one negative element.
  // If there is at least one negative element, sign_high is the index of the first negative element  
  // from the right hand side.
  for (i=high; i>=low; i--) 
    if (sequence[i]<0) {sign_high = i; break;}
  
  if (abs(product(low, sign_low, sequence))>abs(product(sign_high, high, sequence)))
    // Maximum product is the product of the first sequence element to the element prior to
    // the last negative element.
    return abs(product(low, sign_high-1, sequence)); 
  else
    // Maximum product is the product of the element next to the first negative element
	// to the last sequence element.
    return abs(product(sign_low+1, high, sequence));       
}

int main(void) {
  int cases = 0; // Number of cases.
  int length; // Sequence length.
  int number[18]; // Input number.
  int zero[18]; // Positions for zero elements.
  int zeros; // Number of zero elements.
  long long max_prod; // Maximum product.
  long long prod; // Current product.
  int i, j; // Loop variables.
  
  while (scanf("%d", &length)==1) { // Input the sequence length, if any.
    zeros = 0; // No zero elements.
    
    for (i=0; i<length; i++) { // Input all integers in the sequence.
      scanf("%d", &number[i]);
      if (number[i]==0) zero[zeros++] = i; // Set the index of zero elements.      
    }
    
    printf("Case #%d: The maximum product is ", ++cases); // Print the message preamble.
    if (length==1) // The sequence has only one element.
	  printf("%d.\n", number[0]);
	else {
      if (zeros==0) 
        printf("%lld.\n", product_in_subsequence(0, length-1, number));
	  else {
	    // The are zeros in the sequence. We will break the sequence into multiple
	    // subsequences with the zero elements as the sequence boundaries.
	    // Evaluate the first subsequence.
	    max_prod = product_in_subsequence(0, zero[0]-1, number);
	    // Evaluate the intermediate subsequences.
	    for (i=1; i<zeros; i++) {
	  	  prod = product_in_subsequence(zero[i-1]+1, zero[i]-1, number);
	  	  if (prod>max_prod) max_prod = prod;
	    }
	    // Evaluate the last subsequence.
	    prod = product_in_subsequence(zero[zeros-1]+1, length-1, number);
	    if (prod>max_prod) max_prod = prod;
	    // Printf the maximum product.
	    printf("%lld.\n", max_prod);
	  }
    }
  }
  return 0;
}
