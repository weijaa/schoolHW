// One-star problem
// Problem 10409 Die Game
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
  int cmd_count; // Commond count in each case.
  char command[6]; // "north", "east", "south", or "west", maximum length is 5.
  // Record the current value of these three faces.
  // The oppositive face is of value 7 minus the value of that face.
  int top_face, north_face, west_face; 
  int temp;
  int i; // Loop variable.
  
  scanf("%d", &cmd_count); // Input the first command count.
  
  while (cmd_count!=0) { // If the command count is 0, the program is done.
    // At the beginning of the game, the top face is 1 and the north face is 2.
    top_face = 1;
    north_face = 2;
    west_face = 3;
    
    for (i=0; i<cmd_count; i++) { // Perform all commands.
      scanf("%s", &command); // Input the command string.
      
      // For each rolling of the die, only two faces change their values.
	  if (strcmp(command, "north")==0) { // When the command is "north", west_face no change.
	    temp = top_face;
        top_face = 7 - north_face;
        north_face = temp;
	  }
	  else if (strcmp(command, "east")==0) { // When the command is "east", north_face no change.
	    temp = top_face;
        top_face = west_face;
        west_face = 7 - temp;
	  }
	  else if (strcmp(command, "south")==0) { // When the command is "south", west_face no change.
	    temp = top_face;
        top_face = north_face;
        north_fa= 7 - temp;
	  }
	  else if (strcmp(command, "west")==0) { // When the command is "west", north_face no change.
	    temp = top_face;
        top_face = 7 - west_face;
        west_face = temp;
	  }
	}
	printf("%d\n", top_face); // Print the final result of the top face.
	scanf("%d", &cmd_count); // Input the next command count.
  }
  return 0;
}
