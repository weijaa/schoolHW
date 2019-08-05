// One-star problem
// Problem UVA490 Rotating Sentences
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
  char sentence[100][101]; // Maximum 100 sentences and each sentence maixmum 100 characters.
  int length[100]; // To record the length of each sentence.
  int sentence_count; // The number of sentences.
  int length_max = 0; // The maximum length of all sentences.
  int newline; // To determine wheter to add a new line.
  int i, j, k;

  i = 0; // i is the sentence index.
  j = 0; // j is the character count of sentence i.
  while (!feof(stdin)) { // Read the text until end-of-file.
     sentence[i][j] = getc(stdin); // Get the next character, place it in the sentence buffer.
     if (sentence[i][j]!=0X0A && sentence[i][j]!=0X0D ) { // If it is neither carriage return nor line feed,
       j++; // Move to the next character position in the buffer.
     }
     else { // When a carriage return or a line feed, move to the next new line.
       if (j!=0) { // There are text in the line.
         length[i] = j; // Store the length of the line.
         if (length[i]>length_max) length_max = length[i]; // Update the maximum if necessary.
         i++; // Move to the next line.
         j = 0; // The new line has no text yet.
       }
     }
  }
  if (j>0) { // The text does not end with '0A' or '0D', count te final line in.
    length[i] = j-1; // Store the length of the final line.
    if (length[i]>length_max) length_max = length[i]; // Update the maximum if necessary.
    i++; // Add one more line.
  }
  sentence_count = i; // Total number of sentences are input.
  for (j=0; j<length_max; j++) { // After rotation, the output text has number of lines as the maximum sentence length.
   newline = 0;
   for (i=sentence_count-1; i>=0; i--) { // Sentences are printed from right to left.
      if (newline) break; // If a newline is added, stop the loop.
      if (length[i]>j) putc(sentence[i][j], stdout); // If the sentence has more unprinted character, outupt it.
      else {
      	newline = 1; // Assume a newline is inserted
      	for (k=i; k>=0; k--) if (length[k]>j) {newline = 0; break;} // Will output more text, no newline is added.
		if (newline) putc('\n', stdout); // If a newline is added, output "\n".
		else putc(' ', stdout); // otherwise, output a space.
	  }
    }
    if (!newline) putc('\n', stdout); // After the j-th character of all lines being output and no newline is ouput, outupt a newline.
  }
  return 0;
} 
