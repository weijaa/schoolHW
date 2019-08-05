// One-star problem
// Problem 10415 Eb Alto Saxophone Player
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

/* We use an unsigned short integer to represent the fingers of a note. Let the least
   siginifcant bit, b_0, represent finger 1, and b_i represent finger i_1, for 0<=i<10.
   A bit has value 1 if a note uses that bit. For example, note 'c' uses fingers 2--4 
   and 7--10, its corresponding value will be 1111001110, hexadecimal value 0X3CE. We
   use two array low[7] and high[7] to store the fingers used for notes {'a', 'b', 'c',
   'd', 'e', 'f', 'g'} and {'A', 'B', 'C', 'E', 'E', 'F', 'G'}, respectively. 
*/
int main(void) {
  unsigned short low[7]  = {0X006, 0X002, 0X3CE, 0X1CE, 0X0CE, 0X04E, 0X00E}; // Low octave.
  unsigned short high[7] = {0X007, 0X003, 0X004, 0X1CF, 0X0CF, 0X04F, 0X00F}; // High octave.
  int finger[10]; // Moves of 10 fingers. The number of move for figner i is finger[i-1]. 
  int cases; // Number of cases.
  char music[201]; // Notes of a music, maximum 200 notes.
  unsigned short last_note, this_note, temp_note; // Single note for processing.
  int i, j, k; // Loop variable.
  
  scanf("%d", &cases); // Input the number of cases.
  
  for (i=0; i<cases; i++) { // Count finger moves of all musics.
    scanf("%s", music); // Input music notes of this case.
    for (j=0; j<10; j++) finger[j] = 0; // Clear the number of moves for all fingers.
    last_note = 0X000; // At the beginning no finger is pressed.
    for (j=0; j<strlen(music); j++) { // For all notes compute the finger moves.
      if (islower(music[j])) this_note = low[music[j]-'a']; // Get this note; low octave.
      else this_note = high[music[j]-'A']; // High octave.
      
      temp_note = this_note;
      for (k=0; k<10; k++) {
  	    if ((last_note&0X01)==0 && (this_note&0X01)==1) finger[k]++;
  	    last_note = last_note >> 1;
  	    this_note = this_note >> 1;
      }
      
      last_note =  temp_note; // Move to the next note; this note becomes last note. 
	}
	for (j=0; j<10; j++) printf("%d ", finger[j]); // Output the finger moves of all fingers.
	printf("\n"); // Output the newline.  	
  }
  return 0;
}
