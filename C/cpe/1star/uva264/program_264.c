// One-star problem
// Problem UVA264 Count on Cantor
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

/* Observe that in the Cantor's enumeration, the first anti-diagonal has one element,
   the second anti-diagonal has two elements, the third anti-diagonal has three elements, etc.
   These anti-diagonals form an arithmetic progression sequence, 1, 2, 3, 4, ....
   That is, the k-th anti-diagonal has k elements. Note that, we count the anti-diagonal index
   starting from 1. Also, the number of elements in the first i anti-diagonals is i(i+1)/2.
   
   Hence, to find the position of the n-th element in the Cantor's enumeration, we first 
   compute the diagaonal index i which is the smallest integer such that i(i+1)/2 is 
   greater than or equal to n. That is, the n-th element is on the i-th anti-diagonal. 
   Since the Cantor's enumeration is traversed in the zigzag manners, when i is odd, 
   the anti-diagonal starts from the lower-left corner and traverses upward; when i is 
   even, the anti-diagonal starts from the upper-right corner and traveses downward. 
   Therefore,  When i is odd the position of j is at the (n-i(i-1)/2)-th element 
   starting from the lower-left corner of the i-th anti-diagonal, i.e., the 
   (i-(n-i(i-1)/2)+1)-th element starting from the upper-right corner of the i-th 
   anti-diagonal; when i is even the position of j is at the (n-i(i-1)/2)-th element 
   starting from the upper-right corner of the i-th anti-diagonal.
   
   If we conisder j is counted from the upper-right corner, then the value of n is j/(i-j+1).
*/
int main(void) { 
  int n; // The n-th element in the Cantor's enumeration.
  int i, j; // The n-th element is j-th element of the i-th anti-diagonal.
  
  while (scanf("%d", &n)==1) { // Input the value n.
    i = 1; // Initialize the anti-diagonal index i to 0.
    while (i*(i+1)/2<n) i++; // Find the smallest i such that i(i+1)/2 is greater than or equal to n. 
    if (i%2==1) j = n - i * (i - 1) / 2; // When the anti-diagonal is traversed downward.
    else j = i - (n - i * (i - 1) / 2) + 1; // When the anti-diagonal is traversed upward.
    printf("Term %d is %d/%d\n", n, i-j+1, j); // Output the result of n.
  }
  return 0;
} 
