// One-star problem
// Problem 10714 Ants
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
  Let use divide all the ants in two groups, the first group is the ants on the left hands 
  of the central point of the pole and the second group is the ants on the right hand side 
  of te central point of the pole. If there is an ant at the center of the group, count it
  in the first group.
  
  The scenario of the earlies time for ALL ants to fall off the pole is that all ants
  in the first group walk to the left and all ants in the second group walk to the right.
  The nearest ant to the center, say, K, will be the last one to fall off the pole at time
  K if it is in the first group, and at time N-K if it is in the second group. Therefore,
  the algorithm for the earlies time for ALL ants to fall is to find the ant with the 
  maximum value m, if m<=n/2, or n-m, if m>n/2.
  
  The scenario of the latest time for ALL ants to fall off the pole is that the ant nearest
  to an end of the pole walk toward the far end. Then this ant must the one farest from the
  center of the pole. Let the ant at L be the nearest one to an end, say, left hand side, 
  and it walks to the right. If L does not meet any other ant, he/she will fall at time N-L, 
  all other ants must fall off the pole before time N-L. If L meets some another ant, 
  say, H, and turn back, the turn back position must be on the left half of the pole; 
  otherwise, it contradicts to the fact that L is the farest ant from the center. H will 
  pick up the rest journey of L and fall off the pole at time N-L and L falls off before 
  time N-L. If H meet another ant in the rest of journey, the meeting point must be also
  at the left half of the pole and this ant pick up the rest of journey to the right form 
  that meeting point. Simlaryly, if L is the nearest one to the right end and walk to the 
  left, the latest time for ALL ants to fall is L. Hence, the algorithm for latest time for
  all ant to fall is to find the ant with the maximum value m, if m>n/2, or n-m, if m<=n/2.
  
*/

int main(void) {
  int cases; // Number of cases.
  int pole; // Length of the pole.
  int ants; // number of ants.
  int p; // Position of an ant.
  int earliest; // Earliest time for ALL ants to fall.
  int latest; // Latest time for ALL ants to fall.
  int i, j; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%d %d", &pole, &ants); // Input pole length and the number of ants.
    earliest = 0; // Set the earliest time for ALL ants to fall to be 0.
    latest = 0; // Set the latest time for ALL ants to fall to be 0.
    
    for (j=0; j<ants; j++) { // Process all ants.
      scanf("%d", &p); // Postion of ant j.
      if (p<=pole/2) { // Ant j is at the left hand side of the pole.
        if (earliest<p) earliest = p; // Update the earliest falling time.
        if (latest<pole-p) latest = pole - p; // Update the latest falling time.
	  }
	  else { // Ant j is at the right hand side of the pole.
	    if (earliest<pole-p) earliest = pole - p;
	    if (latest<p) latest = p;
	  }
    }
    printf("%d %d\n", earliest, latest);
  }
  return 0;
}
