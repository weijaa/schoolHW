// Two-star problem
// Problem 572 Oil Deposits
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

// Use digits and letters to mark plot, maximum 62 deposits.
// The purpose of different is for displaying the deposits mark, though it is
// not required in the problem.
void new_pocket(char *plot, char *deposit) {
  *plot = *deposit; // Mark the new pocket.
  if ((*deposit)<'9') (*deposit)++; // Set the next deposit mark as the next digit.
  else if ((*deposit)=='9') *deposit = 'A'; // Set the next deposit mark as letter 'A'.
  else if ((*deposit)<'Z') (*deposit)++; // Set the next deposit mark as the next letter.
  else if ((*deposit)=='Z') *deposit = 'a'; // Set the next deposit mark as letter 'a'.
  else (*deposit)++; // Set the next deposit mark as the next letter.
  
  if ((*deposit)=='z'+1) *deposit = '0'; // More than 62 deposits, start mark from '0' again.
}

/* Mark the neighbors as the same mark. Each plot has maximum eight neighbors.
   Neighborhood marking will propagate the mark to all possible neighbors recursively.
   grid: the pointer to the two-dimensional grid.
   m, n: number of rows and columns of the grid.
   i, j: row and column index of the plot.
   mark: mark of the pocket.
*/
void mark_neighbors(char grid[100][101], int m, int n, int i, int j, char mark) {
  if (i>0) { // Exclude the top row.
    if (j>0 && grid[i-1][j-1]=='@') {
	  grid[i-1][j-1] = mark; // upper-left plot
      mark_neighbors(grid, m, n, i-1, j-1, mark); // Propagate the mark to neighbors.
	} 
    if (grid[i-1][j]=='@') {
	  grid[i-1][j] = mark; // upper plot
      mark_neighbors(grid, m, n, i-1, j, mark); // Propagate the mark to neighbors.
	} 
    if (j<n-1 && grid[i-1][j+1]=='@') {
	  grid[i-1][j+1] = mark; // upper-right plot
      mark_neighbors(grid, m, n, i-1, j+1, mark); // Propagate the mark to neighbors.
	}
  }
  if (i<m-1) { // Exclude the bottom row.
    if (j>0 && grid[i+1][j-1]=='@') {
	  grid[i+1][j-1] = mark; // lower-left plot
      mark_neighbors(grid, m, n, i+1, j-1, mark); // Propagate the mark to neighbors.
	}
    if (grid[i+1][j]=='@') {
	  grid[i+1][j] = mark; // lower plot
      mark_neighbors(grid, m, n, i+1, j, mark); // Propagate the mark to neighbors.
	}
    if (j<n-1 && grid[i+1][j+1]=='@') {
	  grid[i+1][j+1] = mark; // lower-right plot
      mark_neighbors(grid, m, n, i+1, j+1, mark); // Propagate the mark to neighbors.
	}
  }
  if (j>0 && grid[i][j-1]=='@') {
	  grid[i][j-1] = mark; // left plot
      mark_neighbors(grid, m, n, i, j-1, mark); // Propagate the mark to neighbors.
	}
  if (j<n-1 && grid[i][j+1]=='@') {
	  grid[i][j+1] = mark; // right plot
      mark_neighbors(grid, m, n, i, j+1, mark); // Propagate the mark to neighbors.
	}
}

int main(void) {
  int m, n; // Input number of raws and columns.
  char grid[100][101]; // Grid pointer, two dimensional character array.
  char deposit; // Mark of oil deposits, '0'..'1', 'A'..'Z, 'a'..'z', maximum 62 marks.
  int count;
  int i, j, k; // Loop variables.
  
  while (1) { // Continue until the input raw is 0.
    scanf("%d %d", &m, &n); // Input the number of raws and columns.
    if (m==0) break; // If m is 0, stop the loop and terminate the program.
    
    for (i=0; i<m; i++) scanf("%s", &grid[i]); // Input all rows of the grid.

    deposit = '0'; // Initial deposit is 0.
    count = 0; // Initail count to 0;
    for (i=0; i<m; i++) // Scan all plots in the grid from left to right,
      for (j=0; j<n; j++) { // and then from top to bottom.
      	if (grid[i][j]=='@') { // The plot is a pocket.
      	  // Check all neighboring plots, if any is marked, copy the mark.
      	  if (i>0 && j>0 && grid[i-1][j-1]!='*' && grid[i-1][j-1]!='@') // check upper-left plot
		    grid[i][j] = grid[i-1][j-1]; // Mark same pocket as the upper-left plot.
      	  else if (i>0 && grid[i-1][j]!='*' && grid[i-1][j]!='@') // check upper plot
		    grid[i][j] = grid[i-1][j]; // Mark same pocket as the upper plot.
      	  else if (i>0 && j<n-1 && grid[i-1][j+1]!='*' && grid[i-1][j+1]!='@') // check upper right plot
		    grid[i][j] = grid[i-1][j+1]; // Mark same pocket as the upper right plot.
      	  else if (i<m-1 && j>0 && grid[i+1][j-1]!='*' && grid[i+1][j-1]!='@') // check lower-left plot
		    grid[i][j] = grid[i+1][j-1]; // Mark same pocket as the lower-left plot.
      	  else if (i<m-1 && grid[i+1][j]!='*' && grid[i+1][j]!='@') // check lower plot
		    grid[i][j] = grid[i+1][j]; // Mark same pocket as the upper plot.
      	  else if (i<m-1 && j<n-1 && grid[i+1][j+1]!='*' && grid[i+1][j+1]!='@') // check lower right plot
		    grid[i][j] = grid[i+1][j+1]; // Mark same pocket as the lower right plot.
      	  else if (j>0 && grid[i][j-1]!='*' && grid[i][j-1]!='@') // check left plot
		    grid[i][j] = grid[i][j-1]; // Mark same pocket as the left plot.
      	  else if (j<n-1 && grid[i][j+1]!='*' && grid[i][j+1]!='@') // check right plot
		    grid[i][j] = grid[i][j+1]; // Mark same pocket as the right plot.
		  else {
		    new_pocket(&grid[i][j], &deposit); // Mark a new pocket.
		    count++;
		  }
      	  mark_neighbors(grid, m, n, i, j, grid[i][j]); // Mark the neighbors.
        }
	  }

   /* // These printing statements are for the one who is interested
      // in viewing the deposit markings.
   printf("*** m=%d, n=%d\n", m, n);
   for (k=0; k<m; k++) printf("      %s\n", grid[k]);
   printf("\n");
   */
	
    // Output the deposit count.
    printf("%d\n", count);
  }
  return 0;
}
