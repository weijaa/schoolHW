// Two-star problem
// Problem 151 Power Crisis
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

// Obviously, the problem has a trivial solution of m==1. We will not consider this
// trivial solution.
int main(void) {
  int N; // Input number of regions.
  int m; // Number of regions to be skipped to turn off the power.
  const int Wellington = 13; // The last region to be powered off
  // on_off[i] means region i been turned off or not;
  // 1: not been turned off; 0: been turned off.
  int on_off[99];
  int region; // The region to be powered off.
  int found; // 0: the smallest m is not found; 1: otherwise.
  int count; // Number of regions been powered off.
  int i; // Loop variables.
  
  while (1) { // Continue until the input is 0.
  	scanf("%d", &N); // Input the number of regions, 13<=N<100.
  	
  	if (N==0) break; // If the input is 0, stop the loop and terminate the program.
  	
  	// Consider m start from 2.
  	m = 2;
  	found = 0; // The smallest m is not found yet.
  	on_off[0] = 0; // Mark region 0 has been powered off first.
	count = 1; // Region 1. Region 0 has been powered off.
  	for (i=1; i<N; i++) on_off[i] = 1; // Reset other regions not been powered off.
	region = 0; // Check all regions starting from Region 1.
  	while (!found) { // Continue if not found.
	  while (!found) { // If not region N is not powered off.
	    for (i=0; i<m-1; i++) { // Jump m regions.
	      // Region i has been powered off, check the next region.
	      // That is, find the first region starting from (i
	      while (on_off[region]==0) region = (region + 1) % N; 
	      region = (region + 1) % N; // Skip one region.
		}
		while (on_off[region]==0) region = (region + 1) % N;
		on_off[region] = 0; // Region i is powered off.
		count++;
		// Wellington, Region 13, has been powerd off.
		if (region+1==Wellington) found = 1; // 
	  }
	  if (count<N) { // Not all regions are powered off.
	    m++; // Check the next m;
	    found = 0; // The solution is not found.
	    count = 1; // Region 1. Region 0 has been powered off.
  	    for (i=1; i<N; i++) on_off[i] = 1; // Reset other regions not been powered off.
	    region = 0; // Check all regions starting from Region 1.
      }
 	}
 	printf("%d\n", m);
  }
  return 0;
}
