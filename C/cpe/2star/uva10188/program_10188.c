// Two-star problem
// Problem 10188 Automated Judge Script
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
#include <ctype.h>
#include <string.h>

// Input a line of characters until a new line.
void readln(char *line) {
  int i = 0; // Character counter.
  do {
  	line[i] = getchar(); // Input a character from stdin.
  } while (line[i++]!=0X0A); // Continue when the input character is not a new line.
  line[i-1] = '\0'; // Change the new line to end-of-string.
}

// Return 1 if n lines of strings in text1 and text2 are the same.
int all_line_identical(int n, char text1[99][121], char text2[99][121]) {
  int i; // Loop variable.
  
  // If there is one line not identical return flase.
  for (i=0; i<n; i++) if (strcmp(text1[i], text2[i])!=0) return 0;
  return 1; // All lines are the same, return 1.
}

int main(void) {
  int n, m; // Input integer, number of lines.
  // Standard solutions and team output maximum 99 lines and 120 characters each line.
  char standard_solution[99][121];
  char team_output[99][121];
  char temp; // Temporary character. To search new line.
  int run = 0; // Run index, initial is 0.
  // Judging result of the team output.
  int result; // 1: Accepted, 2: Presentation erro, 3: Wrong answer.
  // Number of characters in lines of standard solution and team output.
  int length1, length2; 
  int i, j, k; // Loop variables.
  
  while (1) { // Continue if input value of n is not 0.
    scanf("%d", &n); // Input integer n, the number of lines of standard solution.
    if (n==0) break; // No more lines, stop the loop and terminate the program.
     // Forward stdin pointer until reach a new line.
    do {
  	  temp = getchar();
    } while (temp!=0X0A);
    // Read n lines of standard solution.
    for (i=0; i<n; i++) readln(standard_solution[i]);
    
    scanf("%d", &m); // Input integer m, the number of lines of team output. 
    // Forward stdin pointer until reach a new line.
    do {
  	  temp = getchar();
    } while (temp!=0X0A);    
    for (i=0; i<m; i++) readln(team_output[i]); // Read m lines of team output.
    
  	if (n!=m) result = 3; // Unmatching number of lines. Wrong answer.
  	// The contents of standard solution and team output are the same. Accepted.
  	else if (all_line_identical(n, standard_solution, team_output)) result = 1;
  	else {
  	  result = 0; // Set result to 0, i.e, the result is not decided yet.
  	  
  	  // Remove white spaces in standard solution and team output.
  	  for (i=0; i<n && !result; i++) { // Check line i while result is not decided.
  	    length1 = strlen(standard_solution[i]); // String length of standard solution.
  	    length2 = strlen(team_output[i]); // String length of team output.
  	    // Remove white spaces of line i.
  	    k = 0;
  	    for (j=0; j<length1; j++) // Copy non-white characters.
  	      if (standard_solution[i][j]!=' ' && standard_solution[i][j]!='\t')
			standard_solution[i][k++] = standard_solution[i][j];
		standard_solution[i][k] = '\0'; // Add end-of-string.
		length1 = k;
  	    k = 0;
  	    for (j=0; j<length2; j++) // Copy non-white characters.
  	      if (team_output[i][j]!=' ' && team_output[i][j]!='\t')
			team_output[i][k++] = team_output[i][j];
		team_output[i][k] = '\0'; // Add end-of-string.
		length2 = k;
		// Unmatching non-white characters. Wrong Answer.
  	    if (length1!=length2) result = 3;
      }
      
      if (!result) { // If the result is undecided.
  	    // The standard solution and team output have identical non-white contents.
	    if (all_line_identical(n, standard_solution, team_output)) result = 2;
	  }
	  
	  // Scan and compare non-white characters of all line i while result is 
	  // not decided.
      for (i=0; i<n && !result; i++) 
  	    for (j=0; j<length1 && !result; j++) 
  	    	// If either one is a digit, but not matching. Worng answer.
  	        if ((isdigit(standard_solution[i][j]) || isdigit(team_output[i][j])) &&
			    (standard_solution[i][j]!=isdigit(team_output[i][j]))) result = 3;

	  if (!result) { // If the result is undecided.
	    // The unmatching content is at non-numeric characters. Presentation error.
	    result = 2;
      }
	}
	
	if (result==1) printf("Run #%d: Accepted\n", ++run);
	else if (result==2) printf("Run #%d: Presentation Error\n", ++run);
	else printf("Run #%d: Wrong Answer\n", ++run);
  }
  return 0;
}
