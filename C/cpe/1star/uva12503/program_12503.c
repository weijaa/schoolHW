// One-star problem
// Problem 12503 Robot Instructions
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

int main(void) {
  int cases; // Number of testing cases.
  int n; // Number of instructions.
  // Instruction sequence, up 100 100 instructions. -1 for LEFT, 1 for RIGHT.
  int instruction[100];
  char str[6]; // Instruction strings, LEFT, RIGHT, SAME.
  int position;
  int i, j, k; // Loop variable.
  
  scanf("%d", &cases); // Input number of cases.
  
  for (i=0; i<cases; i++) { // Process all cases.
    scanf("%d", &n); // Input number of instructions.
    position = 0; // Initial robot position is 0.
    for (j=0; j<n; j++) { // Input all instructions.
      scanf("%s", str); // Input the instruction string.
      if (strcmp(str, "LEFT")==0) instruction[j] = -1; // Move "LEFT"
      else if (strcmp(str, "RIGHT")==0) instruction[j] = 1; // Move "RIGHT"
      else if (strcmp(str, "SAME")==0) { // SAME AS instruction.
        scanf("%s %d", str, &k); // Input AS instruction k.
		instruction[j] = instruction[k-1]; // Instruction label starts from 1.
	  }
	  position += instruction[j];
	  
	}
	printf("%d\n", position); // Output robot final position.
  }
  return 0;
}
