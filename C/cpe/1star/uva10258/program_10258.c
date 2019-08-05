// One-star problem
// Problem 10258 Contest Scoreboard
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
  int contestant, problem, time;
  char L;
  // Input "i, j, <time>, 'R'", "i, j, <time>, 'U'", and "i, j, <time>, 'E'" will be ignored.
  // Assume at most 100 contestant and at most 9 problems. (Index i and j are not 0.)
  // If incorrect[i][j]=k, it denotes conteatant i has incorrectly submitted the problem j k times,
  // but he/she has not submitted a correct answer for problem j yet, i.e., the number of times
  // "i, j, <time>, 'I'" have been input.
  int incorrect[101][10];
  // Assume at most 100 contestant (Index i is not 0.)
  // If score[i]=k>0, it denotes conteatant i has correctly submitted the problem j, i.e.,
  // "i j <time> 'C'" has been read from the input line.
  // The value score[i] adds <time> plus 20*incorrect[i][j], i.e., including peanlty.
  // If after "i j <time> 'C'" has been input, no line "i j <time> 'I'" shoud be submitted. 
  // Therefore, if contestant i submits incorrect answer for problem j, but he/she does not 
  // Submit a correct answer form problem j, the problem is not recorded to the score.
  int score[101]; 
  int correct[101]; // Number of correct answer contestant has submitted.
  int team[101]; // Tesm number, the team id is updated with swap operations.
  int cases; // Number of cases.
  // temporary score and correct problem count team number for swap operation.
  int temp_score, temp_correct, temp_team; 
  int i, j, k; // Loop variable.
  char c; // One character to test newline.
  
  // Clear the problem and score data.
  for (i=1; i<101; i++) {
    score[i] = 0;
    correct[i] = 0;
    team[i] = i;
    for (j=1; j<10; j++) incorrect[i][j] = 0;
  }
  
  scanf("%d\n\n", &cases); // Read the number of cases.
  for (k=0; k<cases; k++) {
  	while (scanf("%d %d %d %c", &contestant, &problem, &time, &L)==4) {
  	  if (L=='C') {// A correct answer has been submitted.
  	    score[contestant] += time + 20 * incorrect[contestant][problem];
  	    correct[contestant]++;
      }
  	  else if (L=='I') // An correct answer has been submitted.
		incorrect[contestant][problem]++; 
	  else ; // If L='R', 'U', or 'E', ignore the input.
	  
	  scanf("%c", &c);
	  if (feof(stdin)) {break;} // Reach end of file. The current case is done.
	  else if (c==0X0A) {// A newline is detected.
	    scanf("%c", &c);
	    if (feof(stdin)) {break;} // Reach end of file. The current case is done.
	    else if (c==0X0A) {break;} // An blank line is read and the current case is done.
	    else {ungetc(c, stdin);} // Put the character back to the input stream and continue.
      }
    }

    // Sort score and correct problem count both in the descending order.
    for (i=100; i>=2; i--)
      for (j=2; j<=100; j++) 
        if (correct[j-1]<correct[j] || (correct[j-1]==correct[j] && score[j-1]<score[j])) {
          temp_score = score[j-1];
          temp_correct = correct[j-1];
          temp_team = team[j-1];
          score[j-1] = score[j];
          correct[j-1] = correct[j];
          team[j-1] = team[j];
          score[j] = temp_score;
          correct[j] = temp_correct;
          team[j] = temp_team;
		}       
	// A case is done. Output the result of this case.
	for (i=1; i<=100; i++) 
	  if (correct[i]>0) printf("%d %d %d\n", team[i], correct[i], score[i]);
	  else break;
	printf("\n");
	  
    // Clear the problem and score data.
    for (i=1; i<101; i++) {
      score[i] = 0;
      correct[i] = 0;
      team[i] = i;
      for (j=1; j<10; j++) incorrect[i][j] = 0;
    }
  }
  return 0;
}
