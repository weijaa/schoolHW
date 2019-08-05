// One-star problem
// Problem UVA118 Mutant Flatworld Explore
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

  int grid[51][51];
  int x_coord, y_coord; // The upper-right coordinate.
  int x_position, y_position; // The robot postion.
  int off_edge; // Flag shows whether the robot falls off edge or not. 
  char orientation; // Orientation of move.
  char instruction[101]; // Instruction string, maximum length is 100.
  int i, j;
  
  // Read the upper-right coordinate.
  scanf("%d %d", &x_coord, &y_coord);
  // Clear all grids.
  for (i=0; i<x_coord; i++)
    for (j=0; j<y_coord; j++) grid[i][j] = 0; 
  
  // The initial robot position and orientation.
  // If the end of file is reached, the input command does not read any data.
  while (scanf("%d %d %c", &x_position, &y_position, &orientation)==3) { 
    // Set off edge condition to 0.
    off_edge = 0;
    scanf("%s", &instruction); // Input the instruction string.
    for (i=0; i<strlen(instruction); i++) { // Perform robot moves sequentially.
      switch (instruction[i]) { // Check the current instruction character.
        case 'L': { // Left turn
          switch (orientation) { // Update orientation for the left turn move.
            case 'N': {orientation = 'W'; break;}
            case 'S': {orientation = 'E'; break;}
            case 'E': {orientation = 'N'; break;}
            case 'W': {orientation = 'S'; break;}
          }
          break;
        }
        case 'R': { // Right turn
          switch (orientation) { // Update orientation for the right turn move.
            case 'N': {orientation = 'E'; break;}
            case 'S': {orientation = 'W'; break;}
            case 'E': {orientation = 'S'; break;}
            case 'W': {orientation = 'N'; break;}
          }
          break;
        }
        case 'F': { // Move forward
          switch (orientation) {  // Update position.
            case 'N': {
              y_position++; // Move to north one step.
              if (y_position>y_coord) { // When the robot goes off edge.
                y_position--; // Move back.
                if (grid[x_position][y_position]==0) { // If no previous robot goes off edge here,
                  grid[x_position][y_position] = 1; // Mark the grid as the robot leaving "scent".
                  off_edge = 1; // This robot gets off the edge and lost.
                }
              }
              break;
            }
            case 'S': {
              y_position--; // Move to south one step.
              if (y_position<0) { // When the robot goes off edge.
                y_position++; // Move back.
                if (grid[x_position][y_position]==0) { // If no previous robot goes off edge here,
                  grid[x_position][y_position] = 1; // Mark the grid as the robot leaving "scent".
                  off_edge = 1; // This robot gets off the edge and lost.
                }
              }
              break;
            }
            case 'E': {
              x_position++; // Move to east one step.
              if (x_position>x_coord) { // When the robot goes off edge.
                x_position--; // Move back.
                if (grid[x_position][y_position]==0) { // If no previous robot goes off edge here,
                  grid[x_position][y_position] = 1; // Mark the grid as the robot leaving "scent".
                  off_edge = 1; // This robot gets off the edge and lost.
                }
              }
              break;
            }
            case 'W': {
              x_position--; // Move to west one step.
              if (x_position<0) { // When the robot goes off edge.
                x_position++; // Move back.
                if (grid[x_position][y_position]==0) { // If no previous robot goes off edge here,
                  grid[x_position][y_position] = 1; // Mark the grid as the robot leaving "scent".
                  off_edge = 1; // This robot gets off the edge and lost.
                }
              }
              break;
            }
          }
          break;
        }
      }      
      // If the robot goes off edge, stops the command.
      if (off_edge) break;
    }
    printf("%d %d %c", x_position, y_position, orientation); // Print the final position.
    if (off_edge) printf(" LOST\n"); // If the robot goes off edge, print "LOST";
    else printf("\n"); // otherwise, print the newline.
  }
  return 0;
} 
