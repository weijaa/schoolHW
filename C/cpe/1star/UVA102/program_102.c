// One-star problem
// Problem UVA102 Ecological Bin Packing
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
  // The number of colored bottles in three recycle bins.
  // The index in the first dimension is the bin number.
  // The index in the second dimension is the color of bottles, 0: Brwon, 1: Green, 2: Clear.  
  int bin[3][3];
  // The six possible permutations of the colored bottoles in the three bins.
  // The order of the six permutations are in alphabetical order. 
  const char order[6][4]= {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
  int moves[6]; // The number of moves for the order of colored bottles as the above six cases.
  int min; // Minimum number of moves.
  int selected; // The selected cases.
  int i; // Loop variable.
  
  while (scanf("%d %d %d %d %d %d %d %d %d", // Input the number of colored bottles in three recycle bins.
               &bin[0][0], &bin[0][1], &bin[0][2],
               &bin[1][0], &bin[1][1], &bin[1][2],
               &bin[2][0], &bin[2][1], &bin[2][2])==9) {
    
    // Case 0: BCG, bin 0: brown, bin 1: clear, bin 2: green.
    // bin[1][0] + bin[2][0]: move brown bottles to bin 0.
    // bin[0][2] + bin[2][2]: move clear bottles to bin 1.
    // bin[0][1] + bin[1][1]: move green bottles to bin 2.
	moves[0] = bin[1][0] + bin[2][0] + bin[0][2] + bin[2][2] + bin[0][1] + bin[1][1];

	// Case 1: BGC, bin 0: brown, bin 1: green, bin 2: clear.
    // bin[1][0] + bin[2][0]: move brown bottles to bin 0.
    // bin[0][1] + bin[2][1]: move green bottles to bin 1.
    // bin[0][2] + bin[1][2]: move clear bottles to bin 2.
	moves[1] = bin[1][0] + bin[2][0] + bin[0][1] + bin[2][1] + bin[0][2] + bin[1][2];
	
	// Case 2: CBG, bin 0: clear, bin 1: brown, bin 2: green.
    // bin[1][2] + bin[2][2]: move clear bottles to bin 0.
    // bin[0][0] + bin[2][0]: move brown bottles to bin 1.
    // bin[0][1] + bin[1][1]: move green bottles to bin 2.
	moves[2] = bin[1][2] + bin[2][2] + bin[0][0] + bin[2][0] + bin[0][1] + bin[1][1];
	
	// Case 3: CGB, bin 0: clear, bin 1: green, bin 2: brown.
    // bin[1][2] + bin[2][2]: move clear bottles to bin 0.
    // bin[0][1] + bin[2][1]: move green bottles to bin 1.
    // bin[0][0] + bin[1][0]: move brown bottles to bin 2.
	moves[3] = bin[1][2] + bin[2][2] + bin[0][1] + bin[2][1] + bin[0][0] + bin[1][0];
	
	// Case 4: GBC, bin 0: green, bin 1: brown, bin 2: clear.
    // bin[1][1] + bin[2][1]: move green bottles to bin 0.
    // bin[0][0] + bin[2][0]: move brown bottles to bin 1.
    // bin[0][2] + bin[1][2]: move clear bottles to bin 2.
	moves[4] = bin[1][1] + bin[2][1] + bin[0][0] + bin[2][0] + bin[0][2] + bin[1][2];
	
	// Case 5: GCB, bin 0: green, bin 1: clear, bin 2: brown.
    // bin[1][1] + bin[2][1]: move green bottles to bin 0.
    // bin[0][2] + bin[2][2]: move clear bottles to bin 1.
    // bin[0][0] + bin[1][0]: move brown bottles to bin 2.
	moves[5] = bin[1][1] + bin[2][1] + bin[0][2] + bin[2][2] + bin[0][0] + bin[1][0];
	
    // Initially, set the selected case of minimum moves to be case 0.
    min = moves[0];
    selected = 0;
    // For cases 1 to 5, update the minimum moves and the selected case,
	// if move[i] is less than min.
    for (i=1; i<6; i++) 
	  if (moves[i]<min) {min = moves[i]; selected = i;}
    
    printf("%s %d\n", order[selected], min); // Print the selected case and minimum moves.
  }
  return 0;
} 
