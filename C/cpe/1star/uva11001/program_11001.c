// One-star problem
// Problem 11001 Necklace
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
#include <math.h>
#define epsilon 0.0001

int main(void) {
  int V_total; // Total volume of clay.
  int V0; // Volume of clay consumed.
  int k; // Number of necklaces;
  int k_max; // The number of necklaces with the maximum length.
  float V; // Volume of clay used to make a necklace, including consumed clay, i.e., V=V_total/k.
  int non_unique; // Stop, not unique solution. 
  float D; // Diameter of a necklances.
  float length_next; // Diameter to consider next.
  float necklace; // Total necklace length.
  
  while (1) { // Continue untill 0 0 are input.
    scanf("%d %d", &V_total, &V0); // Input total volume and consumed volume of clay.
	if (V_total==0 && V0==0) break; // "0 0" are input, stop the loop and terminate the program.
	k = 1; // Start wiht one necklace.
	V = (float) V_total / k; // Volume of clay used to make a necklace.
	non_unique = 0; // At the beginning the necklace is unique.
	if (V>=V0) {
	  necklace = 0.3 * sqrt((float) V - V0);  // Length of the necklace if only one necklace.
	  k_max = 1; // Assume the solution is 1 at the beginning.
    }
	else k = 0; // No necklace can be made.
	
	while (V >= V0) { // Stop when k is too large to make necklace or no unique solution.
	  k++; // Increase the number of necklaces.
	  V = (float) V_total / k; // Volume of clay used to make a necklace.
	  if (V>=V0) length_next = 0.3 * sqrt((float) V - V0) * k; // Total length for the next diameter to consider.
	  if (fabs(necklace-length_next)<epsilon) non_unique = 1; // The necklace is not unique.
	  if (necklace<length_next) { // New maximum necklace length is found.
	  	necklace = length_next; // New maximum necklace length.
	  	k_max = k; // Number of necklaces making the maximum length.
	  	non_unique = 0; // It is unique at this moment.
	  }
	  //printf("***%6.4f\n", length_next);
	}
	if (non_unique || k==0) printf("0\n"); // If it is not unique or no necklaces can be made.
	else printf("%d\n", k_max); // Output the number of necklaces making the maximum length.
  }
  return 0;
}
