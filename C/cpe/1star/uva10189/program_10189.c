// One-star problem
// Problem 10189 Minesweeper
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
  int M, N; // Size of the field.
  int index = 1; // Field index, initial value is 1.
  int i, j; // Loop variables.
  char field[100][100]; 
  while (scanf("%d %d", &M, &N)) { // Input M and N.
    if (M==0 && N==0) break; // Terminate the program when both M and N are 0. 
    
    for (i=0; i<M; i++) {
      scanf("%s", &field[i]); // Read the i-th of the field.
      for (j=0; j<N; j++) if (field[i][j]=='.') field[i][j] = '0'; // Initial the mine out of the black cell to 0.
	}
	
	// Count the mines arround field[i][j].
	for (i=0; i<M; i++) 
      for (j=0; j<N; j++) {
      	if (field[i][j]!='*') { // Cell field[i][j] is not a mine.
      	  if (i-1>=0 && j-1>=0 && field[i-1][j-1]=='*') field[i][j]++; // upper-left cell.
      	  if (i-1>=0 &&           field[i-1][j]=='*')   field[i][j]++; // upper cell.
      	  if (i-1>=0 && j+1<N  && field[i-1][j+1]=='*') field[i][j]++; // upper-right cell.
      	  if (          j-1>=0 && field[i][j-1]=='*')   field[i][j]++; // left cell.
      	  if (          j+1<N  && field[i][j+1]=='*')   field[i][j]++; // right cell.
      	  if (i+1<M  && j-1>=0 && field[i+1][j-1]=='*') field[i][j]++; // lower-left cell.
      	  if (i+1<M            && field[i+1][j]=='*')   field[i][j]++; // lower cell.
      	  if (i+1<M  && j+1<N  && field[i+1][j+1]=='*') field[i][j]++; // lower-right cell.
		}
      }
      
      printf("Field #%d:\n", index++); // Output the field index.
      for (i=0; i<M; i++) printf("%s\n", field[i]); // Output the field.
      printf("\n"); // Print a blank line.
	}
	return 0;
}
