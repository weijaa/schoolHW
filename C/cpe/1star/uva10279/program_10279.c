// One-star problem
// Problem 10279 Mine Sweeper
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
  int n; // The size of the board;
  char board[10][11]; // The initial layout of the game board.
  char game[10][11]; // The layout of the partial steps of the game board.
  int mine_touched;
  int cases;
  int i, j, k; // Loop variables.
  
  scanf("%d", &cases); // Input number of cases.
  
  for (k=0; k<cases; k++) {
 
    while (scanf("%d", &n)==1) { // Input the size of the game.
      for (i=0; i<n; i++) scanf("%s", &board[i]); // Input the inital layour of the game.
      for (i=0; i<n; i++) scanf("%s", &game[i]); // Input the layour of the partial game.
    
      mine_touched = 0; // Assume no mine is touched.
      for (i=0; i<n; i++) // Check if a mine has been touched.
        for (j=0; j<n; j++) if (board[i][j]=='*' && game[i][j]=='x') mine_touched = 1;
    
      if (mine_touched) { // A mine is touched.
        for (i=0; i<n; i++) { // Print the initial board game.
      	  printf("%s\n", board[i]);
	    }
	    printf("\n"); // Insert a newline.
	  }
	  else { // No mine is touched. 
	    // Mark the touched postions.
	    for (i=0; i<n; i++) 
          for (j=0; j<n; j++) {
      	    if (game[i][j]=='x') { // game[i][j] has been touched..
//printf("checked\n\n");
      	      game[i][j] = '0'; // Initial game[i][j] to 0.
      	      if (i-1>=0 && j-1>=0 && board[i-1][j-1]=='*') game[i][j]++; // upper-left cell.
      	      if (i-1>=0 &&           board[i-1][j]=='*')   game[i][j]++; // upper cell.
      	      if (i-1>=0 && j+1<n  && board[i-1][j+1]=='*') game[i][j]++; // upper-right cell.
      	      if (          j-1>=0 && board[i][j-1]=='*')   game[i][j]++; // left cell.
      	      if (          j+1<n  && board[i][j+1]=='*')   game[i][j]++; // right cell.
      	      if (i+1<n  && j-1>=0 && board[i+1][j-1]=='*') game[i][j]++; // lower-left cell.
      	      if (i+1<n            && board[i+1][j]=='*')   game[i][j]++; // lower cell.
      	      if (i+1<n  && j+1<n  && board[i+1][j+1]=='*') game[i][j]++; // lower-right cell.
	  	    }
          }
	  
        for (i=0; i<n; i++) { // Print the partial board game.
      	  printf("%s\n", game[i]);
	    }
	    printf("\n"); // Insert a newline.
	  }
    }
  }
  return 0;
}
