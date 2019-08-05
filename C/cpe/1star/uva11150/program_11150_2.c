// One-star problem
// Problem 11150 Cola
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

/*
  Let us assume there are N bottles of cola at the beginning. After drinking all cola,
  there are N empty bottles. To get a free cola, three empty bottles are traded and
  another empty bottles is yielded. Hence, two empty bottles are lost for getting
  each free cola.
  
  When N is even, it is possible to get N/2 free cola if an empty bottle 
  is borrowed. After N/2-1 free cola are exchanged, there are two empty bottles left.
  At this point, we may borrow one empty bottle to trade for and addition cola and to
  get N/2 free cola in total. After finishing the last bottle of free cola, one bottle
  is left to retrun for the borrowed one.
  
  When N is odd, after N/2-1 free cola are exchanged, there are three empty bottles left.
  The last three empty bottles are traded for one free cola and there will one empty
  bottle at the end. If we want to get an additonal free cola, two empty bottles must be
  borrowed. However, after finishing this cola, there is only one empty bottle, not enough
  to retuned for the borrowed bottles. Hence, we can get N/2 free cola in total.
  
  As the result, no matter N is even or odd, we will get N/2 free cola. The total number
  drinks consumed is floor(1.5 * N).
*/
int main(void) {
  int N; // The number of cola at the beginning.
  
  while (scanf("%d", &N)==1) // Input the number of bottles of cola paid.
	printf("%d\n", (int)(N*1.5)); // The maximum drinks is 1.5 times of the input number.
	
  return 0;
}
