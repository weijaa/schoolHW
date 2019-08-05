// One-star problem
// Problem 10057 A Mid-Summer Night's Dream
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

int main(void) {
  int n;
  unsigned short data[1000000];
  int min_A, possible_A, input_A;
  unsigned short temp;
  int i, j;
  
  while (scanf("%d", &n)==1) { // Input the number of data elements.
  	for (i=0; i<n; i++) scanf("%d", &data[i]); // Input all n numbers.
  	
  	// Sort the data sequence in ascending order.
  	for (i=n-1; i>0; i--)
  	  for (j=1; j<=i; j++) {
  	  	if (data[j-1]>data[j]) {
  	  	  temp = data[j-1];
  	  	  data[j-1] = data[j];
  	  	  data[j] = temp;
		}
	  }
	  
	// When n is even, the integers between the two centering elements (including) are the possible A.
	// The minimun element of A is the left of the two centering elements, data[n/2-1].
	// The loop of input_A is counting the number of input elements satisfying A. 
	if (n%2==0) {
	  min_A = data[n / 2 - 1];
	  possible_A = data[n / 2] - data[n / 2 - 1] + 1;
	  input_A = 0;
	  for (i=0; i<n; i++) input_A += data[i]==data[n/2-1] || data[i]==data[n/2];
	}
	// When n is odd, the center element is the possible A.
	// The minimun element of A is the center element, data[(n-1)/2].
	// The loop of input_A is counting the number of input elements satisfying A.
	else {
	  min_A = data[(n - 1) / 2];
	  possible_A = 1;
	  input_A = 0;
	  for (i=0; i<n; i++) input_A += data[i]==data[(n-1)/2];
	}
  	
	printf("%d %d %d\n", min_A, input_A, possible_A); // Output the result.
  }
  return 0;
}
